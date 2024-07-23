#pragma once
#include "framework.h"
#include "interface.h"
#include "GraphicsModule.h"

namespace g1 {
	class RenderManager : public IRenderManager
	{
	public:
		explicit RenderManager(const ComPtr<IFactory>& module);

		~RenderManager();

		ULONG AddRef() override;

		ULONG Release() override;

		HRESULT QueryInterface(/* [in] */ REFIID riid, /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		HRESULT Render(IRenderTarget* outputTarget) override;

		HRESULT SetScene(IScene* scene) override;

	private:
		std::atomic<LONG> m_refCount;
		ComPtr<IFactory> m_module;
		ComPtr<IScene> m_scene;

	};
}
