#include "pch.h"
#include "WindowRenderTarget.h"

g1::WindowRenderTarget::WindowRenderTarget(g1::IFactory* factory, ComPtr<IDXGISwapChain1>&& swapChain)
    : m_refCount{ 1 }
    , m_module{ factory }
	, m_swapChain{ std::move(swapChain) } {
	ComPtr<ID3D11Device5> device;
	m_module.As(&device);
	m_swapChain->GetBuffer(0, __uuidof(m_backBuffer), &m_backBuffer);
	device->CreateRenderTargetView(m_backBuffer.Get(), nullptr, &m_rtv);
}

ULONG g1::WindowRenderTarget::AddRef()
{
    auto refCount = m_refCount.fetch_add(1, std::memory_order_release);
    return refCount + 1;
}

ULONG g1::WindowRenderTarget::Release()
{
    auto refCount = m_refCount.fetch_sub(1, std::memory_order_acquire);
    if (refCount == 1)
    {
        delete this;
    }

    return refCount - 1;
}

HRESULT g1::WindowRenderTarget::QueryInterface(REFIID riid, void** ppvObject)
{
	IUnknown* object = nullptr;
	if (riid == __uuidof(IUnknown))
	{
		object = this;
	}
	else if (riid == __uuidof(ID3D11Texture2D))
	{
		object = m_backBuffer.Get();
	}
	else if (riid == __uuidof(ID3D11RenderTargetView))
	{
		object = m_rtv.Get();
	}
	else
	{
		return E_NOINTERFACE;
	}

	object->AddRef();
	*ppvObject = object;
	return S_OK;
}

HRESULT g1::WindowRenderTarget::Resize(uint32_t width, uint32_t height)
{
	m_rtv.Reset();
	m_backBuffer.Reset();
	
	ComPtr<ID3D11Device5> device;
	m_module.As(&device);
	m_swapChain->ResizeBuffers(0, width, height, DXGI_FORMAT_UNKNOWN, 0);
	m_swapChain->GetBuffer(0, __uuidof(m_backBuffer), &m_backBuffer);
	device->CreateRenderTargetView(m_backBuffer.Get(), nullptr, &m_rtv);
	return S_OK;
}

HRESULT g1::WindowRenderTarget::Present()
{
	m_swapChain->Present(0, 0);
	return S_OK;
}
