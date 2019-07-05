.PHONY: default
default: help
	@false

.PHONY: help
help:
	@echo 'Usage:'
	@echo '    make COMMAND (OPTION)'
	@echo
	@echo 'Commands:'
	@echo '    help'
	@echo '    build'
	@echo '    clean'
	@echo '    cmake'
	@echo '    lint'

.PHONY: build
build: cmake
	cmake --build build

.PHONY: clean
clean:
	rm -rf build

.PHONY: cmake
cmake:
	mkdir -p build && cd build && cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON ..

.PHONY: lint
lint:
	pipenv run cpplint --filter=-legal/copyright *.cc
