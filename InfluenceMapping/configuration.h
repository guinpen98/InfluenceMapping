
#ifndef INFLUENCE_MAPPING_CONFIGURATION_H
#define INFLUENCE_MAPPING_CONFIGURATION_H
#include<vector>

constexpr int square_size = 64;

constexpr int window_square_w = 20;
constexpr int window_square_h = 15;

constexpr int window_w = square_size * window_square_w;
constexpr int window_h = square_size * window_square_h;

using field_array = std::vector<int>;
using field_matrix = std::vector<field_array>;

#endif // !INFLUENCE_MAPPING_CONFIGURATION_H
