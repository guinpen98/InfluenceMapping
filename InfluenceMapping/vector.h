#ifndef INFLUENCE_MAPPING_VECTOR_H
#define INFLUENCE_MAPPING_VECTOR_H
#include"configuration.h"

namespace influenceMapping {
	struct Vec2
	{
		double x = 0, y = 0;

		Vec2() = default;

		Vec2(const double ix, const double iy)
			:x(ix), y(iy) {}

		double distance(const Vec2& coord)const {
			return ((x - coord.x) * (x - coord.x) + (y - coord.y) * (y - coord.y));
		}
		double centerDistance()const {
			return ((x - (window_square_w / 2 - 0.5)) * (x - (window_square_w / 2 - 0.5)) + (y - (window_square_w / 2)) * (window_square_w / 2));
		}

		bool isEqual(const Vec2& coord) const {
			return (x == coord.x && y == coord.y);
		}

		Vec2 operator+(const Vec2& coord)const {
			return Vec2(x + coord.x, y + coord.y);
		}
	};

}

#endif // !INFLUENCE_MAPPING_VECTOR_H

