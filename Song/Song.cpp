#include "./Song.hpp"

Song::Song(int id_, std::string title_, std::string artist_, int release_year_,
           std::string link_) {
    id = id_;
    title = title_;
    artist = artist_;
    release_year = release_year_;
    link = link_;
}