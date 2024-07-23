#include "pch.h"
#include "Object.h"
#include "GraphicsModule.h"

g1::Object::Object(Factory* factory, DirectX::XMFLOAT4X4* transform)
    : m_factory{ factory }
    , m_refCount{ 1 }
    , m_transform{ transform }
{
}

HRESULT __stdcall g1::Object::QueryInterface(REFIID riid, void** ppvObject)
{
    return E_NOTIMPL;
}

ULONG __stdcall g1::Object::AddRef(void)
{
    return m_refCount.fetch_add(1, std::memory_order_release) + 1;
}

ULONG __stdcall g1::Object::Release(void)
{

    LONG refCount = m_refCount.fetch_sub(1, std::memory_order_acquire);
    if (refCount == 1)
    {
        auto factory = m_factory;
        this->~Object();
        factory->ReturnLoanObject(this);
    }

    return refCount - 1;
}

HRESULT __stdcall g1::Object::SetTransform(const G1Matrix* pMatrix)
{
    memcpy(m_transform, pMatrix, sizeof(*m_transform));
    return S_OK;
}

HRESULT __stdcall g1::Object::GetTransform(G1Matrix* pMatrix)
{
    memcpy(pMatrix, m_transform, sizeof(G1Matrix));
    return E_NOTIMPL;
}

HRESULT __stdcall g1::Object::SetMesh(IG1Mesh* pMesh)
{
    return E_NOTIMPL;
}
