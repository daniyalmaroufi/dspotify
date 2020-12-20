#ifndef __YEARFILTER__
#define __YEARFILTER__

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "../Song/Song.hpp"
#include "../main/Exceptions.hpp"
#include "../main/defines.hpp"
#include "../main/functions.hpp"
#include "./Filter.hpp"

class YearFilter : public Filter {
   public:
    YearFilter();
    void set(std::string rest_of_command);
    void reset();
    std::vector<Song*> apply_on(const std::vector<Song*>& songs);

   private:
    int min_year;
    int max_year;
};

#endif
