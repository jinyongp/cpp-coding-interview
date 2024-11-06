.PHONY: help init init_dev build test list format run

BUILD=cmake --build build

help:
	@echo "  Usage: make [target]"
	@echo "    Targets:   Arguments:  Description:"
	@echo "    init                   Initialize the project"
	@echo "    build                  Build the project"
	@echo "    test       filter=     Run the tests"
	@echo "    list                   List the tests"
	@echo "    format                 Format the source code"
	@echo "    run        file=       Run the program"

init:
	@rm -rf build
	@cmake -S . -B build -DDEV=$(dev)
	@$(MAKE) build

build:
	@$(BUILD)

test:
	@$(MAKE) build 1>/dev/null
	@./scripts/test.sh

list:
	@$(MAKE) build 1>/dev/null
	@./build/main --gtest_list_tests

format:
	@./scripts/format.sh

run:
	@$(MAKE) build 1>/dev/null
	@./scripts/run.sh


# DEV ONLY

init_dev:
	@$(MAKE) init dev=true
