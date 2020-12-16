#include "./Utunes.hpp"

Utunes::Utunes() {}

void Utunes::handle_input() {
    string command;
    while (cin >> command) {
        if(command=="POST"){
            handle_post_commands();
        } else if(command=="GET"){
            handle_get_commands();
        }else if(command=="DELETE"){
            handle_delete_commands();
        }
    }
}
