compile:
	cd build && make

format:
	find -E src -regex '.*\.(h|cc)' -exec clang-format -i {} \;

init:
	mkdir -p build && cd build && cmake .. && make

test:
	cd build && ctest

clean:
	rm -rf build
