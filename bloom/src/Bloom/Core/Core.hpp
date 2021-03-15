#pragma once

/*
	If the project is including
	BM_BUILD_DLL on it's preprocessor
	the declspec of BLOOM_API will be set to
	export.
*/ 

#ifdef BM_PLATFORM_WINDOWS
	#if BM_BUILD_DLL
		#define BLOOM_API __declspec(dllexport)
	#else
		#define BLOOM_API __declspec(dllimport)
	#endif // BM_BUILD_DLL

#else
	#error Bloom only support Windows! (for now)
#endif // BM_PLATFORM_WINDOWS

#define BIT(x) (1 << x)