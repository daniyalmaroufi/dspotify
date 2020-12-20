#ifndef __ARTISTFILTER__
#define __ARTISTFILTER__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/defines.hpp"
#include "../main/functions.hpp"
#include "./Filter.hpp"

class ArtistFilter : public Filter {
   public:
    ArtistFilter();
    void set(std::string rest_of_command);
    void reset();
    std::vector<Song*> apply_on(const std::vector<Song*>& songs);

   private:
    std::string name;
};

#endif
