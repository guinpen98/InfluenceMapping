#include "mapchip.h"
namespace influenceMapping {
	void Mapchip::setMapchip(std::array<int, num_m_chip_ALL>& m_chip) {
		map_chip = m_chip;
	}
	std::array<int, num_m_chip_ALL> Mapchip::getMapchip() {
		return map_chip;
	}
}