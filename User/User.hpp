#ifndef __USER__
#define __USER__

#include <string>

class User {
   public:
    User(std::string username_, std::string email_, std::string password_);
    User(){};
    bool is_username(std::string username_);
    bool is_email(std::string email_);

   private:
    std::string username;
    std::string email;
    std::string password;
};

#endif
