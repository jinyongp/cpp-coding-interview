# C++ Coding Interview

## 💬 Table of Contents

- [Getting Started](#getting-started)
- [Data Structure Theory](./docs/Data%20Structure%20Theory/README.md)
- [Algorithm Theory](./docs/Algorithm%20Theory/README.md)
- [Problem Solving](./tasks/README.md)

## 🎉 Getting Started

**[Fork](https://github.com/jinyongp/cpp-coding-interview/fork) This Project 🔥**

### 🛠 Prerequisites

#### 1. Install packages/tools

**프로젝트에 필요한 도구를 설치합니다. (\*필수)**

- *make
- *[CMake](https://cmake.org/download/)
- clang-format

#### 2. Install extensions

**VSCode extension을 설치합니다.**
(vscode를 이용하지 않는다면 건너뛰어도 무방합니다.)

<kbd>Ctrl</kbd> + <kbd>P</kbd> 혹은 <kbd>⌘</kbd> + <kbd>P</kbd> 를 누르고 아래 내용을 붙여 넣습니다.

```sh
ext install ms-vscode.cpptools matepek.vscode-catch2-test-adapter ms-vscode.cmake-tools mitaki28.vscode-clang
```

- 설치 목록: C/C++, C++ TestMate, CMake Tools, C/C++ Command Adapter

**Extension을 위한 몇 가지 설정을 합니다.**

1. <kbd>F1</kbd>을 눌러 Command Palette를 열고 `C/C++: Edit Configuration (UI)`를 눌러 설정을 시작합니다.
   -  Include Path에 아래 내용을 추가합니다.
      ```sh
      ${workspaceFolder}
      ${workspaceFolder}/build/_deps/googletest-src/googletest/include
      ${workspaceFolder}/build/_deps/googletest-src/googlemock/include
      ```
   -  C++ standard를 `c++20`으로 변경합니다.
   -  Advanced Settings를 열고 Configuration provider에 `ms-vscode.cmake-tools`를 작성합니다.

2. [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html)을 사용하고 있다면, `.vscode/settings.json`에서 `C_Cpp.clang_format_path` 값을 자신의 `clang-format` 위치로 변경합니다. 해당 위치는 터미널에서 `which clang-format` 명령을 실행하여 얻을 수 있습니다.

#### 3. Initialize a project

**`make init` 명령어를 통해 프로젝트를 초기화합니다.**

그 외 실행 명령어

- `make`: 빌드
- `make init`: 초기화
- `make test`: 테스트
- `make format`: 코드 포맷팅 (based on clang-format)

### 🧪 Pass All The Tests

**[`sources`](./sources) 폴더 내, `TODO`를 수행하며 모든 테스트를 통과하도록 구현하는 것이 목표입니다.**

- 코드를 수정하고, `make` 명령어를 실행하여 빌드를 합니다.
- 여러 방법으로 테스트를 수행할 수 있습니다.
  - 각 테스트 케이스 위에 존재하는 <kbd>Run</kbd> 버튼을 클릭합니다.
  - 사이드에 위치한 Testing 탭에서 개별 테스트를 진행합니다.
  - `make test` 명령어를 실행합니다.
- [`tests`](./tests) 폴더 내에 있는 `*.test.cc` 파일을 확인하여 어느 부분에서 문제가 발생했는지 확인할 수 있습니다.
- [`keys`](./keys) 폴더에서 모든 테스트를 통과하는 코드를 참고할 수 있습니다.
- 테스트 케이스를 통과하셨나요? [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려 자랑해주세요!

## 📝 Notes

- 예제 코드는 간결함을 위해 기본 라이브러리 및 `std` 작성을 생략했습니다.
- 모든 코드는 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)를 준수했습니다.
- 코드 스타일을 수정하고 싶다면, [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)를 참고하여 [`.clang-format`](./.clang-format)에 적용합니다.
- C++ 테스트를 위해 [GoogleTest Framework](https://github.com/google/googletest)를 적용했습니다.
- 프로젝트 빌드를 위해 [`cmake`](https://cmake.org/)와 `makefile`을 사용했습니다.

## 👥 Contributions

- 테스트 케이스의 오류/누락을 발견하신다면 [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new) 혹은 [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려주세요!
<!-- - 추가되었으면 하는 자료구조 혹은 알고리즘을 [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new)로 알려주세요! 금방 추가해보겠습니다. 😁 -->

## 🌐 References

- [GeeksForGeeks Practice Problems](https://practice.geeksforgeeks.org/explore/?page=1)
