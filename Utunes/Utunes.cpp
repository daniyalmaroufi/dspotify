#include "./Utunes.hpp"

Utunes::Utunes() { loggedin_user = NULL; }

void Utunes::handle_input() {
    string command;
    while (getline(cin, command)) {
        try {
            stringstream commandSS(command);
            string command_type, rest_of_command;
            commandSS >> command_type;
            getline(commandSS, rest_of_command);
            if (command_type == "POST") {
                handle_post_commands(rest_of_command);
            } else if (command_type == "GET") {
                handle_get_commands(rest_of_command);
            } else if (command_type == "DELETE") {
                handle_delete_commands(rest_of_command);
            } else {
                throw BadRequest();
            }
        } catch (exception& ex) {
            cout << ex.what();
        }
    }
}
void Utunes::handle_post_commands(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string command;
    commandSS >> command;
    getline(commandSS, rest_of_command);
    if (command == "signup") {
        handle_signup_command(rest_of_command);
    } else if (command == "login") {
        handle_login_command(rest_of_command);
    } else if (command == "logout") {
        handle_logout_command();
    } else {
        throw BadRequest();
    }
}
void Utunes::handle_logout_command() {
    needs_login();
    logout_user();
    cout << "OK" << endl;
}

void Utunes::needs_login() {
    if (loggedin_user == NULL) throw PermissionDenied();
}

void Utunes::logout_user() { loggedin_user = NULL; }

void Utunes::handle_login_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string email, password, temp_value;
    commandSS >> temp_value;
    commandSS >> email;
    commandSS >> temp_value;
    commandSS >> password;
    login_user(email, password);
    cout << "OK" << endl;
}

void Utunes::login_user(string email, string password) {
    for (auto user : users)
        if (user->is_email(email) && user->is_password(hash_text(password))) {
            loggedin_user = user;
            return;
        }
    throw BadRequest();
}

void Utunes::handle_signup_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string username, email, password, temp_value;
    commandSS >> temp_value;
    commandSS >> email;
    commandSS >> temp_value;
    commandSS >> username;
    commandSS >> temp_value;
    commandSS >> password;
    signup_user(username, email, password);
    cout << "OK" << endl;
}

void Utunes::signup_user(string username, string email, string password) {
    for (auto user : users)
        if (user->is_username(username) || user->is_email(email))
            throw BadRequest();
    User* new_user = new User(username, email, hash_text(password));
    users.push_back(new_user);
    loggedin_user = new_user;
}

string Utunes::hash_text(string password) {
    std::hash<std::string> hash;
    return to_string(hash(password));
}

void Utunes::handle_get_commands(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    string command;
    commandSS >> command;
    getline(commandSS, rest_of_command);
    if (command == "songs") {
        handle_get_songs_command(rest_of_command);
    } else {
        throw BadRequest();
    }
}

void Utunes::handle_get_songs_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string command;
    commandSS >> command;
    if (command == "?") {
        getline(commandSS, rest_of_command);
        handle_get_song_command(rest_of_command);
    } else if (command == "") {
        if (songs.size() == 0) throw Empty();
        vector<Song*> sorted_songs = sort_songs();
        for (auto song : sorted_songs) song->print_short_info();
    }
}

void Utunes::handle_get_song_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string song_id, temp_value;
    commandSS >> temp_value;
    commandSS >> song_id;

    for (auto song : songs)
        if (song->is_id(stoi(song_id))) {
            song->print_full_info();
        }
}

bool compare_songs_by_id(Song* first, Song* second) {
    return first->compare_by_id_with(second);
}

vector<Song*> Utunes::sort_songs() {
    vector<Song*> sorted_songs = songs;
    sort(songs.begin(), songs.end(), compare_songs_by_id);
    return sorted_songs;
}

void Utunes::handle_delete_commands(string rest_of_command) {
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
    CSVfile.close();
}
