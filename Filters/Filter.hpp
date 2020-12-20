#ifndef __FILTER__
#define __FILTER__

#include <iostream>
#include <string>
#include <vector>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/defines.hpp"
#include "../main/functions.hpp"

class Filter {
   public:
    Filter(){};
    virtual void set(std::string rest_of_command) = 0;
    virtual void reset() = 0;
    virtual std::vector<Song*> apply_on(const std::vector<Song*>& songs) = 0;

   private:
};

#endif
