

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0628 */
/* at Tue Jan 19 12:14:07 2038
 */
/* Compiler settings for graphics_module.idl:
    Oicf, W1, Zp8, env=Win64 (32b run), target_arch=ARM64 8.01.0628 
    protocol : all , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */



/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 500
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __graphics_module_interface_h__
#define __graphics_module_interface_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

#ifndef DECLSPEC_XFGVIRT
#if defined(_CONTROL_FLOW_GUARD_XFG)
#define DECLSPEC_XFGVIRT(base, func) __declspec(xfg_virtual(base, func))
#else
#define DECLSPEC_XFGVIRT(base, func)
#endif
#endif

/* Forward Declarations */ 

#ifndef __IG1RenderTarget_FWD_DEFINED__
#define __IG1RenderTarget_FWD_DEFINED__
typedef interface IG1RenderTarget IG1RenderTarget;

#endif 	/* __IG1RenderTarget_FWD_DEFINED__ */


#ifndef __IG1WindowRenderTarget_FWD_DEFINED__
#define __IG1WindowRenderTarget_FWD_DEFINED__
typedef interface IG1WindowRenderTarget IG1WindowRenderTarget;

#endif 	/* __IG1WindowRenderTarget_FWD_DEFINED__ */


#ifndef __IG1Mesh_FWD_DEFINED__
#define __IG1Mesh_FWD_DEFINED__
typedef interface IG1Mesh IG1Mesh;

#endif 	/* __IG1Mesh_FWD_DEFINED__ */


#ifndef __IG1Object_FWD_DEFINED__
#define __IG1Object_FWD_DEFINED__
typedef interface IG1Object IG1Object;

#endif 	/* __IG1Object_FWD_DEFINED__ */


#ifndef __IG1Scene_FWD_DEFINED__
#define __IG1Scene_FWD_DEFINED__
typedef interface IG1Scene IG1Scene;

#endif 	/* __IG1Scene_FWD_DEFINED__ */


#ifndef __IG1RenderManager_FWD_DEFINED__
#define __IG1RenderManager_FWD_DEFINED__
typedef interface IG1RenderManager IG1RenderManager;

#endif 	/* __IG1RenderManager_FWD_DEFINED__ */


#ifndef __IG1Factory_FWD_DEFINED__
#define __IG1Factory_FWD_DEFINED__
typedef interface IG1Factory IG1Factory;

#endif 	/* __IG1Factory_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_graphics_module_0000_0000 */
/* [local] */ 

typedef struct G1Matrix
    {
    float c11;
    float c12;
    float c13;
    float c14;
    float c21;
    float c22;
    float c23;
    float c24;
    float c31;
    float c32;
    float c33;
    float c34;
    float c41;
    float c42;
    float c43;
    float c44;
    } 	G1Matrix;

typedef struct G1MeshDesc
    {
    void *vertices;
    UINT numOfVertices;
    void *indices;
    UINT numOfIndices;
    void *texCoords;
    void *normals;
    void *boneWeights;
    void *boneIndices;
    } 	G1MeshDesc;



extern RPC_IF_HANDLE __MIDL_itf_graphics_module_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_graphics_module_0000_0000_v0_0_s_ifspec;

#ifndef __IG1RenderTarget_INTERFACE_DEFINED__
#define __IG1RenderTarget_INTERFACE_DEFINED__

