#ifndef INFLUENCE_MAPPING_DRAW_H
#define INFLUENCE_MAPPING_DRAW_H
#include "object.h"

namespace influenceMapping {
	void drawMap(field_matrix& field, class Mapchip& mc);
	void drawInfluenceRate(std::vector<std::vector<double>>& influence_map);
	void drawObject(std::vector<Object>& object, Mapchip& mc);
	void drawPlayer(class Player& player);
	void drawAgent(std::vector<Agent>& agent);
}
#endif // !INFLUENCE_MAPPING_DRAW_H