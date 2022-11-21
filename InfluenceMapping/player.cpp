#include "player.h"
#include "property.h"

namespace influenceMapping {
	void Player::setState(const PlayerState new_state) {
		state = new_state;
	}
	PlayerState Player::getState()const {
		return state;
	}

	void Player::inputProcess(CharacterDirection direction, field_matrix& field) {
		Vec2 tmp_coord = getCurrentCoord();
		setDirection(direction);
		Vec2 next_coord;
		switch (direction)
		{
		case CharacterDirection::directionDownE:
			if (tmp_coord.y >= window_square_h - 1) return;
			next_coord = down_coord;
			break;
		case CharacterDirection::directionUpE:
			if (tmp_coord.y <= 0.0) return;
			next_coord = up_coord;
			break;
		case CharacterDirection::directionRightE:
			if (tmp_coord.x >= window_square_w - 1) return;
			next_coord = right_coord;
			break;
		case CharacterDirection::directionLeftE:
			if (tmp_coord.x <= 0.0) return;
			next_coord = left_coord;
			break;
		default:
			break;
		}
		if (field[int(tmp_coord.y + next_coord.y)][int(tmp_coord.x + next_coord.x)] == 1) return;
		setNextCoord(next_coord);
		setState(PlayerState::walkE);
	}
	void Player::walk() {
		switch (getDirection())
		{
		case CharacterDirection::directionDownE:
			setInterimCoord(down_coord / walk_fps);
			break;
		case CharacterDirection::directionUpE:
			setInterimCoord(up_coord / walk_fps);
			break;
		case CharacterDirection::directionRightE:
			setInterimCoord(right_coord / walk_fps);
			break;
		case CharacterDirection::directionLeftE:
			setInterimCoord(left_coord / walk_fps);
			break;
		default:
			break;
		}
		int w_cnt = getWalkCnt() + 1;
		if (w_cnt == walk_fps) {
			w_cnt = 0;
			resetInterimCoord(getNextCoord());
			setCurrentCoord(getNextCoord());
			setState(PlayerState::stopE);
		}
		setWalkCnt(w_cnt);
	}
}