#pragma once
#include "framework.h"
#include "interface.h"

namespace g1 {
	class Factory;
	class Object : public IObject
	{
	public:
		explicit Object(Factory* factory, DirectX::XMFLOAT4X4* transform);
		~Object() = default;

		HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		ULONG STDMETHODCALLTYPE AddRef(void) override;

		ULONG STDMETHODCALLTYPE Release(void) override;

		HRESULT STDMETHODCALLTYPE SetTransform(
			/* [in] */ const G1Matrix* pMatrix) override;

		HRESULT STDMETHODCALLTYPE GetTransform(
			/* [out][in] */ G1Matrix* pMatrix) override;

		HRESULT STDMETHODCALLTYPE SetMesh(
			/* [in] */ IG1Mesh* pMesh) override;
	private:
		std::atomic<LONG> m_refCount;
		ComPtr<Factory> m_factory;
		DirectX::XMFLOAT4X4* m_transform;
	};
}
