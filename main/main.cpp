#include <iostream>

#include "../Utunes/Utunes.hpp"
#include "./defines.hpp"

using namespace std;

int main(int argc, char* argv[]) {
    Utunes utunes;
    utunes.read_songs(argv[1]);
    utunes.handle_input();
    return 0;
}