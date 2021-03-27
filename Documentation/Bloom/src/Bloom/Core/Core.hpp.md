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

An `assertion` statement specifies a condition that you expect to be true at a point in your program. If that condition is not true, the assertion fails, execution of your program is interrupted, and the Assertion Failed dialog box appears.

Also assertion statements compile only if `_DEBUG` is defined. Otherwise, the compiler treats assertions as null statements.

[Read more here](https://docs.microsoft.com/en-us/visualstudio/debugger/c-cpp-assertions?view=vs-2019)

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

---

<p align="center">
  BIND EVENT FUNCTION
</p>

Allow to bind an event as _callback_ for any type of function.

```cpp
#define BM_BIND_EVENT_FN(fn)																\
 [this](auto&&... args) -> decltype(auto) {									\
		return this->fn(std::forward<decltype(args)>(args)...); \
 }
```

---

<p align="center">
  SCOPE
</p>

_Actually need to study more to document this part._

[Future readings](https://stackoverflow.com/questions/8526598/how-does-stdforward-work)

```cpp
namespace Bloom {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args) {
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using Ref = std::shared_ptr<T>;

	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args) {
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}
```
