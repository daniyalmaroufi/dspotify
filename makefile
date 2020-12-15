CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
UTUNES_DIR=Utunes/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: utunes.out

utunes.out: obj/main.o obj/utunes.o
	$(CPP) obj/main.o obj/utunes.o -o utunes.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/utunes.o: $(UTUNES_DIR)Utunes.cpp $(UTUNES_DIR)Utunes.hpp $(UTUNES_DIR)Exceptions.hpp
	$(CPP) -c $(UTUNES_DIR)Utunes.cpp -o obj/utunes.o

clean:
	rm -r *.out
	rm -r obj/*.o
