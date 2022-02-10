#include "agent.h"
namespace influenceMapping {
	void Agent::setState(const enum AgentState new_state) {
		state = new_state;
	}
	AgentState Agent::getState()const {
		return state;
	}
	void Agent::setNumber(const int new_num) {
		number = new_num;
	}
	int Agent::getNumber()const {
		return number;
	}
	void Agent::walk() {
		if (getCurrentCoord().isEqual(getNextCoord())) {
			setState(agentStopE);
			return;
		}
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
			setState(AgentState::agentStopE);
		}
		setWalkCnt(w_cnt);
	}
	void Agent::pathSearch(const std::vector<std::vector<int>>& field, const std::vector<std::vector<double>>& influence_map) {
		double max_influence = -1;
		Vec2 coord = getCurrentCoord();
		Vec2 n_coord = Vec2(coord.x, coord.y - 1);
		CharacterDirection new_direction = directionUpE;
		if (field[int(coord.y) - 1][int(coord.x)] == 0) {
			if (influence_map[int(coord.y) - 1][int(coord.x)] > max_influence) {
				max_influence = influence_map[int(coord.y) - 1][int(coord.x)];
			}
		}
		if (field[int(coord.y) + 1][int(coord.x)] == 0) {
			if (influence_map[int(coord.y) + 1][int(coord.x)] > max_influence) {
				new_direction = directionDownE;
				max_influence = influence_map[int(coord.y) + 1][int(coord.x)];
				n_coord = Vec2(coord.x,coord.y + 1);
			}
			else if (influence_map[int(coord.y) + 1][int(coord.x)] == max_influence)
				if (isReturn(new_direction) || n_coord.centerDistance() > Vec2(coord.x, coord.y + 1).centerDistance()) {
					new_direction = directionDownE;
					max_influence = influence_map[int(coord.y) + 1][int(coord.x)];
					n_coord = Vec2(coord.x, coord.y + 1);
				}
		}

		if (field[int(coord.y)][int(coord.x) - 1] == 0) {
			if (influence_map[int(coord.y)][int(coord.x) - 1] > max_influence) {
				new_direction = directionLeftE;
				max_influence = influence_map[int(coord.y)][int(coord.x) - 1];
				n_coord = Vec2(coord.x - 1, coord.y);
			}
			else if (influence_map[int(coord.y)][int(coord.x) - 1] == max_influence)
				if (isReturn(new_direction) || n_coord.centerDistance() > Vec2(coord.x - 1, coord.y).centerDistance()) {
					new_direction = directionLeftE;
					max_influence = influence_map[int(coord.y)][int(coord.x) - 1];
					n_coord = Vec2(coord.x - 1, coord.y);
				}
		}
		if (field[int(coord.y)][int(coord.x) + 1] == 0) {
			if (influence_map[int(coord.y)][int(coord.x) + 1] > max_influence) {
				new_direction = directionRightE;
				max_influence = influence_map[int(coord.y)][int(coord.x) + 1];
			}
			else if (influence_map[int(coord.y)][int(coord.x) + 1] == max_influence)
				if (isReturn(new_direction) || n_coord.centerDistance() > Vec2(coord.x + 1, coord.y).centerDistance()) {
					new_direction = directionRightE;
					max_influence = influence_map[int(coord.y)][int(coord.x) + 1];
				}
		}
		setDirection(new_direction);
	}
	void Agent::behavior(const std::vector<std::vector<int>>& field, const std::vector<std::vector<double>>& influence_map, std::vector<Agent>& agent) {
		stop_count++;
		if (stop_count > 0) {
			setState(agentWalkE);
			pathSearch(field,influence_map);
			Vec2 tmp_coord = getCurrentCoord();
			int other_num = getNumber() == 0 ? 1 : 0;
			Vec2 other_c_coord = agent[other_num].getCurrentCoord();
			Vec2 other_n_coord = agent[other_num].getNextCoord();
			switch (getDirection())
			{
			case directionDownE:
				if (tmp_coord.y >= window_square_h) return;
				if (field[int(tmp_coord.y) + 1][int(tmp_coord.x)] == 1) return;
				if (other_c_coord.isEqual(Vec2(tmp_coord.x, tmp_coord.y+1))) return;
				if (other_n_coord.isEqual(Vec2(tmp_coord.x, tmp_coord.y+1))) return;
				//if (influence_map[int(tmp_coord.y) + 1][int(tmp_coord.x)] == influence_map[int(tmp_coord.y)][int(tmp_coord.x)]) return;
				setNextCoord(Vec2(0.0, 1.0));
				break;
			case directionUpE:
				if (tmp_coord.y <= 0.0) return;
				if (field[int(tmp_coord.y) - 1][int(tmp_coord.x)] == 1) return;
				if (other_c_coord.isEqual(Vec2(tmp_coord.x, tmp_coord.y-1))) return;
				if (other_n_coord.isEqual(Vec2(tmp_coord.x, tmp_coord.y-1))) return;
				//if (influence_map[int(tmp_coord.y) - 1][int(tmp_coord.x)] == influence_map[int(tmp_coord.y)][int(tmp_coord.x)]) return;
				setNextCoord(Vec2(0.0, -1.0));
				break;
			case directionRightE:
				if (tmp_coord.x >= window_square_w) return;
				if (field[int(tmp_coord.y)][int(tmp_coord.x) + 1] == 1) return;
				if (other_c_coord.isEqual(Vec2(tmp_coord.x+1, tmp_coord.y))) return;
				if (other_n_coord.isEqual(Vec2(tmp_coord.x+1, tmp_coord.y))) return;
				//if (influence_map[int(tmp_coord.y)][int(tmp_coord.x) + 1] == influence_map[int(tmp_coord.y)][int(tmp_coord.x)]) return;
				setNextCoord(Vec2(1.0, 0.0));
				break;
			case directionLeftE:
				if (tmp_coord.x <= 0.0) return;
				if (field[int(tmp_coord.y)][int(tmp_coord.x) - 1] == 1) return;
				if (other_c_coord.isEqual(Vec2(tmp_coord.x-1, tmp_coord.y))) return;
				if (other_n_coord.isEqual(Vec2(tmp_coord.x-1, tmp_coord.y))) return;
				//if (influence_map[int(tmp_coord.y)][int(tmp_coord.x) - 1] == influence_map[int(tmp_coord.y)][int(tmp_coord.x)]) return;
				setNextCoord(Vec2(-1.0, 0.0));
				break;
			default:
				break;
			}
			stop_count = 0;
		}
	}
	bool Agent::isReturn(const CharacterDirection n_d) {
		CharacterDirection d = getDirection();
		return ((d == directionUpE && n_d == directionDownE) || (d == directionDownE && n_d == directionUpE) || (d == directionRightE && n_d == directionLeftE) || (d == directionRightE && n_d == directionLeftE));
	}

}
