#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

class NoUser : public std::exception {
public:
    const char* what() {
        return "User not joined\n";
    }
};

class NoGame : public std::exception {
public:
    const char* what() {
        return "No game created\n";
    }
};

class NoRole : public std::exception {
public:
    const char* what() {
        return "One or more players do not have a role\n";
    }
};

class GameStarted : public std::exception {
public:
    const char* what() {
        return "Game has already started\n";
    }
};

class SilentVoter : public std::exception {
public:
    const char* what() {
        return "Voter is silenced\n";
    }
};

class DeadVotee : public std::exception {
public:
    const char* what() {
        return "Votee already dead\n";
    }
};

class CannotWakeup : public std::exception {
public:
    const char* what() {
        return "User can not wake up during night\n";
    }
};

class DeadUser : public std::exception {
public:
    const char* what() {
        return "User is dead\n";
    }
};

class DetectiveAsked : public std::exception {
public:
    const char* what() {
        return "Detective has already asked\n";
    }
};

class DeadSuspect : public std::exception {
public:
    const char* what() {
        return "Suspect is dead\n";
    }
};

class DoctorHealed : public std::exception {
public:
    const char* what() {
        return "Doctor has already healed\n";
    }
};

class DeadPatient : public std::exception {
public:
    const char* what() {
        return "Patient is dead\n";
    }
};

class DeadPerson : public std::exception {
public:
    const char* what() {
        return "Person is dead\n";
    }
};

class Swapped : public std::exception {
public:
    const char* what() {
        return "Characters already swapped\n";
    }
};

class NightSwap : public std::exception {
public:
    const char* what() {
        return "Can't swap before end of night\n";
    }
};

class DaySwap : public std::exception {
public:
    const char* what() {
        return "Voting in progress\n";
    }
};

#endif