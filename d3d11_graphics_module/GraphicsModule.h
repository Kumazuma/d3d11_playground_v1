#pragma once
#include "framework.h"
#include "Object.h"
#include <DirectXMath.h>

namespace g1 {
	inline constexpr size_t MAX_NUM_OF_OBJECT = 65536 * 4;
	struct ObjectTable
	{
		uint32_t node[MAX_NUM_OF_OBJECT];
		uint8_t object_array[sizeof(Object) * MAX_NUM_OF_OBJECT];
		DirectX::XMFLOAT4X4 transform[MAX_NUM_OF_OBJECT];
	};

	class Factory : public IG1Factory
	{
	public:
		Factory();
		
		~Factory();
		
		ULONG AddRef() override;
		
		ULONG Release() override;

		HRESULT QueryInterface(/* [in] */ REFIID riid, /* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		HRESULT CreateRenderTarget(HWND hWindow, UINT width, UINT height, IWindowRenderTarget** ppRenderTarget) override;
		
		HRESULT CreateRenderManager(IRenderManager** ppRenderMgr) override;
		
		HRESULT CreateScene(IScene** ppObj) override;
		
		HRESULT CreateObject(IObject** ppObj) override;
		
		void ReturnLoanObject(Object* pObj);

		HRESULT STDMETHODCALLTYPE CreateMesh(
			/* [in] */ const G1MeshDesc* desc,
			/* [out] */ IG1Mesh** ppMesh) override;
	private:
		std::atomic<LONG> m_refCount;
		ComPtr<ID3D11Device5> m_device;
		ComPtr<ID3D11DeviceContext4> m_context;
		ComPtr<IDXGIFactory5> m_dxgiFactory;
		uint64_t m_commitedState;
		void* m_ptrObjectTable;
		ObjectTable* m_objectTable;
		uint32_t m_idleObjectNodeIndex;
	};
}
