# dspotify

A simple cpp music platform like Spotify

![Utunes](./utunes.png)

# Phase 1

In the phase 1, Users can work with the app using command line (CLI). The app reads the songs list from a csv file. Users after login/sign up can access the songs, filter them, and like the songs.

## CLI Commands

The format of commands in the CLI version of the app is like this:

```bash
POST/GET/DELETE <command> ? <options>
```
## Songs Data

Each songs is a row in the input csv file with these fields:
* id
* title
* artist
* release_year
* link

# Build

To build the project simply run these commands on terminal.

```bash
mkdir obj
make all
```

## Clean

To clean object files run this command:

```bash
make clean
```

# Usage

TO run the app after building, run this command:

```bash
./utunes.out <csv_file_relative_address>
```

# Commands

## signup

The command to sign up a user is:

```bash
POST signup ? email <email> username <username> password <password>
```

in case the email or username exist on the database, `Bad Request` would be the output, otherwise `OK`.

## login

The command to login a user is:

```bash
POST signup ? email <email> password <password>
```

in case the data was not correct, `Bad Request` would be the output, otherwise `OK`.

## logout

The command to logout a user is:

```bash
POST logout
```

in case no user logged in, `Permission Denied` would be the output, otherwise `OK`.




