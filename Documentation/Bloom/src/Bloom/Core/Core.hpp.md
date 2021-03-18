# <h1 align="center"> Core header </h1>

## Description

The `Core.hpp` header contains most of the base macros that will be used within the Bloom engine.

## Code

---

<p align="center">
  <b>BM_(PLATFORM_WINDOWS, BUILD_DLL) and BLOOM_API</b>
</p>

```cpp
#ifdef BM_PLATFORM_WINDOWS
	#if BM_BUILD_DLL
		#define BLOOM_API __declspec(dllexport)
	#else
		#define BLOOM_API __declspec(dllimport)
	#endif // BM_BUILD_DLL

#else
	#error Bloom only support Windows! (for now)
#endif // BM_PLATFORM_WINDOWS
```

This code snippet checks whether `BM_PLATFORM_WINDOWS` is included in the preprocessor¹ or not. If so, the next step is to check if `BM_BUILD_DLL` is also there, in case it's the `BLOOM_API` macro will be set to `__declspec (dllexport)` since the Bloom solution (the engine) will generate a `dynamic library (.dll)` and not an `executable (.exe)`, so the functions will have to be explicitly imported or exported from the dll.

In other words, as the Bloom solution has `BM_BUILD_DLL` in its preprocessor¹ means that its functions will have to be set in `export` mode. If the solution will generate a `.dll` define the macro that when add to a class will `export` them, otherwise set to `import`.

¹(setted by the premake5.lua. If you are not aware on how premake5 works, check out the docs [here](LINK_TO_PREMAKE5_DOCS))

---

<p align="center">
  BIT
</p>

```cpp
#define BIT(x) (1 << x)
```

It's simply a bitwise left shift operator that will be used on `events enum`.

---

<p align="center">
  ASSERT
</p>

```cpp
#ifdef BM_ENABLE_ASSERTS
	#define BM_ASSERT(x, ...) {\
		if(!(x)) {\
			BM_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak(); \
		} \
  }

	#define BM_CORE_ASSERT(x, ...) {\
		if(!(x)) {\
			BM_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); \
			__debugbreak(); \
		} \
  }
#else
	#define BM_ASSERT(x, ...)
	#define BM_CORE_ASSERT(x, ...)
#endif
```
