CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
UTUNES_DIR=Utunes/
SONG_DIR=Song/
USER_DIR=User/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: utunes.out

utunes.out: obj/main.o obj/utunes.o obj/song.o obj/user.o
	$(CPP) obj/main.o obj/utunes.o obj/song.o obj/user.o -o utunes.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/utunes.o: $(UTUNES_DIR)Utunes.cpp $(UTUNES_DIR)Utunes.hpp main/Exceptions.hpp
	$(CPP) -c $(UTUNES_DIR)Utunes.cpp -o obj/utunes.o

obj/song.o: $(SONG_DIR)Song.cpp $(SONG_DIR)Song.hpp
	$(CPP) -c $(SONG_DIR)Song.cpp -o obj/song.o

obj/user.o: $(USER_DIR)User.cpp $(USER_DIR)User.hpp
	$(CPP) -c $(USER_DIR)User.cpp -o obj/user.o

clean:
	rm -r *.out
	rm -r obj/*.o
