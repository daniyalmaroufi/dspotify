#ifndef __SONG__
#define __SONG__

#include <string>

class Song {
   public:
    Song(int id_, std::string title_, std::string artist_, int release_year_,
           std::string link_);
    Song(){};

   private:
    int id;
    std::string title;
    std::string artist;
    int release_year;
    std::string link;
};

#endif