all: compile run

compile:
	mkdir -p bin
	gcc src/2048.c -o bin/2048 -Wall -Werror

run:
	./bin/2048
