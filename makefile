.PHONY: compile format init test

help:
	@echo "  Usage: make [target]"
	@echo "    Targets:   Arguments:  Description:"
	@echo "    init                   Initialize the project"
	@echo "    compile                Compile the project"
	@echo "    format                 Format the source code"
	@echo "    test       filter      Run the tests"


compile:
	@cd build && make

format:
	@if command -v clang-format > /dev/null; then \
		find -E sources -regex '.*\.(h|cc)' -exec clang-format -i {} \; ; \
	else \
		echo "[ERROR] clang-format is not installed. Please install clang-format to use this command."; \
	fi

init:
	@rm -rf build && mkdir build && cd build && cmake .. && make

test:
ifdef filter
	cd build && ctest -R $(filter)
else
	cd build && ctest
endif