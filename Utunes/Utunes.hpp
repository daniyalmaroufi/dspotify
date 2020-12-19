#ifndef __UTUNES__
#define __UTUNES__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

#include "./Exceptions.hpp"
#include "../Song/Song.hpp"

using namespace std;

class Utunes {
   public:
    Utunes();
    void handle_input();
    void handle_post_commands(string rest_of_command);
    void handle_get_commands(string rest_of_command);
    void handle_delete_commands(string rest_of_command);
    void read_songs(string file_path);

   private:
   vector<Song*> songs;
};

#endif