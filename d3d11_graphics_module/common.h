#pragma once
#include <wrl.h>
namespace g1 {
	template<typename T>
	using ComPtr = Microsoft::WRL::ComPtr<T>;
}