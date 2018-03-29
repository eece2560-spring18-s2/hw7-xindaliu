CFLAGS=-Wall -Werror -std=c++11 -I../../src -g

all:test

test: test.o database.o csv_reader.o member.o
	g++ $^ -o $@ $(CFLAGS)

test.o: test.cc
	g++ $^ -c -o $@ $(CFLAGS)

%.o: ../../src/%.cc
	g++ $^ -c -o $@ $(CFLAGS)

clean:
	rm test *.o
