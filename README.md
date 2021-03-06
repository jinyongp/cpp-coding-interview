# C++ Coding Interview

## ๐ฌ Table of Contents

- [Getting Started](#getting-started)
- [Data Structure Theory](./docs/Data%20Structure%20Theory/README.md)
- [Algorithm Theory](./docs/Algorithm%20Theory/README.md)
- [Problem Solving](./tasks/README.md)

## ๐ Getting Started

**[Fork](https://github.com/jinyongp/cpp-coding-interview/fork) This Project ๐ฅ**

### ๐  Prerequisites

#### 1. Install packages/tools

**ํ๋ก์ ํธ์ ํ์ํ ๋๊ตฌ๋ฅผ ์ค์นํฉ๋๋ค. (\*ํ์)**

- *make
- *[CMake](https://cmake.org/download/)
- clang-format

#### 2. Install extensions

**VSCode extension์ ์ค์นํฉ๋๋ค.**
(vscode๋ฅผ ์ด์ฉํ์ง ์๋๋ค๋ฉด ๊ฑด๋๋ฐ์ด๋ ๋ฌด๋ฐฉํฉ๋๋ค.)

<kbd>Ctrl</kbd> + <kbd>P</kbd> ํน์ <kbd>โ</kbd> + <kbd>P</kbd> ๋ฅผ ๋๋ฅด๊ณ  ์๋ ๋ด์ฉ์ ๋ถ์ฌ ๋ฃ์ต๋๋ค.

```sh
ext install ms-vscode.cpptools matepek.vscode-catch2-test-adapter ms-vscode.cmake-tools mitaki28.vscode-clang
```

- ์ค์น ๋ชฉ๋ก: C/C++, C++ TestMate, CMake Tools, C/C++ Command Adapter

**Extension์ ์ํ ๋ช ๊ฐ์ง ์ค์ ์ ํฉ๋๋ค.**

1. <kbd>F1</kbd>์ ๋๋ฌ Command Palette๋ฅผ ์ด๊ณ  `C/C++: Edit Configuration (UI)`๋ฅผ ๋๋ฌ ์ค์ ์ ์์ํฉ๋๋ค.
   -  Include Path์ ์๋ ๋ด์ฉ์ ์ถ๊ฐํฉ๋๋ค.
      ```sh
      ${workspaceFolder}
      ${workspaceFolder}/build/_deps/googletest-src/googletest/include
      ${workspaceFolder}/build/_deps/googletest-src/googlemock/include
      ```
   -  C++ standard๋ฅผ `c++20`์ผ๋ก ๋ณ๊ฒฝํฉ๋๋ค.
   -  Advanced Settings๋ฅผ ์ด๊ณ  Configuration provider์ `ms-vscode.cmake-tools`๋ฅผ ์์ฑํฉ๋๋ค.

2. [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html)์ ์ฌ์ฉํ๊ณ  ์๋ค๋ฉด, `.vscode/settings.json`์์ `C_Cpp.clang_format_path` ๊ฐ์ ์์ ์ `clang-format` ์์น๋ก ๋ณ๊ฒฝํฉ๋๋ค. ํด๋น ์์น๋ ํฐ๋ฏธ๋์์ `which clang-format` ๋ช๋ น์ ์คํํ์ฌ ์ป์ ์ ์์ต๋๋ค.

#### 3. Initialize a project

**`make init` ๋ช๋ น์ด๋ฅผ ํตํด ํ๋ก์ ํธ๋ฅผ ์ด๊ธฐํํฉ๋๋ค.**

๊ทธ ์ธ ์คํ ๋ช๋ น์ด

- `make`: ๋น๋
- `make init`: ์ด๊ธฐํ
- `make test`: ํ์คํธ
- `make format`: ์ฝ๋ ํฌ๋งทํ (based on clang-format)

### ๐งช Pass All The Tests

**[`sources`](./sources) ํด๋ ๋ด, `TODO`๋ฅผ ์ํํ๋ฉฐ ๋ชจ๋  ํ์คํธ๋ฅผ ํต๊ณผํ๋๋ก ๊ตฌํํ๋ ๊ฒ์ด ๋ชฉํ์๋๋ค.**

- ์ฝ๋๋ฅผ ์์ ํ๊ณ , `make` ๋ช๋ น์ด๋ฅผ ์คํํ์ฌ ๋น๋๋ฅผ ํฉ๋๋ค.
- ์ฌ๋ฌ ๋ฐฉ๋ฒ์ผ๋ก ํ์คํธ๋ฅผ ์ํํ  ์ ์์ต๋๋ค.
  - ๊ฐ ํ์คํธ ์ผ์ด์ค ์์ ์กด์ฌํ๋ <kbd>Run</kbd> ๋ฒํผ์ ํด๋ฆญํฉ๋๋ค.
  - ์ฌ์ด๋์ ์์นํ Testing ํญ์์ ๊ฐ๋ณ ํ์คํธ๋ฅผ ์งํํฉ๋๋ค.
  - `make test` ๋ช๋ น์ด๋ฅผ ์คํํฉ๋๋ค.
- [`tests`](./tests) ํด๋ ๋ด์ ์๋ `*.test.cc` ํ์ผ์ ํ์ธํ์ฌ ์ด๋ ๋ถ๋ถ์์ ๋ฌธ์ ๊ฐ ๋ฐ์ํ๋์ง ํ์ธํ  ์ ์์ต๋๋ค.
- [`keys`](./keys) ํด๋์์ ๋ชจ๋  ํ์คํธ๋ฅผ ํต๊ณผํ๋ ์ฝ๋๋ฅผ ์ฐธ๊ณ ํ  ์ ์์ต๋๋ค.
- ํ์คํธ ์ผ์ด์ค๋ฅผ ํต๊ณผํ์จ๋์? [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)์ ์ฌ๋ ค ์๋ํด์ฃผ์ธ์!

## ๐ Notes

- ์์  ์ฝ๋๋ ๊ฐ๊ฒฐํจ์ ์ํด ๊ธฐ๋ณธ ๋ผ์ด๋ธ๋ฌ๋ฆฌ ๋ฐ `std` ์์ฑ์ ์๋ตํ์ต๋๋ค.
- ๋ชจ๋  ์ฝ๋๋ [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)๋ฅผ ์ค์ํ์ต๋๋ค.
- ์ฝ๋ ์คํ์ผ์ ์์ ํ๊ณ  ์ถ๋ค๋ฉด, [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)๋ฅผ ์ฐธ๊ณ ํ์ฌ [`.clang-format`](./.clang-format)์ ์ ์ฉํฉ๋๋ค.
- C++ ํ์คํธ๋ฅผ ์ํด [GoogleTest Framework](https://github.com/google/googletest)๋ฅผ ์ ์ฉํ์ต๋๋ค.
- ํ๋ก์ ํธ ๋น๋๋ฅผ ์ํด [`cmake`](https://cmake.org/)์ `makefile`์ ์ฌ์ฉํ์ต๋๋ค.

## ๐ฅ Contributions

- ํ์คํธ ์ผ์ด์ค์ ์ค๋ฅ/๋๋ฝ์ ๋ฐ๊ฒฌํ์ ๋ค๋ฉด [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new) ํน์ [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)์ ์ฌ๋ ค์ฃผ์ธ์!
<!-- - ์ถ๊ฐ๋์์ผ๋ฉด ํ๋ ์๋ฃ๊ตฌ์กฐ ํน์ ์๊ณ ๋ฆฌ์ฆ์ [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new)๋ก ์๋ ค์ฃผ์ธ์! ๊ธ๋ฐฉ ์ถ๊ฐํด๋ณด๊ฒ ์ต๋๋ค. ๐ -->

## ๐ References

- [GeeksForGeeks Practice Problems](https://practice.geeksforgeeks.org/explore/?page=1)
