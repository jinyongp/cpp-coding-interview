#!/usr/bin/env bash

if [ -z $name ]; then
  command=$(basename $0 .sh)
  echo "Usage: $command name=<name>"
  exit 1
fi

cd $(dirname $0)/../src

mkdir -p $name
cd $name

# README.md
# $name.cc
# $name.h
# $name.hint.h
# $name.interface.h
# $name.test.cc

echo "# ${name^} <kbd>[Pass Me](./$name.h)</kbd>" > README.md

cat <<EOF > $name.cc
#include <iostream>

using namespace std;

int main() {
  // code here

  return 0;
}
EOF

cat <<EOF > $name.h
#ifndef ${name^^}_H_
#define ${name^^}_H_

#include "${name}.interface.h"
#include "utils.h"

/// @brief Description
class ${name^} : public ${name^}Interface {
 private:
  // private members

 public:
  // public methods
};

#endif  // ${name^^}_H_
EOF

cat <<EOF > $name.hint.h
#ifndef ${name^^}_H_
#define ${name^^}_H_

#include "${name}.interface.h"
#include "utils.h"

class ${name^} : public ${name^}Interface {
 private:
  // private members

 public:
  // public methods
};

#endif  // ${name^^}_H_
EOF

cat <<EOF > $name.interface.h
#ifndef ${name^^}_INTERFACE_H_
#define ${name^^}_INTERFACE_H_

#include <cstddef>

class ${name^}Interface {
 public:
  /// @brief 기본 생성자
  ${name^}Interface() = default;

  /// @brief 가상 소멸자
  virtual ~${name^}Interface() = default;
};

#endif  // ${name^^}_INTERFACE_H_
EOF

cat <<EOF > $name.test.cc
#include <gtest/gtest.h>

#ifdef DEV
#include "${name}.hint.h"
#else
#include "${name}.h"
#endif

class ${name} : public ::testing::Test {
 protected:
  void SetUp() override {}

  void TearDown() override {}
};

TEST_F(${name}, Test) {
  ASSERT_TRUE(true);
}
EOF
