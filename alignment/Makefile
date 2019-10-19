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

.PHONY: up
up:
	docker-compose up --build -d

.PHONY: down
down:
	docker-compose down

.PHONY: shell
shell:
	docker-compose exec --user `id -u`:`id -g` be-compile bash

.PHONY: be-build
be-build:
	docker-compose exec --user `id -u`:`id -g` be-compile powerpc64-linux-gnu-g++ -std=c++11 -static src/main.cpp -o be-alignment

.PHONY: be-fetch
be-fetch:
	curl -fSL 'https://github.com/multiarch/qemu-user-static/releases/download/v4.1.0-1/qemu-ppc64-static.tar.gz' | tar -zxv

.PHONY: be-exec
be-exec:
	./qemu-ppc64-static be-alignment
