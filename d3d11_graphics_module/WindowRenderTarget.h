#pragma once
#include <cstdint>
#include "interface.h"
#include "framework.h"

namespace g1 {
	class WindowRenderTarget: public IWindowRenderTarget
	{
	public:
		WindowRenderTarget(IFactory* module, ComPtr<IDXGISwapChain1>&& swapChain);

		~WindowRenderTarget() = default;

		ULONG AddRef() override;

		ULONG Release() override;

		HRESULT QueryInterface(/* [in] */ REFIID riid, /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		HRESULT Resize(uint32_t width, uint32_t height) override;
		
		HRESULT Present() override;

	private:
		std::atomic<LONG> m_refCount;
		ComPtr<IFactory> m_module;
		ComPtr<IDXGISwapChain1> m_swapChain;
		ComPtr<ID3D11Texture2D> m_backBuffer;
		ComPtr<ID3D11RenderTargetView> m_rtv;
	};
}
