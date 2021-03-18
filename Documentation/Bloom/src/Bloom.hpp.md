# <h1 align="center"> Bloom outside access header </h1>

## Description

The need to create the `Bloom.hpp` file comes from the fact that other solutions outside the Bloom engine need to access its functions. For that purpose, everything that may be needed is grouped and exported in a single file.

For example, in the `Sandbox` solution, which is a class inherited from `Bloom::Application`, obviously will have to have access to the application that is inside the Bloom engine, so it should import as follows.

```cpp
#include <Bloom.hpp>

class Sandbox : public Bloom::Application {
  ...
}
```

It'll only have access to the application class because in `Bloom.hpp` we have:

```cpp
#pragma once

#include "Bloom/Core/Application.hpp"
```

## A Plus

And if you're wondering what `#pragma once` would be

The use of `#pragma once` can reduce build times, as the compiler won't open and read the file again after the first `#include` of the file in the translation unit.

It's called the multiple-include optimization. It has an effect similar to the include guard idiom, which uses preprocessor macro definitions to prevent multiple inclusions of the contents of the file. It also helps to prevent violations of the one definition rule: the requirement that all templates, types, functions, and objects have no more than one definition in your code.

[Read more here](https://docs.microsoft.com/en-us/cpp/preprocessor/once?view=msvc-160)
