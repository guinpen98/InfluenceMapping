#include "object.h"
#include<random>

namespace influenceMapping {
	void Object::setCoord(const Vec2 new_coord) {
		coord = new_coord;
	}
	Vec2 Object::getCoord()const {
		return coord;
	}
	void objectAdd(const field_matrix& field, std::vector<Object>& object, const std::vector<Agent>& agent) {
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> w_distr(1, window_square_w - 2);
		std::uniform_int_distribution<int> h_distr(1, window_square_h - 2);
		int x = w_distr(eng), y = h_distr(eng);
		while (field[y][x] == 1 || closeToAgent(agent,Vec2(x,y))) {
			x = w_distr(eng), y = h_distr(eng);
		}
		object.emplace_back();
		object.back().setCoord(Vec2(x, y));
	}
	bool closeToAgent(const std::vector<Agent>& agent,const Vec2 new_coord) {
		for (int i = 0; i < agent_num; i++)
			if (agent[i].getNextCoord().distance(new_coord) < 25) return true;
		return false;
	}
	void objectDelete(std::vector<Object>& object, const std::vector<Agent>& agent) {
		for (int i = 0; i < object.size(); i++)
			for (int j = 0; j < agent_num; j++) {
				Vec2 a_coord = agent[j].getCurrentCoord();
				if (object[i].getCoord().isEqual(a_coord)) {
					object.erase(object.begin() + i);
					break;
				}
			}
	}
}