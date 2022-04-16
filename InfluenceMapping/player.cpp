#include "player.h"
namespace influenceMapping {
	void Player::setState(const enum PlayerState new_state) {
		state = new_state;
	}
	PlayerState Player::getState()const {
		return state;
	}

	void Player::inputProcess(CharacterDirection direction, std::vector<std::vector<int>>& field) {
		Vec2 tmp_coord = getCurrentCoord();
		setDirection(direction);
		Vec2 next_coord;
		switch (direction)
		{
		case directionDownE:
			if (tmp_coord.y >= window_square_h - 1) return;
			next_coord = down_coord;
			break;
		case directionUpE:
			if (tmp_coord.y <= 0.0) return;
			next_coord = up_coord;
			break;
		case directionRightE:
			if (tmp_coord.x >= window_square_w - 1) return;
			next_coord = right_coord;
			break;
		case directionLeftE:
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
		case directionDownE:
			setInterimCoord(down_coord / walk_fps);
			break;
		case directionUpE:
			setInterimCoord(up_coord / walk_fps);
			break;
		case directionRightE:
			setInterimCoord(right_coord / walk_fps);
			break;
		case directionLeftE:
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