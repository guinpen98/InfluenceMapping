#ifndef INFLUENCE_LOAD_FILE_H
#define INFLUENCE_LOAD_FILE_H
#include <fstream>
#include <sstream>
#include<vector>
#include"configuration.h"

namespace influenceMapping {
	void readMapFile(std::vector<std::vector<int>>& field);
}
#endif // !INFLUENCE_LOAD_FILE_H