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
