#include <iostream>

#include "../Utunes/Utunes.hpp"
#include "./defines.hpp"

using namespace std;

int main() {
    Utunes utunes;
    utunes.handle_input();
    cout << "Hello World." << endl;
    return 0;
}