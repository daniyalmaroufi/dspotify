#ifndef __USER__
#define __USER__

#include <string>

class User {
   public:
    User(std::string username_, std::string email_, int password_);
    User(){};

   private:
    std::string username;
    std::string email;
    std::string password;
};

#endif
