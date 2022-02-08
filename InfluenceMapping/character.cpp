#include "character.h"

namespace influenceMapping {
	void Character::setCharacterchip(std::vector<int>& m_chip) {
		character_chip = m_chip;
	}
	std::vector<int> Character::getCharacterchip() {
		return character_chip;
	}
	void Character::setCurrentCoord(const Vec2 coord) {
		current_coord = coord;
	}

	Vec2 Character::getCurrentCoord()const {
		return current_coord;
	}

	void Character::setNextCoord(const Vec2 d_coord) {
		next_coord = current_coord + d_coord;
	}

	Vec2 Character::getNextCoord()const {
		return next_coord;
	}

	void Character::setInterimCoord(const Vec2 d_coord) {
		interim_coord = interim_coord + d_coord;
	}

	void Character::resetInterimCoord(const Vec2 coord) {
		interim_coord = coord;
	}

	Vec2 Character::getInterimCoord()const {
		return interim_coord;
	}
	void Character::resetCoord(const Vec2 c_coord, const Vec2 i_coord, const Vec2 n_coord) {
		current_coord = c_coord;
		interim_coord = i_coord;
		next_coord = n_coord;
	}
	void Character::setWalkCnt(const int new_cnt) {
		walk_cnt = new_cnt;
	}
	int Character::getWalkCnt()const {
		return walk_cnt;
	}
	void Character::setDirection(const enum CharacterDirection new_direction) {
		direction = new_direction;
	}
	CharacterDirection Character::getDirection()const {
		return direction;
	}

}