/* interface IG1RenderTarget */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1RenderTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0D1C1A03-E59C-4ECA-B3A6-57CC13200EA1")
    IG1RenderTarget : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IG1RenderTargetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1RenderTarget * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1RenderTarget * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1RenderTarget * This);
        
        END_INTERFACE
    } IG1RenderTargetVtbl;

    interface IG1RenderTarget
    {
        CONST_VTBL struct IG1RenderTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1RenderTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1RenderTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1RenderTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1RenderTarget_INTERFACE_DEFINED__ */


#ifndef __IG1WindowRenderTarget_INTERFACE_DEFINED__
#define __IG1WindowRenderTarget_INTERFACE_DEFINED__

/* interface IG1WindowRenderTarget */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1WindowRenderTarget;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B389A412-C974-4FFE-BBA3-A80E0C0D5F3B")
    IG1WindowRenderTarget : public IG1RenderTarget
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Resize( 
            /* [in] */ UINT width,
            /* [in] */ UINT height) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Present( void) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IG1WindowRenderTargetVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1WindowRenderTarget * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1WindowRenderTarget * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1WindowRenderTarget * This);
        
        DECLSPEC_XFGVIRT(IG1WindowRenderTarget, Resize)
        HRESULT ( STDMETHODCALLTYPE *Resize )( 
            IG1WindowRenderTarget * This,
            /* [in] */ UINT width,
            /* [in] */ UINT height);
        
        DECLSPEC_XFGVIRT(IG1WindowRenderTarget, Present)
        HRESULT ( STDMETHODCALLTYPE *Present )( 
            IG1WindowRenderTarget * This);
        
        END_INTERFACE
    } IG1WindowRenderTargetVtbl;

    interface IG1WindowRenderTarget
    {
        CONST_VTBL struct IG1WindowRenderTargetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1WindowRenderTarget_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1WindowRenderTarget_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1WindowRenderTarget_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 



#define IG1WindowRenderTarget_Resize(This,width,height)	\
    ( (This)->lpVtbl -> Resize(This,width,height) ) 

#define IG1WindowRenderTarget_Present(This)	\
    ( (This)->lpVtbl -> Present(This) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1WindowRenderTarget_INTERFACE_DEFINED__ */


#ifndef __IG1Mesh_INTERFACE_DEFINED__
#define __IG1Mesh_INTERFACE_DEFINED__

/* interface IG1Mesh */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1Mesh;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4B312B9-8CC2-46C0-881B-05ECCD9F6740")
    IG1Mesh : public IUnknown
    {
    public:
    };
    
    
#else 	/* C style interface */

    typedef struct IG1MeshVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1Mesh * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1Mesh * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1Mesh * This);
        
        END_INTERFACE
    } IG1MeshVtbl;

    interface IG1Mesh
    {
        CONST_VTBL struct IG1MeshVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1Mesh_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1Mesh_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1Mesh_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1Mesh_INTERFACE_DEFINED__ */


#ifndef __IG1Object_INTERFACE_DEFINED__
#define __IG1Object_INTERFACE_DEFINED__

/* interface IG1Object */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1Object;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD6FE070-7B6D-4A62-AC52-5244E1AFCFEB")
    IG1Object : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetTransform( 
            /* [in] */ const G1Matrix *pMatrix) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTransform( 
            /* [out][in] */ G1Matrix *pMatrix) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMesh( 
            /* [in] */ IG1Mesh *pMesh) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IG1ObjectVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1Object * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1Object * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1Object * This);
        
        DECLSPEC_XFGVIRT(IG1Object, SetTransform)
        HRESULT ( STDMETHODCALLTYPE *SetTransform )( 
            IG1Object * This,
            /* [in] */ const G1Matrix *pMatrix);
        
        DECLSPEC_XFGVIRT(IG1Object, GetTransform)
        HRESULT ( STDMETHODCALLTYPE *GetTransform )( 
            IG1Object * This,
            /* [out][in] */ G1Matrix *pMatrix);
        
        DECLSPEC_XFGVIRT(IG1Object, SetMesh)
        HRESULT ( STDMETHODCALLTYPE *SetMesh )( 
            IG1Object * This,
            /* [in] */ IG1Mesh *pMesh);
        
        END_INTERFACE
    } IG1ObjectVtbl;

    interface IG1Object
    {
        CONST_VTBL struct IG1ObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1Object_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1Object_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1Object_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IG1Object_SetTransform(This,pMatrix)	\
    ( (This)->lpVtbl -> SetTransform(This,pMatrix) ) 

#define IG1Object_GetTransform(This,pMatrix)	\
    ( (This)->lpVtbl -> GetTransform(This,pMatrix) ) 

#define IG1Object_SetMesh(This,pMesh)	\
    ( (This)->lpVtbl -> SetMesh(This,pMesh) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1Object_INTERFACE_DEFINED__ */


#ifndef __IG1Scene_INTERFACE_DEFINED__
#define __IG1Scene_INTERFACE_DEFINED__

/* interface IG1Scene */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1Scene;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B906D84B-B120-40FF-BBD5-E474944A9DF7")
    IG1Scene : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddObject( 
            /* [in] */ IG1Object *pObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveObject( 
            /* [in] */ IG1Object *pObj) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetNumOfObject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Get( 
            /* [in] */ UINT index,
            /* [out] */ IG1Object **ppObj) = 0;
        
        virtual UINT STDMETHODCALLTYPE GetAsArray( 
            /* [in] */ UINT offset,
            /* [in] */ UINT count,
            /* [out][in] */ IG1Object **pArray) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IG1SceneVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1Scene * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1Scene * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1Scene * This);
        
        DECLSPEC_XFGVIRT(IG1Scene, AddObject)
        HRESULT ( STDMETHODCALLTYPE *AddObject )( 
            IG1Scene * This,
            /* [in] */ IG1Object *pObj);
        
        DECLSPEC_XFGVIRT(IG1Scene, RemoveObject)
        HRESULT ( STDMETHODCALLTYPE *RemoveObject )( 
            IG1Scene * This,
            /* [in] */ IG1Object *pObj);
        
        DECLSPEC_XFGVIRT(IG1Scene, GetNumOfObject)
        UINT ( STDMETHODCALLTYPE *GetNumOfObject )( 
            IG1Scene * This);
        
        DECLSPEC_XFGVIRT(IG1Scene, Get)
        HRESULT ( STDMETHODCALLTYPE *Get )( 
            IG1Scene * This,
            /* [in] */ UINT index,
            /* [out] */ IG1Object **ppObj);
        
        DECLSPEC_XFGVIRT(IG1Scene, GetAsArray)
        UINT ( STDMETHODCALLTYPE *GetAsArray )( 
            IG1Scene * This,
            /* [in] */ UINT offset,
            /* [in] */ UINT count,
            /* [out][in] */ IG1Object **pArray);
        
        END_INTERFACE
    } IG1SceneVtbl;

    interface IG1Scene
    {
        CONST_VTBL struct IG1SceneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1Scene_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1Scene_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1Scene_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IG1Scene_AddObject(This,pObj)	\
    ( (This)->lpVtbl -> AddObject(This,pObj) ) 

#define IG1Scene_RemoveObject(This,pObj)	\
    ( (This)->lpVtbl -> RemoveObject(This,pObj) ) 

#define IG1Scene_GetNumOfObject(This)	\
    ( (This)->lpVtbl -> GetNumOfObject(This) ) 

#define IG1Scene_Get(This,index,ppObj)	\
    ( (This)->lpVtbl -> Get(This,index,ppObj) ) 

#define IG1Scene_GetAsArray(This,offset,count,pArray)	\
    ( (This)->lpVtbl -> GetAsArray(This,offset,count,pArray) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1Scene_INTERFACE_DEFINED__ */


#ifndef __IG1RenderManager_INTERFACE_DEFINED__
#define __IG1RenderManager_INTERFACE_DEFINED__

/* interface IG1RenderManager */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1RenderManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0E6F4E9C-C67D-4A94-891A-481AF53E614F")
    IG1RenderManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Render( 
            /* [in] */ IG1RenderTarget *outputTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetScene( 
            /* [in] */ IG1Scene *scene) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IG1RenderManagerVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1RenderManager * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1RenderManager * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1RenderManager * This);
        
        DECLSPEC_XFGVIRT(IG1RenderManager, Render)
        HRESULT ( STDMETHODCALLTYPE *Render )( 
            IG1RenderManager * This,
            /* [in] */ IG1RenderTarget *outputTarget);
        
        DECLSPEC_XFGVIRT(IG1RenderManager, SetScene)
        HRESULT ( STDMETHODCALLTYPE *SetScene )( 
            IG1RenderManager * This,
            /* [in] */ IG1Scene *scene);
        
        END_INTERFACE
    } IG1RenderManagerVtbl;

    interface IG1RenderManager
    {
        CONST_VTBL struct IG1RenderManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1RenderManager_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1RenderManager_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1RenderManager_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IG1RenderManager_Render(This,outputTarget)	\
    ( (This)->lpVtbl -> Render(This,outputTarget) ) 

#define IG1RenderManager_SetScene(This,scene)	\
    ( (This)->lpVtbl -> SetScene(This,scene) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1RenderManager_INTERFACE_DEFINED__ */


#ifndef __IG1Factory_INTERFACE_DEFINED__
#define __IG1Factory_INTERFACE_DEFINED__

/* interface IG1Factory */
/* [uuid][local][object] */ 


EXTERN_C const IID IID_IG1Factory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F40915A4-1726-41AA-B916-2EE40F5F0F24")
    IG1Factory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateRenderTarget( 
            /* [in] */ HWND hWindow,
            /* [in] */ UINT width,
            /* [in] */ UINT height,
            /* [out] */ IG1WindowRenderTarget **ppRenderTarget) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRenderManager( 
            /* [out] */ IG1RenderManager **ppRenderMgr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateScene( 
            /* [out] */ IG1Scene **ppScene) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [out] */ IG1Object **ppObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateMesh( 
            /* [in] */ const G1MeshDesc *desc,
            /* [out] */ IG1Mesh **ppMesh) = 0;
        
    };
    
    
#else 	/* C style interface */

    typedef struct IG1FactoryVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IG1Factory * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IG1Factory * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IG1Factory * This);
        
        DECLSPEC_XFGVIRT(IG1Factory, CreateRenderTarget)
        HRESULT ( STDMETHODCALLTYPE *CreateRenderTarget )( 
            IG1Factory * This,
            /* [in] */ HWND hWindow,
            /* [in] */ UINT width,
            /* [in] */ UINT height,
            /* [out] */ IG1WindowRenderTarget **ppRenderTarget);
        
        DECLSPEC_XFGVIRT(IG1Factory, CreateRenderManager)
        HRESULT ( STDMETHODCALLTYPE *CreateRenderManager )( 
            IG1Factory * This,
            /* [out] */ IG1RenderManager **ppRenderMgr);
        
        DECLSPEC_XFGVIRT(IG1Factory, CreateScene)
        HRESULT ( STDMETHODCALLTYPE *CreateScene )( 
            IG1Factory * This,
            /* [out] */ IG1Scene **ppScene);
        
        DECLSPEC_XFGVIRT(IG1Factory, CreateObject)
        HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            IG1Factory * This,
            /* [out] */ IG1Object **ppObj);
        
        DECLSPEC_XFGVIRT(IG1Factory, CreateMesh)
        HRESULT ( STDMETHODCALLTYPE *CreateMesh )( 
            IG1Factory * This,
            /* [in] */ const G1MeshDesc *desc,
            /* [out] */ IG1Mesh **ppMesh);
        
        END_INTERFACE
    } IG1FactoryVtbl;

    interface IG1Factory
    {
        CONST_VTBL struct IG1FactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IG1Factory_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define IG1Factory_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define IG1Factory_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define IG1Factory_CreateRenderTarget(This,hWindow,width,height,ppRenderTarget)	\
    ( (This)->lpVtbl -> CreateRenderTarget(This,hWindow,width,height,ppRenderTarget) ) 

#define IG1Factory_CreateRenderManager(This,ppRenderMgr)	\
    ( (This)->lpVtbl -> CreateRenderManager(This,ppRenderMgr) ) 

#define IG1Factory_CreateScene(This,ppScene)	\
    ( (This)->lpVtbl -> CreateScene(This,ppScene) ) 

#define IG1Factory_CreateObject(This,ppObj)	\
    ( (This)->lpVtbl -> CreateObject(This,ppObj) ) 

#define IG1Factory_CreateMesh(This,desc,ppMesh)	\
    ( (This)->lpVtbl -> CreateMesh(This,desc,ppMesh) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IG1Factory_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


