.PHONY: compile format init test

help:
	@echo "  Usage: make [target]"
	@echo "    Targets:   Arguments:  Description:"
	@echo "    init                   Initialize the project"
	@echo "    compile                Compile the project"
	@echo "    format                 Format the source code"
	@echo "    test       filter      Run the tests"


compile:
	@cmake --build build

format:
	@if command -v clang-format > /dev/null; then \
		find -E sources -regex '.*\.(h|cc)' -exec clang-format -i {} \; ; \
	else \
		echo "[ERROR] clang-format is not installed. Please install clang-format to use this command."; \
	fi

init:
	@rm -rf build
	@cmake -S . -B build
	@cmake --build build

test:
	@cmake --build build 1>/dev/null
	@if [ -z "$(filter)" ]; then \
		cd build && ctest 2>/dev/null; \
	else \
		export DEV="$(dev)"; \
		cd build && ctest --output-on-failure -R $(filter) 2>/dev/null; \
	fi;
