#include "./LikeFilter.hpp"

LikeFilter::LikeFilter() { reset(); };

void LikeFilter::set(std::string rest_of_command) {
    std::stringstream commandSS(rest_of_command);
    std::string temp_value;
    int min_like_, max_like_;
    commandSS >> min_like_;
    commandSS >> temp_value;
    commandSS >> max_like_;
    if (temp_value != "max_like" || max_like_ < min_like_ || min_like_ < 0 ||
        max_like_ < 0)
        throw BadRequest();
    min_like = min_like_;
    max_like = max_like_;
}

void LikeFilter::reset() {
    min_like = 0;
    max_like = 0;
}

std::vector<Song*> LikeFilter::apply_on(const std::vector<Song*>& songs) {
    if (min_like == 0 || max_like == 0) return songs;
    std::vector<Song*> filtered_songs;
    for (auto song : songs) {
        if (song->is_like_between(min_like, max_like))
            filtered_songs.push_back(song);
    }
    return filtered_songs;
}
