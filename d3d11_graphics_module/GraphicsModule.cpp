#include "pch.h"
#include "WindowRenderTarget.h"
#include "GraphicsModule.h"
#include "RenderManager.h"
#include "Scene.h"
#include <DirectXMath.h>

HRESULT g1::CreateFactory(::IG1Factory** ppFactory) {
	try
	{
		*ppFactory = new Factory();
	}
	catch (HRESULT hr)
	{
		return hr;
	}

	return S_OK;
}


constexpr size_t MEMOEY_SIZE = ((sizeof(g1::ObjectTable) + 65535) / 65536) * 65536;
constexpr size_t MEMORY_PAGE_SIZE = 65536 * 4;
g1::Factory::Factory()
	: m_refCount{ 1 }
	, m_commitedState{ }
	, m_idleObjectNodeIndex{ }
{
	HRESULT hr;
	ComPtr<ID3D11Device> device;
	ComPtr<ID3D11DeviceContext> context;
	D3D_FEATURE_LEVEL featureLevel{};
	hr = CreateDXGIFactory2(0, __uuidof(IDXGIFactory5), &m_dxgiFactory);
	if (FAILED(hr))
		throw hr;

	hr = D3D11CreateDevice(nullptr, D3D_DRIVER_TYPE_HARDWARE, nullptr, D3D11_CREATE_DEVICE_BGRA_SUPPORT, nullptr, 0, D3D11_SDK_VERSION, &device, &featureLevel, &context);
	if (FAILED(hr))
		throw hr;

	device.As(&m_device);
	context.As(&m_context);

	m_ptrObjectTable = VirtualAlloc(nullptr, MEMOEY_SIZE, MEM_RESERVE, PAGE_READWRITE);
	if (m_ptrObjectTable == nullptr)
		throw E_OUTOFMEMORY;

	int numPageOfNode = ((sizeof(ObjectTable::node) + MEMORY_PAGE_SIZE - 1) / MEMORY_PAGE_SIZE);
	void* ret = VirtualAlloc(m_ptrObjectTable, MEMORY_PAGE_SIZE * numPageOfNode, MEM_COMMIT, PAGE_READWRITE);
	assert(ret != nullptr);
	memset(ret, 0xFF, sizeof(ObjectTable::node));
	for (int i = 0; i < numPageOfNode; ++i)
	{
		m_commitedState |= 1ull << (63 - i);
	}

	m_objectTable = (ObjectTable*)m_ptrObjectTable;
	for (size_t i = 0; i < MAX_NUM_OF_OBJECT; ++i)
	{
		m_objectTable->node[i] = i + 1;
	}

	m_objectTable->node[MAX_NUM_OF_OBJECT - 1] = MAX_NUM_OF_OBJECT;
}

g1::Factory::~Factory()
{
	VirtualFree(m_ptrObjectTable, 0, MEM_RELEASE);
}

auto g1::Factory::AddRef() -> ULONG
{
	LONG m = m_refCount.fetch_add(1, std::memory_order_release) + 1;
	return static_cast<ULONG>(m);
}

auto g1::Factory::Release() -> ULONG
{
	LONG m = m_refCount.fetch_sub(1, std::memory_order_acquire);
	if (m == 1)
	{
		delete this;
	}

	return static_cast<ULONG>(m - 1);
}

auto g1::Factory::QueryInterface(REFIID riid, void** ppvObject) -> HRESULT
{
	IUnknown* object = nullptr;
	if (riid == __uuidof(IUnknown))
	{
		object = this;
	}
	else if (riid == __uuidof(IFactory))
	{
		object = this;
	}
	else if (riid == __uuidof(ID3D11Device))
	{
		object = m_device.Get();
	}
	else if (riid == __uuidof(ID3D11Device5))
	{
		object = m_device.Get();
	}
	else if (riid == __uuidof(ID3D11DeviceContext))
	{
		object = m_context.Get();
	}
	else if (riid == __uuidof(ID3D11DeviceContext4))
	{
		object = m_context.Get();
	}
	else
	{
		return E_NOINTERFACE;
	}

	object->AddRef();
	*ppvObject = object;
	return S_OK;
}

