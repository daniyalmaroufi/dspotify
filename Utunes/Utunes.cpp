#include "./Utunes.hpp"

Utunes::Utunes() {
    loggedin_user = NULL;
    filters["artist"] = new ArtistFilter();
    filters["year"] = new YearFilter();
    filters["like"] = new LikeFilter();
}

Utunes::~Utunes() {
    for (auto song : songs) delete song;
    songs.clear();
    for (auto user : users) delete user;
    users.clear();
    for (auto playlist : playlists) delete playlist;
    playlists.clear();
    for (auto filter : filters) delete filter.second;
    filters.clear();
}

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
    } else if (command == "likes") {
        handle_like_a_song_command(rest_of_command);
    } else if (command == "playlists") {
        handle_create_playlist_command(rest_of_command);
    } else if (command == "playlists_songs") {
        handle_add_song_to_playlist_command(rest_of_command);
    } else if (command == "comments") {
        handle_add_comment_command(rest_of_command);
    } else if (command == "filters") {
        handle_set_filter_command(rest_of_command);
    } else {
        throw BadRequest();
    }
}

void Utunes::handle_set_filter_command(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    string command, temp_value;
    commandSS >> temp_value;
    commandSS >> command;
    getline(commandSS, rest_of_command);
    if (command == "artist") {
        filters["artist"]->set(rest_of_command);
        OK();
    } else if (command == "min_year") {
        filters["year"]->set(rest_of_command);
        OK();
    } else if (command == "min_like") {
        filters["like"]->set(rest_of_command);
        OK();
    } else {
        throw BadRequest();
    }
}

void Utunes::handle_add_comment_command(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    int song_id, time;
    string comment, temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> song_id;
    commandSS >> temp_value;
    commandSS >> time;
    commandSS >> temp_value;
    commandSS >> comment;

    for (auto song : songs)
        if (song->is_id(song_id)) {
            song->add_comment(time, loggedin_user->get_username(), comment);
            OK();
            return;
        }
    throw NotFound();
}

void Utunes::handle_add_song_to_playlist_command(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    int playlist_id, song_id;
    string temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> playlist_id;
    commandSS >> temp_value;
    commandSS >> song_id;
    add_song_to_playlist(playlist_id, song_id);
    OK();
}

void Utunes::add_song_to_playlist(int playlist_id, int song_id) {
    if (!playlists[playlist_id - 1]->is_owner(loggedin_user->get_username()))
        throw PermissionDenied();
    Song* the_song = NULL;
    for (auto song : songs)
        if (song->is_id(song_id)) the_song = song;

    if (!the_song) throw NotFound();

    playlists[playlist_id - 1]->add_song(the_song);
}

void Utunes::handle_create_playlist_command(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    string name, privacy, temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> name;
    commandSS >> temp_value;
    commandSS >> privacy;
    create_playlist(name, privacy);
}

void Utunes::create_playlist(string name, string privacy) {
    playlists.push_back(new Playlist(playlists.size() + 1, name,
                                     loggedin_user->get_username(), privacy));
    cout << playlists.size() << endl;
}

void Utunes::handle_like_a_song_command(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    string song_id, temp_value;
    commandSS >> temp_value;
    if (temp_value != "?") throw BadRequest();
    commandSS >> temp_value;
    commandSS >> song_id;

    Song* song = find_song(stoi(song_id));
    if (!song) throw NotFound();

    loggedin_user->like_song(song);
    OK();
}

Song* Utunes::find_song(int id) {
    for (auto song : songs)
        if (song->is_id(id)) return song;

    return NULL;
}

void Utunes::handle_logout_command() {
    needs_login();
    logout_user();
    OK();
}

void Utunes::needs_login() {
    if (loggedin_user == NULL) throw PermissionDenied();
}

void Utunes::logout_user() {
    reset_filters();
    loggedin_user = NULL;
}

void Utunes::handle_login_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string email, password, temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> email;
    commandSS >> temp_value;
    commandSS >> password;
    login_user(email, password);
    OK();
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
    commandSS >> temp_value;
    commandSS >> email;
    commandSS >> temp_value;
    commandSS >> username;
    commandSS >> temp_value;
    commandSS >> password;
    signup_user(username, email, password);
    OK();
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
    } else if (command == "likes") {
        handle_get_likes_command();
    } else if (command == "playlists") {
        handle_get_playlists_command(rest_of_command);
    } else if (command == "playlists_songs") {
        handle_get_playlist_songs_command(rest_of_command);
    } else if (command == "users") {
        handle_get_users_command(rest_of_command);
    } else if (command == "comments") {
        handle_get_comments_command(rest_of_command);
    } else {
        throw BadRequest();
    }
}

void Utunes::handle_get_comments_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    int song_id;
    string temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> song_id;

    for (auto song : songs)
        if (song->is_id(song_id)) {
            song->show_comments();
            return;
        }
    throw NotFound();
}

bool compare_users_by_name(User* first, User* second) {
    return first->compare_by_name_with(second);
}

