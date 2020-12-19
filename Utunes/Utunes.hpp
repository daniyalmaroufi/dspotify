#ifndef __UTUNES__
#define __UTUNES__

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../User/User.hpp"
#include "../main/Exceptions.hpp"

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
    string hash_text(string password);
    void handle_login_command(string rest_of_command);
    void login_user(string email, string password);
    void handle_logout_command();
    void needs_login();
    void logout_user();
    void handle_get_songs_command(string rest_of_command);
    void handle_get_song_command(string rest_of_command);
    vector<Song*> sort_songs();
    void handle_like_a_song_command(string rest_of_command);

   private:
    vector<Song*> songs;
    vector<User*> users;
    User* loggedin_user;
};

#endif