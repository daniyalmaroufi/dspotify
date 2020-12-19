#include "./User.hpp"

User::User(std::string username_, std::string email_, std::string password_) {
    username = username_;
    email = email_;
    password = password_;
}

bool User::is_username(std::string username_) { return username == username_; }
bool User::is_email(std::string email_) { return email == email_; }
bool User::is_password(std::string password_) { return password == password_; }
void User::like_song(Song* song) {
    for(auto liked_song:liked_songs){
        if(liked_song->is_the_same(song)){
            throw BadRequest();
        }
    }
    song->like();
    liked_songs.push_back(song);
}
