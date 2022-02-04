#include "mapchip.h"
namespace influenceMapping {
	void Mapchip::setMapchip(const std::vector<int>& m_chip) {
		map_chip = m_chip;
	}
	std::vector<int> Mapchip::getMapchip()const {
		return map_chip;
	}
}