#ifndef __UTUNES__
#define __UTUNES__

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../User/User.hpp"
#include "./Exceptions.hpp"

using namespace std;

class Utunes {
   public:
    Utunes();
    void read_songs(string file_path);
    void handle_input();
    void handle_post_commands(string rest_of_command);
    void handle_get_commands(string rest_of_command);
    void handle_delete_commands(string rest_of_command);
    void handle_signup_command(string rest_of_command);
    void signup_user(string username, string email, string password);

   private:
    vector<Song*> songs;
    vector<User*> users;
};

#endif