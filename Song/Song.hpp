#ifndef __SONG__
#define __SONG__

#include <iostream>
#include <string>

class Song {
   public:
    Song(int id_, std::string title_, std::string artist_, int release_year_,
         std::string link_);
    Song(){};
    bool compare_by_id_with(Song* second);
    void print_short_info();
    bool is_id(int id_);
    bool is_the_same(Song* second);
    void print_full_info();
    void like();

   private:
    int id;
    std::string title;
    std::string artist;
    int release_year;
    std::string link;
    int num_of_likes;
    int num_of_comments;
    int num_of_playlists;
};

#endif