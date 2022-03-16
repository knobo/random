
random: rand.o
	g++ -o random rand.o

random.o:
	g++ -c ./rand.cpp

all: random
