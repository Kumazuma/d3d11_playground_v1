#pragma once
#include "framework.h"
#include "interface.h"
#include <vector>

namespace g1 {
	class Scene : public IScene
	{
	public:
		Scene();

		~Scene();

		HRESULT STDMETHODCALLTYPE QueryInterface(
			/* [in] */ REFIID riid,
			/* [iid_is][out] */ _COM_Outptr_ void __RPC_FAR* __RPC_FAR* ppvObject) override;

		ULONG STDMETHODCALLTYPE AddRef(void) override;

		ULONG STDMETHODCALLTYPE Release(void) override;

		HRESULT STDMETHODCALLTYPE AddObject(
			/* [in] */ IG1Object* pObj) override;

		HRESULT STDMETHODCALLTYPE RemoveObject(
			/* [in] */ IG1Object* pObj) override;

		UINT STDMETHODCALLTYPE GetNumOfObject(void) override;

		HRESULT STDMETHODCALLTYPE Get(
			/* [in] */ UINT index,
			/* [out] */ IG1Object** ppObj) override;

		UINT STDMETHODCALLTYPE GetAsArray(
			/* [in] */ UINT offset,
			/* [in] */ UINT count,
			/* [out][in] */ IG1Object** pArray) override;
		
	private:
		std::atomic<LONG> m_refCount;
		std::vector<IObject*> m_objectList;

	};
}
