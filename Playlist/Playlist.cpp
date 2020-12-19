#include "./Playlist.hpp"

Playlist::Playlist(int id_, std::string name_, std::string ownername_,
                   std::string privacy_) {
    id = id_;
    name = name_;
    ownername = ownername_;
    privacy = privacy_;
}

bool Playlist::is_owner(std::string username) {
    return ownername == username;
}

void Playlist::print_short_info() {
    std::cout << id << " " << name << " " << privacy << std::endl;
}

bool Playlist::is_public() { return privacy == PUBLIC_PLAYLIST; }
