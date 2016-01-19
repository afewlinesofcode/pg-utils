# TODO: Don't have time for autotools at this moment. Will use them later.

all: dist/pg-util

dist/pg-util: dist
	g++ -o dist/pg-util src/main.cpp -std=c++14 -I./include

dist:
	mkdir -p dist

clean:
	rm -f dist/pg-util
