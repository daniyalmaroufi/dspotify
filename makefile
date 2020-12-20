CPP_EXEC=g++
CPP_STD=-std=c++11
CPP_FLAGS=-g
UTUNES_DIR=Utunes/
SONG_DIR=Song/
USER_DIR=User/
PLAYLIST_DIR=Playlist/
FILTERS_DIR=Filters/


CPP=$(CPP_EXEC) $(CPP_STD) $(CPP_FLAGS)

all: utunes.out

utunes.out: obj/main.o obj/utunes.o obj/song.o obj/user.o obj/functions.o obj/playlist.o\
 obj/artistfilter.o obj/yearfilter.o
	$(CPP) obj/main.o obj/utunes.o obj/song.o obj/user.o obj/functions.o obj/playlist.o\
 obj/artistfilter.o obj/yearfilter.o -o utunes.out

obj/main.o: main/main.cpp
	$(CPP) -c main/main.cpp -o obj/main.o

obj/utunes.o: $(UTUNES_DIR)Utunes.cpp $(UTUNES_DIR)Utunes.hpp main/Exceptions.hpp
	$(CPP) -c $(UTUNES_DIR)Utunes.cpp -o obj/utunes.o

obj/song.o: $(SONG_DIR)Song.cpp $(SONG_DIR)Song.hpp
	$(CPP) -c $(SONG_DIR)Song.cpp -o obj/song.o

obj/user.o: $(USER_DIR)User.cpp $(USER_DIR)User.hpp
	$(CPP) -c $(USER_DIR)User.cpp -o obj/user.o

obj/playlist.o: $(PLAYLIST_DIR)Playlist.cpp $(PLAYLIST_DIR)Playlist.hpp
	$(CPP) -c $(PLAYLIST_DIR)Playlist.cpp -o obj/playlist.o

obj/artistfilter.o: $(FILTERS_DIR)ArtistFilter.cpp $(FILTERS_DIR)ArtistFilter.hpp
	$(CPP) -c $(FILTERS_DIR)ArtistFilter.cpp -o obj/artistfilter.o

obj/yearfilter.o: $(FILTERS_DIR)YearFilter.cpp $(FILTERS_DIR)YearFilter.hpp
	$(CPP) -c $(FILTERS_DIR)YearFilter.cpp -o obj/yearfilter.o

obj/functions.o: main/functions.hpp main/functions.cpp
	$(CPP) -c main/functions.cpp -o obj/functions.o

clean:
	rm -r *.out
	rm -r obj/*.o
