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
		switch (direction)
		{
		case directionDownE:
			if (tmp_coord.y >= window_square_w) return;
			if (field[int(tmp_coord.y) + 1][int(tmp_coord.x)] == 1) return;
			setNextCoord(Vec2(0.0, 1.0));
			break;
		case directionUpE:
			if (tmp_coord.y <= 0.0) return;
			if (field[int(tmp_coord.y) - 1][int(tmp_coord.x)] == 1) return;
			setNextCoord(Vec2(0.0, -1.0));
			break;
		case directionRightE:
			if (tmp_coord.x >= window_square_w) return;
			if (field[int(tmp_coord.y)][int(tmp_coord.x) + 1] == 1) return;
			setNextCoord(Vec2(1.0, 0.0));
			break;
		case directionLeftE:
			if (tmp_coord.x <= 0.0) return;
			if (field[int(tmp_coord.y)][int(tmp_coord.x) - 1] == 1) return;
			setNextCoord(Vec2(-1.0, 0.0));
			break;
		default:
			break;
		}
		setState(PlayerState::walkE);
	}
	void Player::walk() {
		switch (getDirection())
		{
		case directionDownE:
			setInterimCoord(Vec2(0.0, 1.0 / walk_fps));
			break;
		case directionUpE:
			setInterimCoord(Vec2(0.0, -1.0 / walk_fps));
			break;
		case directionRightE:
			setInterimCoord(Vec2(1.0 / walk_fps, 0.0));
			break;
		case directionLeftE:
			setInterimCoord(Vec2(-1.0 / walk_fps, 0.0));
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