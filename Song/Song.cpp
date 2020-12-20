#include "./Song.hpp"

Song::Song(int id_, std::string title_, std::string artist_, int release_year_,
           std::string link_) {
    id = id_;
    title = title_;
    artist = artist_;
    release_year = release_year_;
    link = link_;
    num_of_likes = 0;
    num_of_playlists = 0;
}

bool Song::compare_by_id_with(Song* second) { return id < second->id; }

void Song::print_short_info() {
    std::cout << id << " " << title << " " << artist << " " << release_year
              << std::endl;
}

bool Song::is_id(int id_) { return id == id_; }

void Song::print_full_info() {
    std::cout << id << std::endl;
    std::cout << title << std::endl;
    std::cout << artist << std::endl;
    std::cout << release_year << std::endl;
    std::cout << "#likes: " << num_of_likes << std::endl;
    std::cout << "#comments: " << comments.size() << std::endl;
    std::cout << "#playlists: " << num_of_playlists << std::endl;
}

bool Song::is_artist(std::string name) { return artist == name; }

bool Song::is_the_same(Song* second) { return id == second->id; }

void Song::like() { num_of_likes += 1; }

void Song::added_to_playlist() { num_of_playlists += 1; }

void Song::removed_to_playlist() { num_of_playlists -= 1; }

void Song::add_comment(int time, std::string username, std::string text) {
    comment new_comment;
    new_comment.time = time;
    new_comment.username = username;
    new_comment.text = text;
    comments.push_back(new_comment);
}

bool compare_comments_by_username(const comment& first, const comment& second) {
    return first.username < second.username;
}

bool compare_comments_by_time(const comment& first, const comment& second) {
    return first.time < second.time;
}

std::vector<comment> sort_comments_by_username(std::vector<comment> comments) {
    sort(comments.begin(), comments.end(), compare_comments_by_username);
    return comments;
}

std::vector<comment> sort_comments_by_time(std::vector<comment> comments) {
    sort(comments.begin(), comments.end(), compare_comments_by_time);
    return comments;
}

void Song::show_comments() {
    if (comments.size() == 0) throw Empty();
    comments = sort_comments_by_username(comments);
    comments = sort_comments_by_time(comments);
    for (auto the_comment : comments)
        std::cout << the_comment.time << " " << the_comment.username << ": "
                  << the_comment.text << std::endl;
}

bool Song::is_year_between(int min_year, int max_year) {
    return release_year >= min_year && release_year <= max_year;
}

bool Song::is_like_between(int min_like, int max_like) {
    return num_of_likes >= min_like && num_of_likes <= max_like;
}
