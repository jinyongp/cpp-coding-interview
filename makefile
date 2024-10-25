.PHONY: help compile format init open test dev

BUILD=cmake --build build
TEST=cd build && ctest --output-on-failure
FILTER=grep -vE "^\s+(Start|Running|\/)"

help:
	@echo "  Usage: make [target]"
	@echo "    Targets:   Arguments:  Description:"
	@echo "    init                   Initialize the project"
	@echo "    compile                Compile the project"
	@echo "    format                 Format the source code"
	@echo "    test       filter      Run the tests"

compile:
	@$(BUILD)

format:
	@if command -v clang-format > /dev/null; then \
		find -E src -regex '.*\.(h|cc)' -exec clang-format -i {} \; ; \
	else \
		echo "[ERROR] clang-format is not installed. Please install clang-format to use this command."; \
	fi

init:
	@rm -rf build
	@cmake -S . -B build
	@$(BUILD)

test:
	@$(BUILD) 1>/dev/null
	
	@export DEV="$(dev)"; \
	if [ -z "$(filter)" ]; then \
		$(TEST) 2>/dev/null | $(FILTER); \
	else \
		$(TEST) -R $(filter) 2>/dev/null | $(FILTER); \
	fi;

dev:
	@$(MAKE) test dev=true
