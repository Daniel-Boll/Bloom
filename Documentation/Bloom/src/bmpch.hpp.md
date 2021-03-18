# <h1 align="center"> Precompiled header file </h1>

## Name

> bmpch

where

- bm
  - Bloom abbreviation
- pch
  - Precompiled header abbreviation

## Description

In the C and C++ programming languages, a header file is a file whose text may be automatically included in another source file by the C preprocessor by the use of a preprocessor directive in the source file.

Header files can sometimes contain very large amounts of source code (for instance, the header files `windows.h` and `Cocoa/Cocoa.h` on Microsoft Windows and OS X, respectively). This is especially true with the advent of large "header" libraries that make extensive use of templates, like the Eigen math library and Boost C++ libraries. They are written almost entirely as header files that the user `#includes`, rather than being linked at runtime. Thus, each time the user compiles their program, the user is essentially recompiling numerous header libraries as well. (These would be precompiled into shared objects or dynamic link libraries in non "header" libraries.)

To reduce compilation times, some compilers allow header files to be compiled into a form that is faster for the compiler to process. This intermediate form is known as a precompiled header, and is commonly held in a file named with the extension .pch or similar, such as `.gch` under the GNU Compiler Collection.

[Read more here](https://en.wikipedia.org/wiki/Precompiled_header)

## Usage

Every common library among multiple `.cpp` files will be put on the `bmpch.hpp` and then when needed the file will include the `bmpch.hpp` instead of every specific include that it may need.