std::vector<User*> sort_users_by_name(std::vector<User*> users) {
    sort(users.begin(), users.end(), compare_users_by_name);
    return users;
}

void Utunes::handle_get_users_command(string rest_of_command) {
    vector<User*> users_to_show;
    for (auto user : users)
        if (!user->is_username(loggedin_user->get_username())) {
            users_to_show.push_back(user);
        }
    if (users_to_show.size() == 0) throw Empty();
    for (auto user : sort_users_by_name(users_to_show))
        cout << user->get_username() << endl;
}

void Utunes::handle_get_playlist_songs_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    int playlist_id;
    string temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> playlist_id;

    if (!playlists[playlist_id - 1]->is_owner(loggedin_user->get_username()) &&
        !playlists[playlist_id - 1]->is_public())
        throw PermissionDenied();

    playlists[playlist_id - 1]->show_songs();
}

void Utunes::handle_get_playlists_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string ownername, temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> ownername;
    bool was_empty;
    if (loggedin_user->is_username(ownername))
        was_empty = show_all_playlists_of_user(ownername);
    else
        was_empty = show_public_playlists_of_user(ownername);
    if (was_empty) throw Empty();
}

bool Utunes::show_all_playlists_of_user(string ownername) {
    bool was_empty = true;
    for (auto playlist : playlists)
        if (playlist->is_owner(ownername)) {
            playlist->print_short_info();
            was_empty = false;
        }
    return was_empty;
}

bool Utunes::show_public_playlists_of_user(string ownername) {
    bool was_empty = true;
    for (auto playlist : playlists)
        if (playlist->is_owner(ownername) && playlist->is_public()) {
            playlist->print_short_info();
            was_empty = false;
        }
    return was_empty;
}

void Utunes::handle_get_likes_command() { loggedin_user->show_likes(); }

vector<Song*> Utunes::get_filtered_songs() {
    vector<Song*> filtered_songs = songs;
    for (auto filter : filters)
        filtered_songs = filter.second->apply_on(filtered_songs);
    return filtered_songs;
}

void Utunes::handle_get_songs_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string command;
    commandSS >> command;
    if (command == "?") {
        getline(commandSS, rest_of_command);
        handle_get_song_command(rest_of_command);
    } else {
        vector<Song*> filtered_songs = get_filtered_songs();
        if (filtered_songs.size() == 0) throw Empty();
        filtered_songs = sort_songs(filtered_songs);
        for (auto song : filtered_songs) song->print_short_info();
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
            return;
        }
    throw NotFound();
}

void Utunes::handle_delete_commands(string rest_of_command) {
    needs_login();
    stringstream commandSS(rest_of_command);
    string command;
    commandSS >> command;
    getline(commandSS, rest_of_command);
    if (command == "likes") {
        handle_delete_likes_command(rest_of_command);
    } else if (command == "playlists_songs") {
        handle_remove_song_from_list_command(rest_of_command);
    } else if (command == "filters") {
        reset_filters();
        OK();
    } else {
        throw BadRequest();
    }
}

void Utunes::reset_filters() {
    for (auto filter : filters) filter.second->reset();
}

void Utunes::handle_remove_song_from_list_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    int playlist_id, song_id;
    string temp_value;
    commandSS >> temp_value;
    commandSS >> temp_value;
    commandSS >> playlist_id;
    commandSS >> temp_value;
    commandSS >> song_id;
    if (!playlists[playlist_id - 1]->is_owner(loggedin_user->get_username()))
        throw PermissionDenied();
    playlists[playlist_id - 1]->remove_song(song_id);
    OK();
}

void Utunes::handle_delete_likes_command(string rest_of_command) {
    stringstream commandSS(rest_of_command);
    string song_id, temp_value;
    commandSS >> temp_value;
    if (temp_value != "?") throw BadRequest();
    commandSS >> temp_value;
    commandSS >> song_id;
    loggedin_user->remove_liked_song(stoi(song_id));
    OK();
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

void Utunes::read_liked_songs(string file_path) {
    ifstream CSVfile;
    CSVfile.open(file_path);
    string Line;
    getline(CSVfile, Line);
    while (getline(CSVfile, Line)) {
        vector<string> record;
        string cell_value;
        stringstream SStream(Line);
        while (getline(SStream, cell_value, ',')) record.push_back(cell_value);
        import_user(record[0], record[1], record[2], stoi(record[3]));
    }
    CSVfile.close();

    create_matrix();
}

void Utunes::import_user(string username, string email, string password,
                         int liked_song) {
    for (auto user : users)
        if (user->is_username(username)) {
            user->like_song(find_song(liked_song));
            return;
        }

    User* new_user = new User(username, email, hash_text(password));
    users.push_back(new_user);
    new_user->like_song(find_song(liked_song));
}

void Utunes::create_matrix() {
    for (int i = 0; i < users.size(); i++) {
        vector<int> user_likes;
        for (auto song : songs) user_likes.push_back(users[i]->do_likes(song));
        likes_matrix.push_back(user_likes);
    }

    for (auto userlike : likes_matrix) {
        for (auto like : userlike) cout << like << " ";
        cout << endl;
    }
}
