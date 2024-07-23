#include "pch.h"
#include "RenderManager.h"
#include "WindowRenderTarget.h"

g1::RenderManager::RenderManager(const ComPtr<IFactory>& module)
	: m_module{ module }
	, m_refCount{ 1 }
{
}

g1::RenderManager::~RenderManager()
{
}

ULONG g1::RenderManager::AddRef()
{
	auto refCount = m_refCount.fetch_add(1, std::memory_order_release);
	if (refCount <= 0)
	{
		char msg[80];
		wsprintfA(msg, "Invalid ref counting(%p)", this);
		OutputDebugStringA(msg);
	}

	return refCount + 1;
}

ULONG g1::RenderManager::Release()
{
	auto refCount = m_refCount.fetch_sub(1, std::memory_order_acquire);
	if (refCount == 1)
	{
		delete this;
	}

	return 0;
}

HRESULT g1::RenderManager::QueryInterface(REFIID riid, void** ppvObject)
{
	return E_NOTIMPL;
}

HRESULT g1::RenderManager::Render(IRenderTarget* outputTarget)
{
	// auto* renderTaget = (impl::WindowRenderTarget*)outputTarget;
	ComPtr<ID3D11DeviceContext4> context;
	ComPtr<ID3D11RenderTargetView> rtv;
	m_module.As(&context);
	outputTarget->QueryInterface(__uuidof(rtv), &rtv);
	float rgba[4]{0.5f, 1.f, 1.f, 1.f};
	context->ClearRenderTargetView(rtv.Get(), rgba);
	
	context->ClearState();
	return S_OK;
}

HRESULT g1::RenderManager::SetScene(IScene* scene)
{
	return E_NOTIMPL;
}
