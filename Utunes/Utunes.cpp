#include "./Utunes.hpp"

Utunes::Utunes() {}

void Utunes::handle_input() {
    string command;
    while (cin >> command) {
        if (command == "POST") {
            handle_post_commands();
        } else if (command == "GET") {
            handle_get_commands();
        } else if (command == "DELETE") {
            handle_delete_commands();
        }
    }
}
void Utunes::handle_post_commands() {
    // do something
}
void Utunes::handle_get_commands() {
    // do something
}
void Utunes::handle_delete_commands() {
    // do something
}

void Utunes::read_songs(string file_path) {
    ifstream CSVfile;
    CSVfile.open(file_path);
    string Line;
    getline(CSVfile, Line);
    while (getline(CSVfile, Line)) {
        vector<string> record;
        string cell_value;
        stringstream SStream(Line);
        while (getline(SStream, cell_value, ',')) record.push_back(cell_value);
        songs.push_back(new Song(stoi(record[0]), record[1], record[2],
                                 stoi(record[3]), record[4]));
    }
}
