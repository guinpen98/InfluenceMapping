#ifndef INFLUENCE_MAPPING_VECTOR_H
#define INFLUENCE_MAPPING_VECTOR_H
#include"configuration.h"

namespace influenceMapping {
	struct Vec2
	{
		double x = 0, y = 0;

		constexpr Vec2() = default;

		constexpr Vec2(const double ix, const double iy)
			:x(ix), y(iy) {}

		constexpr double distance(const Vec2& coord)const {
			return ((x - coord.x) * (x - coord.x) + (y - coord.y) * (y - coord.y));
		}
		constexpr double centerDistance()const {
			return ((x - (window_square_w / 2 - 0.5)) * (x - (window_square_w / 2 - 0.5)) + (y - (window_square_w / 2)) * (window_square_w / 2));
		}

		constexpr bool isEqual(const Vec2& coord) const {
			return (x == coord.x && y == coord.y);
		}

		constexpr Vec2 operator+(const Vec2& coord)const {
			return Vec2(x + coord.x, y + coord.y);
		}
		constexpr Vec2 operator/(const double n)const {
			return Vec2(x / n, y / n);
		}
	};
	constexpr Vec2 right_coord = Vec2{ 1.0, 0.0 };
	constexpr Vec2 left_coord = Vec2{ -1.0, 0.0 };
	constexpr Vec2 down_coord = Vec2{ 0.0, 1.0 };
	constexpr Vec2 up_coord = Vec2{ 0.0, -1.0 };
}

#endif // !INFLUENCE_MAPPING_VECTOR_H

