#ifndef __SONG__
#define __SONG__

#include <string>
#include <iostream>

class Song {
   public:
    Song(int id_, std::string title_, std::string artist_, int release_year_,
         std::string link_);
    Song(){};
    bool compare_by_id_with(Song* second);
    void print_info();

   private:
    int id;
    std::string title;
    std::string artist;
    int release_year;
    std::string link;
};

#endif