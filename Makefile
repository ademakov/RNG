
CXXFLAGS=-std=c++14 -O2

test: test.cc rng.h

all: test

clean:
	rm -f test
