#ifndef INFLUENCE_MAPPING_MAIN_H
#define INFLUENCE_MAPPING_MAIN_H
#include<random>
#include <fstream>
#include <sstream>
#include"draw.h"

using namespace std;

namespace influenceMapping {
	bool update();
	void readMapFile(vector<vector<int>>& field);
	void main(Mapchip mc,Player player,Agent agent);
}
#endif // !INFLUENCE_MAPPING_MAIN_H