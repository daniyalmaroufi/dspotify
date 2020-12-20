#include "./ArtistFilter.hpp"

ArtistFilter::ArtistFilter() { name = ""; };

void ArtistFilter::set(std::string rest_of_command) {
    std::stringstream commandSS(rest_of_command);
    std::string temp_value, name_;
    commandSS >> name_;
    while (commandSS >> temp_value) name_ = name_ + " " + temp_value;
    name = name_;
}

void ArtistFilter::reset() { name = ""; }

std::vector<Song*> ArtistFilter::apply_on(const std::vector<Song*>& songs) {
    if (name == "") return songs;
    std::vector<Song*> filtered_songs;
    for (auto song : songs) {
        if (song->is_artist(name)) filtered_songs.push_back(song);
    }
    return filtered_songs;
}
