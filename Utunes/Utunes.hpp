#ifndef __UTUNES__
#define __UTUNES__

#include <iostream>
#include <string>

using namespace std;

class Utunes {
   public:
    Utunes();
    void handle_input();
    void handle_post_commands();
    void handle_get_commands();
    void handle_delete_commands();

   private:
};

#endif