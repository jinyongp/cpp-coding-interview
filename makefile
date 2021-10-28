compile:
	cd build && make

init:
	mkdir -p build && cd build && cmake .. && make

test:
	cd build && ctest

clean:
	rm -rf build