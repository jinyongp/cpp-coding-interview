# C++ Coding Interview <!-- omit in toc -->

## 💬 Table of Contents <!-- omit in toc -->

- [🎉 Getting Started](#-getting-started)
  - [🛠 Prerequisites](#-prerequisites)
  - [🧪 Pass All The Tests](#-pass-all-the-tests)
- [🚩 Tests](#-tests)
- [📝 Notes](#-notes)
- [👥 Contributions](#-contributions)
- [🌐 References](#-references)


## 🎉 Getting Started

### Fork the project <!-- omit in toc -->

**이 프로젝트를 [Fork](https://github.com/jinyongp/cpp-coding-interview/fork) 하세요! 🔥**

Fork가 완료되면, 프로젝트를 로컬 환경으로 Clone합니다.

```bash
$ cd /path/to/your/workspace
$ git clone https://github.com/<username>/cpp-coding-interview.git
```

### 🛠 Prerequisites

#### 1. Install packages and tools <!-- omit in toc -->

**프로젝트에 필요한 도구를 설치합니다.**

- [make](https://www.gnu.org/software/make/)
- [CMake](https://cmake.org/download/)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html) (recommended)

#### 2. Install vscode extensions <!-- omit in toc -->

VSCode를 사용 중이시라면, 확장(Extensions) 탭으로 이동하여 `@recommended`를 검색하고 모두 설치합니다.

#### 3. Initialize a project <!-- omit in toc -->

**아래 명령어를 통해 프로젝트를 초기화합니다.**

```bash
$ make init

# 도움말 출력
$ make
```

### 🧪 Pass All The Tests

**[`src`](./src) 디렉터리 내, `todo`를 수행하여 모든 테스트를 통과하도록 구현하는 것이 목표입니다.**

>아래 예시는 `stack` 과제를 수행하는 방법입니다.

1. 과제를 시작하기 전, 새로운 git branch를 생성합니다.

   ```bash
   $ git pull upstream main
   $ git checkout -b stack
   ```
3. [stack.h](./src/stack/stack.h) 파일을 열어 주석을 읽고 각 함수의 의도에 맞게 구현합니다.
   - `throw todo();`를 지우고 함수가 정상적으로 동작할 수 있도록 코드를 작성하세요.
4. 구현을 완료했다면, 테스트를 실행하여 작성한 소스 코드가 정상적으로 동작하는지 확인합니다.
   -  테스트를 수행하기 위해선 아래 두 가지 방법이 있습니다.

      1. 터미널에서 아래 명령어를 실행합니다. (`filter` 인자를 전달하여 특정 테스트만 실행할 수 있습니다.)

         ```bash
         # 모든 stack 테스트 실행
         $ make test filter='stack.*' 

         # 특정 테스트만 실행
         $ make test filter='stack.Push'
         ```
      2. VSCode 내 설치한 `matepek.vscode-catch2-test-adapter` Extension을 통해 테스트를 실행합니다.
   - 테스트 결과를 확인하고 모두 통과할 때까지 코드를 수정합니다.
5. 구현에 어려움이 있다면, `stack.test.cc` 파일을 참고하여 적절한 동작을 이해하고 구현합니다.
6. `stack.hint.h` 파일을 통해 모든 테스트를 통과하는 코드를 참고할 수 있습니다.
7. 모든 테이트 케이스를 완료했다면? 작업물을 커밋하고 [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려 자랑해주세요!

## 🚩 Tests

**자료구조**

- [Stack](./src/stack/stack.h)

## 📝 Notes

- 모든 코드는 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)를 준수했습니다.
- 코드 스타일 일관성을 위해 [Clang-Format Style](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)을 활용합니다.
- C++ 테스트를 위해 [GoogleTest Framework](https://github.com/google/googletest)를 적용했습니다.
- 프로젝트 빌드를 위해 [`cmake`](https://cmake.org/)와 `makefile`을 사용했습니다.

## 👥 Contributions

- 테스트 케이스의 오류/누락을 발견하신다면 [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new) 혹은 [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려주세요!
<!-- - 추가되었으면 하는 자료구조 혹은 알고리즘을 [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new)로 알려주세요! 금방 추가해보겠습니다. 😁 -->

## 🌐 References

- [GeeksForGeeks Practice Problems](https://practice.geeksforgeeks.org/explore/?page=1)
