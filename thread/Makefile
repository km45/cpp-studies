OUT = dest

.DEFAULT_GOAL = build

.PHONY: clean
clean:
	rm -rf $(OUT)

.PHONY: cmake
cmake:
	mkdir -p $(OUT)
	cd $(OUT) && cmake -G Ninja -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

.PHONY: build
build: cmake
	cmake --build $(OUT)
