#ifndef INFLUENCE_MAPPING_MAIN_H
#define INFLUENCE_MAPPING_MAIN_H
#include<random>
#include"draw.h"
#include"load_file.h"

namespace influenceMapping {
	bool update();
	void main(Mapchip& mc,Player& player, std::vector<Agent>& agent);
}
#endif // !INFLUENCE_MAPPING_MAIN_H