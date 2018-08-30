.PHONY: all
all: recursive template

.PHONY: recursive
recursive:
	g++ --std=c++17 -O2 -o recursive recursive.cc

.PHONY: template
template:
	g++ --std=c++17 -O2 -o template template.cc

.PHONY: clean
clean:
	rm -f recursive template
