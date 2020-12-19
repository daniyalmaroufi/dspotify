#include "./Playlist.hpp"

Playlist::Playlist(int id_, std::string name_, std::string ownername_,
                   std::string privacy_) {
    id = id_;
    name = name_;
    ownername = ownername_;
    privacy = privacy_;
}

bool Playlist::is_owner(std::string username) { return ownername == username; }

void Playlist::print_short_info() {
    std::cout << id << " " << name << " " << privacy << std::endl;
}

bool Playlist::is_public() { return privacy == PUBLIC_PLAYLIST; }

void Playlist::add_song(Song* the_song) { songs.push_back(the_song); }

void Playlist::show_songs() {
    if (songs.size() == 0) throw Empty();
    for (auto song : songs) song->print_short_info();
}
