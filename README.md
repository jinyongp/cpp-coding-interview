# Coding Interview

## Table of Contents

- [Getting Started](#getting-started)
- [Data Structure Theory](./docs/Data%20Structure%20Theory/README.md)
- [Algorithm Theory](./docs/Algorithm%20Theory/README.md)
- [Problem Solving](./tasks/README.md)

## Getting Started

### Prerequisites

#### Install packages

프로젝트에 필요한 패키지를 설치합니다.

```sh
brew install cmake clang-format
```

#### Install extensions

아래 목록의 vscode extension을 설치합니다.

- C/C++: `ms-vscode.cpptools`
- C++ TestMate: `matepek.vscode-catch2-test-adapter`
- Better C++ Syntax: `jeff-hykin.better-cpp-syntax`
- TODO Highlight v2: `jgclark.vscode-todo-highlight`

Extension을 위한 몇 가지 설정을 합니다.

1. GoogleTest를 불러오기 위해 <kbd>F1</kbd>을 눌러 `Command Palette`를 열고 `C_Cpp.ConfigurationProviderSelect`를 찾아 클릭한 뒤, `CMake Tools`를 추가해야 합니다.
2. [`clang-format`](https://clang.llvm.org/docs/ClangFormat.html)을 사용하고 있다면, `.vscode/settings.json`에서 `C_Cpp.clang_format_path` 값을 자신의 `clang-format` 위치로 변경합니다. 해당 위치는 터미널에서 `which clang-format`을 실행하여 얻을 수 있습니다.

#### Initialize project

프로젝트를 초기화합니다.

```sh
make init
```

그 외 실행 명령어

- `make`: 컴파일 및 빌드
- `make test`: 테스트 실행
- `make format`: 코드 포맷팅 (based on clang-format)
- `make clean init`: 빌드 파일 제거 및 새로 생성

### Pass all the tests

`sources` 폴더 내, `TODO`를 수행하며 모든 테스트를 통과하도록 구현합니다.

- 코드를 수정하고, `make` 명령어를 실행하면 빌드가 완료됩니다.
- `make test` 명령어로 테스트를 할 수 있습니다. 혹은, 좌측 Testing 탭(C++ TestMate)에서 개별 테스트가 가능합니다.
- `tests` 폴더 내에 있는 `*.test.cc` 파일을 확인하여 어느 부분에서 문제가 있는건지 볼 수 있습니다.
- `keys` 폴더에서 모든 테스트를 통과하는 코드를 확인할 수 있습니다.

## Notes

- 예제 코드는 간결함을 위해 기본 라이브러리 및 `std` 작성을 생략합니다.
- 모든 코드는 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)를 준수합니다.
- 코드 스타일을 수정하고 싶다면, [Clang-Format Style Options](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)를 참고하여 [`.clang-format`](./.clang-format)에 적용하세요.
- C++ 테스트를 위해 [GoogleTest Framework](https://github.com/google/googletest)를 적용했습니다.
- 프로젝트 빌드를 위해 [`cmake`](https://cmake.org/)와 `makefile`을 사용합니다.

## Reference

- [GeeksForGeeks Practice Problems](https://practice.geeksforgeeks.org/explore/?page=1)
