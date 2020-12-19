#ifndef __PLAYLIST__
#define __PLAYLIST__

#include <iostream>
#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/defines.hpp"
#include "../main/functions.hpp"

class Playlist {
   public:
    Playlist(int id_, std::string name_, std::string ownername_,
             std::string privacy_);
    Playlist(){};
    bool is_owner(std::string username);
    bool is_public();
    void print_short_info();

   private:
    int id;
    std::string name;
    std::string ownername;
    std::string privacy;
    std::vector<Song*> songs;
};

#endif
