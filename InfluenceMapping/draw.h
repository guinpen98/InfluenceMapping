#ifndef INFLUENCE_MAPPING_DRAW_H
#define INFLUENCE_MAPPING_DRAW_H
#include"mapchip.h"
#include"node.h"
#include"player.h"
#include"object.h"
#include<DxLib.h>

namespace influenceMapping {
	void drawMap(std::vector<std::vector<int>>& field, Mapchip& mc);
	void drawInfluenceRate(std::vector<std::vector<double>>& influence_map);
	void drawObject(std::vector<Object>& object, Mapchip& mc);
	void drawPlayer(Player& player);
	void drawAgent(Agent& agent);
}
#endif // !INFLUENCE_MAPPING_DRAW_H