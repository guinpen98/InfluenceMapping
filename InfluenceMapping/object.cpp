#include "object.h"

namespace influenceMapping {
	void Object::setCoord(const Vec2 new_coord) {
		coord = new_coord;
	}
	Vec2 Object::getCoord()const {
		return coord;
	}
	void objectAdd(const std::vector<std::vector<int>>& field, std::vector<Object>& object, const Agent& agent) {
		std::random_device rd;
		std::default_random_engine eng(rd());
		std::uniform_int_distribution<int> w_distr(1, window_square_w - 2);
		std::uniform_int_distribution<int> h_distr(1, window_square_h - 2);
		int x = w_distr(eng), y = h_distr(eng);
		while (field[y][x] == 1 || agent.getNextCoord().distance(Vec2(x, y)) < 50) {
			x = w_distr(eng), y = h_distr(eng);
		}
		object.emplace_back();
		object.back().setCoord(Vec2(x, y));
	}
}