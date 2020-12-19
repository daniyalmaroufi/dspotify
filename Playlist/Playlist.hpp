#ifndef __PLAYLIST__
#define __PLAYLIST__

#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/functions.hpp"

class Playlist {
   public:
    Playlist(int id_, std::string name_, bool is_public_);
    Playlist(){};

   private:
    int id;
    std::string name;
    bool is_public;
    std::vector<Song*> songs;
};

#endif
