#include "./functions.hpp"

bool compare_songs_by_id(Song* first, Song* second) {
    return first->compare_by_id_with(second);
}

std::vector<Song*> sort_songs(std::vector<Song*> songs) {
    sort(songs.begin(), songs.end(), compare_songs_by_id);
    return songs;
}

void OK() { std::cout << "OK" << std::endl; }
