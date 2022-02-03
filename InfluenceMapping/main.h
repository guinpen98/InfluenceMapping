#ifndef INFLUENCE_MAPPING_MAIN_H
#define INFLUENCE_MAPPING_MAIN_H
#include<random>
#include <fstream>
#include <sstream>
#include"player.h"
#include"draw.h"


namespace influenceMapping {
	bool update();
	void readMapFile(std::vector<std::vector<int>>& field);
	void main(Player player);
}
#endif // !INFLUENCE_MAPPING_MAIN_H