#ifndef __SONG__
#define __SONG__

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#include "../main/Exceptions.hpp"

struct comment {
    int time;
    std::string username;
    std::string text;
};

class Song {
   public:
    Song(int id_, std::string title_, std::string artist_, int release_year_,
         std::string link_);
    Song(){};
    bool compare_by_id_with(Song* second);
    void print_short_info();
    bool is_id(int id_);
    bool is_the_same(Song* second);
    bool is_artist(std::string name);
    void print_full_info();
    void like();
    void added_to_playlist();
    void removed_to_playlist();
    void add_comment(int time, std::string username, std::string text);
    void show_comments();

   private:
    int id;
    std::string title;
    std::string artist;
    int release_year;
    std::string link;
    int num_of_likes;
    int num_of_playlists;
    std::vector<comment> comments;
};

#endif