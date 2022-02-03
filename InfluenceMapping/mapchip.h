#ifndef INFLUENCE_MAPPING_MAPCHIP_H
#define INFLUENCE_MAPPING_MAPCHIP_H
#include<array>

namespace influenceMapping {
	const int size_map_X = 16;  //< マップチップXサイズ
	const int size_map_Y = 16;	//< マップチップYサイズ
	const int num_m_chip_X = 8;  //< 横8種類
	const int num_m_chip_Y = 292;   //< 縦292種類
	const int num_m_chip_ALL = num_m_chip_X * num_m_chip_Y; //< 40個
	class Mapchip
	{
	private:
		std::array<int, num_m_chip_ALL> map_chip;
	public:
		void setMapchip(std::array<int, num_m_chip_ALL>& m_chip);
		std::array<int, num_m_chip_ALL> getMapchip();
	};
}

#endif // !INFLUENCE_MAPPING_MAPCHIP_H
