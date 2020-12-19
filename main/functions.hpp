#ifndef __FUNCTOINS__
#define __FUNCTOINS__

#include <algorithm>
#include <vector>
#include <iostream>

#include "../Song/Song.hpp"

bool compare_songs_by_id(Song* first, Song* second);
std::vector<Song*> sort_songs(std::vector<Song*> songs);
void OK();

#endif