HRESULT g1::Factory::CreateRenderTarget(HWND hWindow, UINT width, UINT height, IWindowRenderTarget** ppRenderTarget)
{
	DXGI_SWAP_CHAIN_DESC1 desc{};
	desc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
	desc.BufferCount = 2;
	desc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	desc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	desc.SampleDesc.Count = 1;
	desc.Scaling = DXGI_SCALING_STRETCH;
	desc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	desc.Width = width;
	desc.Height = height;

	ComPtr<IDXGISwapChain1> swapChain;
	HRESULT hr = m_dxgiFactory->CreateSwapChainForHwnd(m_device.Get(), hWindow, &desc, nullptr, nullptr, &swapChain);
	if (FAILED(hr))
	{
		return E_FAIL;
	}

	auto target = new(std::nothrow) WindowRenderTarget{ this, std::move(swapChain) };
	if (target == nullptr)
	{
		return E_OUTOFMEMORY;
	}

	*ppRenderTarget = target;
	return S_OK;
}

HRESULT g1::Factory::CreateRenderManager(IRenderManager** ppRenderMgr)
{
	auto mgr = new(std::nothrow) RenderManager{ this };
	if (mgr == nullptr)
	{
		return E_OUTOFMEMORY;
	}

	*ppRenderMgr = mgr;
	return S_OK;
}

HRESULT g1::Factory::CreateScene(IScene** ppObj)
{
	auto scene = new(std::nothrow) Scene{};
	if (scene == nullptr)
	{
		return E_OUTOFMEMORY;
	}

	*ppObj = scene;
	return S_OK;
}

HRESULT g1::Factory::CreateObject(IObject** ppObj)
{
	if (m_idleObjectNodeIndex == MAX_NUM_OF_OBJECT)
	{
		return E_OUTOFMEMORY;
	}

	const uint32_t nextNode = m_objectTable->node[m_idleObjectNodeIndex];
	const uint32_t index = m_idleObjectNodeIndex;
	m_idleObjectNodeIndex = nextNode;
	// 메모리가 커밋되었는지 확인한다.
	Object* obj = reinterpret_cast<Object*>(m_objectTable->object_array + index * sizeof(Object));
	size_t offset = index * sizeof(Object) + offsetof(ObjectTable, object_array);
	size_t pageIndex = offset / MEMORY_PAGE_SIZE;
	if ((m_commitedState & (1ull << (63 - pageIndex))) == 0)
	{
		// 커밋되어 있지 않으면 커밋한다.
		void* ret = VirtualAlloc((uint8_t*)m_ptrObjectTable + pageIndex * MEMORY_PAGE_SIZE, MEMORY_PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
		m_commitedState |= (1ull << (63 - pageIndex));
	}

	offset = index * sizeof(DirectX::XMFLOAT4X4) + offsetof(ObjectTable, transform);
	pageIndex = offset / MEMORY_PAGE_SIZE;
	if ((m_commitedState & (1ull << (63 - pageIndex))) == 0)
	{
		// 커밋되어 있지 않으면 커밋한다.
		void* ret = VirtualAlloc((uint8_t*)m_ptrObjectTable + pageIndex * MEMORY_PAGE_SIZE, MEMORY_PAGE_SIZE, MEM_COMMIT, PAGE_READWRITE);
		m_commitedState |= (1ull << (63 - pageIndex));
	}

	new(obj) Object(this, m_objectTable->transform + index);
	*ppObj = obj;
	return S_OK;
}

void g1::Factory::ReturnLoanObject(Object* pObj)
{
	size_t index = pObj - (Object*)m_objectTable->object_array;
	m_objectTable->node[index] = m_idleObjectNodeIndex;
	m_idleObjectNodeIndex = index;
}

HRESULT __stdcall g1::Factory::CreateMesh(const G1MeshDesc* desc, IG1Mesh** ppMesh)
{
	return E_NOTIMPL;
}
