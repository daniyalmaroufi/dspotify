#include "./YearFilter.hpp"

YearFilter::YearFilter() { reset(); };

void YearFilter::set(std::string rest_of_command) {
    std::stringstream commandSS(rest_of_command);
    std::string temp_value;
    int min_year_, max_year_;
    commandSS >> min_year_;
    commandSS >> temp_value;
    commandSS >> max_year_;
    if (temp_value != "max_year" || max_year_ < min_year_) throw BadRequest();
    min_year = min_year_;
    max_year = max_year_;
}

void YearFilter::reset() {
    min_year = 0;
    max_year = 0;
}

std::vector<Song*> YearFilter::apply_on(const std::vector<Song*>& songs) {
    if (min_year == 0 || max_year == 0) return songs;
    std::vector<Song*> filtered_songs;
    for (auto song : songs) {
        if (song->is_year_between(min_year, max_year))
            filtered_songs.push_back(song);
    }
    return filtered_songs;
}
