
random: rand.o
	g++ -o random rand.o

random.o:
	g++ --std=c++-17 -c ./rand.cpp

all: random
