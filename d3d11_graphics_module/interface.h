#pragma once
#include <cstdint>
#include <windows.h>
#include <combaseapi.h>
#include "graphics_module_interface.h"

#ifdef D3D11GRAPHICSMODULE_EXPORTS
#define D3D11_GRAPHICS_MODULE_API __declspec(dllexport)
#else
#define D3D11_GRAPHICS_MODULE_API __declspec(dllimport)
#endif

namespace g1 {
	using IObject = ::IG1Object;
	using IScene = ::IG1Scene;
	using IRenderTarget = ::IG1RenderTarget;
	using IWindowRenderTarget = ::IG1WindowRenderTarget;
	using IRenderManager = IG1RenderManager;
	using IFactory = IG1Factory;
	HRESULT D3D11_GRAPHICS_MODULE_API CreateFactory(::IG1Factory** ppFactory);
}
