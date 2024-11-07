#!/usr/bin/env bash

set -e

if [ -z "$name" ]; then
  command=$(basename "$0" .sh)
  echo "Usage: $command name=<name>"
  exit 1
fi

cd "$(dirname "$0")"/../src

mkdir -p "$name"
cd "$name"

snake_case=$(perl -pe 's/([a-z0-9])([A-Z])/$1_\L$2/g' <<< "$name" | tr '[:upper:]' '[:lower:]')
PascalCase=$(perl -pe 's/(^|_)([a-z])/\U$2/g' <<< "$snake_case")

echo "# ${PascalCase} <kbd>[Pass Me](./$name.h)</kbd>" > README.md

cat <<EOF > $snake_case.cc
#include <iostream>

using namespace std;

int main() {
  // code here

  return 0;
}
EOF

cat <<EOF > $snake_case.h
#ifndef ${snake_case^^}_H_
#define ${snake_case^^}_H_

#include "${snake_case}.interface.h"
#include "utils.h"

/// @brief Description
class ${PascalCase} : public ${PascalCase}Interface {
 private:
  // private members

 public:
  // public methods
};

#endif  // ${snake_case^^}_H_
EOF

cat <<EOF > $snake_case.hint.h
#ifndef ${snake_case^^}_H_
#define ${snake_case^^}_H_

#include "${snake_case}.interface.h"
#include "utils.h"

class ${PascalCase} : public ${PascalCase}Interface {
 private:
  // private members

 public:
  // public methods
};

#endif  // ${snake_case^^}_H_
EOF

cat <<EOF > $snake_case.interface.h
#ifndef ${snake_case^^}_INTERFACE_H_
#define ${snake_case^^}_INTERFACE_H_

#include <cstddef>

class ${PascalCase}Interface {
 public:
  /// @brief 기본 생성자
  ${PascalCase}Interface() = default;

  /// @brief 가상 소멸자
  virtual ~${PascalCase}Interface() = default;
};

#endif  // ${snake_case^^}_INTERFACE_H_
EOF

cat <<EOF > $snake_case.test.cc
#include <gtest/gtest.h>

#ifdef DEV
#include "${snake_case}.hint.h"
#else
#include "${snake_case}.h"
#endif

class ${snake_case} : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(${snake_case}, Test) {
  ASSERT_TRUE(true);
}
EOF
