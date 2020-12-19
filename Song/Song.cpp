#include "./Song.hpp"

Song::Song(int id_, std::string title_, std::string artist_, int release_year_,
           std::string link_) {
    id = id_;
    title = title_;
    artist = artist_;
    release_year = release_year_;
    link = link_;
}

bool Song::compare_by_id_with(Song* second) { return id < second->id; }

void Song::print_info() {
    std::cout << id << " " << title << " " << artist << " " << release_year
              << std::endl;
}
