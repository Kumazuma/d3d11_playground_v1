#include "pch.h"
#include "Scene.h"

g1::Scene::Scene()
: m_refCount{ 1 }
{
}

g1::Scene::~Scene()
{
	for (auto& it : m_objectList)
	{
		it->Release();
	}
}

HRESULT __stdcall g1::Scene::QueryInterface(REFIID riid, void** ppvObject)
{
	return E_NOTIMPL;
}

ULONG __stdcall g1::Scene::AddRef(void)
{
	LONG refCount = m_refCount.fetch_add(1, std::memory_order_release);
	return refCount + 1;
}

ULONG __stdcall g1::Scene::Release(void)
{
	LONG refCount = m_refCount.fetch_sub(1, std::memory_order_acquire);
	if (refCount == 1)
	{
		delete this;
	}

	return refCount - 1;
}

HRESULT __stdcall g1::Scene::AddObject(IG1Object* pObj)
{
	m_objectList.push_back(pObj);
	pObj->AddRef();
	return S_OK;
}

HRESULT __stdcall g1::Scene::RemoveObject(IG1Object* pObj)
{
	auto it = m_objectList.begin();
	while (it != m_objectList.end())
	{
		if (*it == pObj)
		{
			it = m_objectList.erase(it);
			pObj->Release();
		}
		else
		{
			++it;
		}
	}

	return S_OK;
}

UINT __stdcall g1::Scene::GetNumOfObject(void)
{
	return (UINT)m_objectList.size();
}

HRESULT __stdcall g1::Scene::Get(UINT index, IG1Object** ppObj)
{
	if (index < m_objectList.size())
	{
		auto* pObj = m_objectList[index];
		*ppObj = pObj;
		pObj->AddRef();
		return S_OK;
	}

	return E_INVALIDARG;
}

UINT __stdcall g1::Scene::GetAsArray(UINT offset, UINT count, IG1Object** pArray)
{
	UINT len = std::min((UINT)m_objectList.size() - offset, count);
	if (len > m_objectList.size())
		return 0;

	auto it = m_objectList.begin() + offset;
	const auto end = it + len;
	volatile auto pOrigin = pArray;
	for (; it != end; ++it)
	{
		*pArray = *it;
		(*it)->AddRef();
		++pArray;
	}

	return len;
}
