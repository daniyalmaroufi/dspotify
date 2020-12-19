#ifndef __EXCEPTIONS__
#define __EXCEPTIONS__

#include <exception>

class BadRequest : public std::exception {
public:
    const char* what() const noexcept {
        return "Bad Request\n";
    }
};

class PermissionDenied : public std::exception {
public:
    const char* what() const noexcept {
        return "Permission Denied\n";
    }
};

#endif