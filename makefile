CPPFLAGS = -Wall -Wconversion -Werror -g
VALGRIND_FLAGS=--leak-check=full --track-origins=yes --show-reachable=yes --error-exitcode=2

all: tp2 probar_memoria

tp2: *.cpp
	g++ main.cpp src/*.cpp $(CPPFLAGS) -o tp2

probar_memoria: tp2
	valgrind $(VALGRIND_FLAGS) ./tp2
