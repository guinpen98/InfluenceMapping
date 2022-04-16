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
			pathSearch(field,influence_map);
			Vec2 tmp_coord = getCurrentCoord();
			Vec2 next_coord = Vec2(0.0, 0.0);
			int other_num = getNumber() == 0 ? 1 : 0;
			switch (getDirection())
			{
			case directionDownE:
				if (tmp_coord.y >= window_square_h) return;
				next_coord = down_coord;
				break;
			case directionUpE:
				if (tmp_coord.y <= 0.0) return;
				next_coord = up_coord;
				break;
			case directionRightE:
				if (tmp_coord.x >= window_square_w) return;
				next_coord = right_coord;
				break;
			case directionLeftE:
				if (tmp_coord.x <= 0.0) return;
				next_coord = left_coord;
				break;
			default:
				break;
			}
			if (field[int(tmp_coord.y)][int(tmp_coord.x)] == 1) return;
			if (isSameCoord(agent, tmp_coord + next_coord)) return;
			setNextCoord(next_coord);
			setState(agentWalkE);
			stop_count = 0;
		}
	}
	bool Agent::isSameCoord(const std::vector<Agent>& agent,const Vec2 next_coord) {
		for (int i = 0; i < agent_num; i++) {
			if (getNumber() == i) continue;
			if (agent[i].getCurrentCoord().isEqual(next_coord)) return true;
			if (agent[i].getNextCoord().isEqual(next_coord)) return true;
		}
		return false;
	}
	bool Agent::isReturn(const CharacterDirection n_d) {
		CharacterDirection d = getDirection();
		return ((d == directionUpE && n_d == directionDownE) || (d == directionDownE && n_d == directionUpE) || (d == directionRightE && n_d == directionLeftE) || (d == directionRightE && n_d == directionLeftE));
	}

}
