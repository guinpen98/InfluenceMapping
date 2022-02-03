#ifndef INFLUENCE_MAPPING_DRAW_H
#define INFLUENCE_MAPPING_DRAW_H
#include"vector.h"
#include"configuration.h"
#include"mapchip.h"
#include"player.h"
//#include"npc.h"
#include<DxLib.h>

namespace influenceMapping {
	void drawMap(std::vector<std::vector<int>>& field, Mapchip mc);
	void drawPlayer(Player player);
	//void drawNPC(life::NPC npc, Vec2 camera_coord);
}
#endif // !INFLUENCE_MAPPING_DRAW_H