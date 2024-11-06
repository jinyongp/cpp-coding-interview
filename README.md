# C++ 코딩 인터뷰 <!-- omit in toc -->

자료구조, 알고리즘 그 외 코딩 과제를 풀거나 추가할 수 있는 저장소입니다.

**과제를 풀고 싶거나 추가하고 싶다면 [🛠 준비하기](#-준비하기)를 확인해주세요.**

## 💬 목차 <!-- omit in toc -->

- [🌈 디렉터리 구조](#-디렉터리-구조)
- [🛸 명령어](#-명령어)
- [🛠 준비하기](#-준비하기)
  - [프로젝트 준비](#프로젝트-준비)
  - [패키지 및 도구 설치](#패키지-및-도구-설치)
  - [VSCode 확장 프로그램 설치](#vscode-확장-프로그램-설치)
  - [프로젝트 초기화](#프로젝트-초기화)
- [🎉 시작하기](#-시작하기)
- [👥 기여하기](#-기여하기)
- [📝 참고사항](#-참고사항)
- [🌐 참고자료](#-참고자료)

## 🌈 디렉터리 구조

```bash
src
├── stack
│   ├── README.md        -- 과제 설명
│   ├── stack.h          -- 구현해야 할 파일
│   ├── stack.cc         -- 관련 개념 예시 파일
│   └── stack.hint.h     -- 모든 테스트를 통과하는 코드
│   ├── stack.test.cc    -- 테스트 파일
└── ...
```

**`src` 디렉터리 내에는 각 자료구조 혹은 알고리즘에 대한 디렉터리가 존재합니다.**

- 각 디렉터리에는 `README.md`, `*.h`, `*.cc`, `*.test.cc`, `*.hint.h` 파일이 존재합니다.

  - `README.md`: 해당 자료구조 혹은 알고리즘에 대한 개념과 구현해야 할 내용이 작성되어 있습니다.

  - `*.h`: 구현해야 할 과제 파일입니다.
  - `*.cc`: 관련 개념을 이해하기 위한 예시 파일입니다.
  - `*.hint.h`: 모든 테스트를 통과하는 코드입니다.
  - `*.test.cc`: 테스트 파일입니다.

어떤 방식으로든 테스트를 통과하는 코드를 작성하면 됩니다.

## 🛸 명령어

```bash
# 프로젝트 초기화
$ make init

# 모든 테스트 실행
$ make test

# 특정 테스트 실행
$ make test name=stack
$ make test name=stack.Push

# 예시 코드 실행
$ make run name=stack

# 코드 스타일 가이드 적용
$ make format

# 도움말 출력
$ make
$ make help
```

## 🛠 준비하기

**아래 설정을 완료하고**

- 과제를 수행하고 싶다면 [🎉 시작하기](#-시작하기)로 이동하세요.
- 기존 과제를 보완하거나 새로운 과제를 추가하고 싶다면 [👥 기여하기](#-기여하기)로 이동하세요.

### 프로젝트 준비

**이 프로젝트를 [Fork](https://github.com/jinyongp/cpp-coding-interview/fork) 하세요! 🔥**

Fork가 완료되면, 프로젝트를 로컬 환경으로 Clone합니다.

```bash
$ cd /path/to/your/workspace
$ git clone https://github.com/<username>/cpp-coding-interview.git
```

### 패키지 및 도구 설치

**프로젝트에 필요한 도구를 설치합니다.**

- gcc, g++
- [make](https://www.gnu.org/software/make/)
- [CMake](https://cmake.org/download/)
- [clang-format](https://clang.llvm.org/docs/ClangFormat.html) (recommended)

### VSCode 확장 프로그램 설치

VSCode를 사용 중이시라면, 확장(Extensions) 탭으로 이동하여 `@recommended`를 검색하고 모두 설치합니다.

### 프로젝트 초기화

**아래 명령어를 통해 프로젝트를 초기화합니다.**

```bash
$ make init
```

## 🎉 시작하기

**[`src`](./src) 디렉터리 내, `todo`를 수행하여 모든 테스트를 통과하도록 구현하는 것이 목표입니다.**

>아래 예시는 `stack` 과제를 수행하는 방법입니다.

1. 과제를 시작하기 전, 새로운 git branch를 생성합니다.

   ```bash
   $ git pull upstream main
   $ git checkout -b stack
   ```
2. [src/stack/README.md](./src/stack/README.md) 파일을 열어 과제에 필요한 개념을 읽고 이해합니다.
   - `make run name=stack` 명령어를 실행하여 예시 코드를 실행하여 실제 동작을 확인하세요.
3. [src/stack/stack.interface.h](./src/stack/stack.interface.h) 파일을 열어 구현해야 할 메서드를 확인합니다.
4. [src/stack/stack.h](./src/stack/stack.h) 파일을 메서드를 모두 구현합니다.
   - `throw utils::todo();` 라인을 지우고 함수가 정상적으로 동작할 수 있도록 코드를 작성세요.
5. 어느정도 구현을 완료했다면, 테스트를 실행하여 작성한 소스 코드가 정상적으로 동작하는지 확인합니다. 테스트를 수행하기 위해선 아래 두 가지 방법이 있습니다.
   - 터미널에서 아래 명령어를 실행합니다. (`name` 인자를 전달하여 특정 테스트만 실행할 수 있습니다.)
      ```bash
      # 모든 stack 테스트 실행
      $ make test name=stack

      # 특정 테스트만 실행
      $ make test name=stack.Push
      ```
   - VSCode 내 테스트 탭을 열어 테스트를 실행합니다.
6. 테스트 결과를 확인하고 모두 통과할 때까지 코드를 수정합니다.
7. 구현에 어려움이 있다면, [stack.test.cc](./src/stack/stack.test.cc) 파일을 참고하여 적절한 동작을 이해하고 구현합니다.
8. [stack.hint.h](./src/stack/stack.hint.h.) 파일을 통해 모든 테스트를 통과하는 코드를 참고할 수 있습니다.
9. 모든 테이트 케이스를 완료했다면? 작업물을 커밋하고 [PR](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려 자랑해주세요!

## 👥 기여하기

>테스트 케이스에서 오류/누락을 발견하신다면 [Issue](https://github.com/jinyongp/cpp-coding-interview/issues/new) 혹은 [Pull Request](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)를 등록해주세요!

과제를 직접 추가해보세요! 🚀

```bash
# 과제 템플릿 추가
$ make generate name=<name>

# 추가한 파일 빌드
$ make init_dev
```

위 명령어를 통해 `src/<name>` 디렉터리가 생성되며, 해당 디렉터리 내에 과제를 추가할 수 있습니다.

[디렉터리 구조](#-디렉터리-구조)를 참고하여 파일을 작성하고, 아래 명령어를 통해 테스트를 실행하세요.

```bash
# <name>.cc 파일 실행
$ make run name=<name>

# <name>.test.cc 파일 실행
$ make test name=<name>
```

추가한 과제를 [Pull Request](https://github.com/jinyongp/cpp-coding-interview/pulls?q=is%3Apr+is%3Aopen+sort%3Aupdated-desc)을 올려주세요!

## 📝 참고사항

- 모든 코드는 [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)를 준수했습니다.
- 코드 스타일 일관성을 위해 [Clang-Format Style](https://clang.llvm.org/docs/ClangFormatStyleOptions.html)을 활용합니다.
- C++ 테스트를 위해 [GoogleTest Framework](https://github.com/google/googletest)를 적용했습니다.
- 프로젝트 빌드를 위해 [`cmake`](https://cmake.org/)와 `makefile`을 사용했습니다.

## 🌐 참고자료

- [GeeksForGeeks Practice Problems](https://practice.geeksforgeeks.org/explore/?page=1)
- [GeeksForGeeks Learn Data Structures and Algorithms](https://www.geeksforgeeks.org/learn-data-structures-and-algorithms-dsa-tutorial/)