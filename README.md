# C++ Coding Interview <!-- omit in toc -->

## 💬 Table of Contents <!-- omit in toc -->

- [🎉 Getting Started](#-getting-started)
  - [🛠 Prerequisites](#-prerequisites)
  - [🧪 Pass All The Tests](#-pass-all-the-tests)
- [📝 Notes](#-notes)
- [👥 Contributions](#-contributions)
- [🌐 References](#-references)


## 🎉 Getting Started

**[Fork](https://github.com/jinyongp/cpp-coding-interview/fork) This Project 🔥**

### 🛠 Prerequisites

#### 1. Install packages/tools <!-- omit in toc -->

**프로젝트에 필요한 도구를 설치합니다.**

- [make](https://www.gnu.org/software/make/)
- [CMake](https://cmake.org/download/)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html) (optional)

#### 2. Install extensions <!-- omit in toc -->

**VSCode Extension 설치**

[extensions.json](./.vscode/extensions.json) 파일을 참고하여 필요한 Extension을 설치합니다.

#### 3. Initialize a project <!-- omit in toc -->

**아래 명령어를 통해 프로젝트를 초기화합니다.**

```bash
$ make init

# 도움말 출력
$ make
```

그 외 실행 명령어


### 🧪 Pass All The Tests

**[`src`](./src) 디렉터리 내, `TODO`를 수행하며 모든 테스트를 통과하도록 구현하는 것이 목표입니다.**

- 코드를 수정하고, `make` 명령어를 실행하여 빌드를 합니다.
- `make test` 명령어 혹은 `matepek.vscode-catch2-test-adapter` Extension을 통해 테스트를 실행합니다.
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
