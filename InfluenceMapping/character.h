#ifndef INFLUENCE_MAPPING_CHARACTER_H
#define INFLUENCE_MAPPING_CHARACTER_H
#include "vector.h"

namespace influenceMapping {
	enum class CharacterDirection :int {
		directionDownE
		, directionUpE
		, directionRightE
		, directionLeftE
	};

	const int size_character_X = 32;  //< キャラクターチップXサイズ
	const int size_character_Y = 32;	//< キャラクターチップYサイズ
	const int num_c_chip_X = 3;  //< 横3種類
	const int num_c_chip_Y = 4;   //< 縦4種類
	const int num_c_chip_ALL = num_c_chip_X * num_c_chip_Y; //< 40個

	class Character
	{
	private:
		Vec2 current_coord = Vec2(1.0, 1.0);
		Vec2 interim_coord = Vec2(1.0, 1.0);
		Vec2 next_coord = Vec2(1.0, 1.0);
		int walk_cnt = 0;
		CharacterDirection direction = CharacterDirection::directionDownE;
		std::vector<int> character_chip;
	public:
		void setCharacterchip(std::vector<int>& c_chip);
		std::vector<int> getCharacterchip();
		void setCurrentCoord(const Vec2 coord);
		Vec2 getCurrentCoord()const;
		void setNextCoord(const Vec2 coord);
		Vec2 getNextCoord()const;
		void setInterimCoord(const Vec2 coord);
		void resetInterimCoord(const Vec2 coord);
		Vec2 getInterimCoord()const;
		void resetCoord(const Vec2 c_coord, const Vec2 i_coord, const Vec2 n_coord);
		void setWalkCnt(const int new_cnt);
		int getWalkCnt()const;
		void setDirection(const CharacterDirection new_direction);
		CharacterDirection getDirection()const;
	};
}

#endif // !INFLUENCE_MAPPING_CHARACTER_H