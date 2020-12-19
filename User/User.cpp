#include "./User.hpp"

User::User(std::string username_, std::string email_, std::string password_) {
    username = username_;
    email = email_;
    password = password_;
}

bool User::is_username(std::string username_) { return username == username_; }
bool User::is_email(std::string email_) { return email == email_; }