.PHONY: help init build format test list dev

BUILD=cmake --build build

help:
	@echo "  Usage: make [target]"
	@echo "    Targets:   Arguments:  Description:"
	@echo "    init                  Initialize the project"
	@echo "    build                 Build the project"
	@echo "    format                Format the source code"
	@echo "    test       [filter]   Run the tests"
	@echo "    list                  List the tests"

init:
	@rm -rf build
	@cmake -S . -B build
	@$(BUILD)

test:
	@$(BUILD) 1>/dev/null
	@export DEV="$(dev)"; ./build/main --gtest_brief=1 --gtest_filter=$(or $(filter), "*")

list:
	@$(BUILD) 1>/dev/null
	@./build/main --gtest_list_tests

build:
	@$(BUILD)

format:
	@if command -v clang-format > /dev/null; then \
		find -E src -regex '.*\.(h|cc)' -exec clang-format -i {} \; ; \
	else \
		echo "[ERROR] clang-format is not installed. Please install clang-format to use this command."; \
	fi

dev:
	@$(MAKE) test dev=true
