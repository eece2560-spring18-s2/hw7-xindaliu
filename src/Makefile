CFLAGS=-Wall -Werror -std=c++11 -g

all: p1_main p2_main p3_main p4_main

p1_main: p1.o csv_reader.o database.o member.o
	g++ $^ -o $@ $(CFLAGS)

p2_main: p2.o csv_reader.o database.o member.o
	g++ $^ -o $@ $(CFLAGS)

p3_main: p3.o csv_reader.o database.o member.o
	g++ $^ -o $@ $(CFLAGS)

p4_main: p4.o csv_reader.o database.o member.o
	g++ $^ -o $@ $(CFLAGS)

%.o: %.cc
	g++ $^ -c -o $@ $(CFLAGS)

clean:
	rm p1_main p2_main p3_main p4_main *.o
