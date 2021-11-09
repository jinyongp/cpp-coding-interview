compile:
	cd build && make

format:
	find -E sources -regex '.*\.(h|cc)' -exec clang-format -i {} \;

init:
	rm -rf build && mkdir build && cd build && cmake .. && make

test:
	cd build && ctest
