#pragma once

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#define NOMINMAX
// Windows 헤더 파일
#include <windows.h>
#include "interface.h"
#include "common.h"
#include <d3d11_4.h>
#include <dxgi1_6.h>
#include <atomic>
#include <DirectXMath.h>