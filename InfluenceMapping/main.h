#ifndef INFLUENCE_MAPPING_MAIN_H
#define INFLUENCE_MAPPING_MAIN_H
#include<random>
#include"draw.h"
#include"load_file.h"

namespace influenceMapping {
	bool update();
<<<<<<< HEAD
=======
	void readMapFile(field_matrix& field);
>>>>>>> f457fe5d24c9f7c07aa75d9adae9955cf46615d0
	void main(Mapchip& mc,Player& player, std::vector<Agent>& agent);
}
#endif // !INFLUENCE_MAPPING_MAIN_H