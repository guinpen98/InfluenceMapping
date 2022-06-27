#ifndef INFLUENCE_MAPPING_MAPCHIP_H
#define INFLUENCE_MAPPING_MAPCHIP_H
#include<vector>

namespace influenceMapping {
	const int size_map_X = 16;  //< マップチップXサイズ
	const int size_map_Y = 16;	//< マップチップYサイズ
	const int num_m_chip_X = 8;  //< 横8種類
	const int num_m_chip_Y = 292;   //< 縦292種類
	const int num_m_chip_ALL = num_m_chip_X * num_m_chip_Y; //< 40個
	class Mapchip
	{
	private:
		std::vector<int> map_chip;
	public:
		void setMapchip(const std::vector<int>& m_chip);
		std::vector<int> getMapchip()const;
	};
}

#endif // !INFLUENCE_MAPPING_MAPCHIP_H
