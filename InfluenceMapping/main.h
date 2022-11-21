#ifndef INFLUENCE_MAPPING_MAIN_H
#define INFLUENCE_MAPPING_MAIN_H
#include "mapchip.h"
#include "player.h"
#include "agent.h"

namespace influenceMapping {
	bool update();
	void main(Mapchip& mc, Player& player, std::vector<Agent>& agent);
}
#endif // !INFLUENCE_MAPPING_MAIN_H