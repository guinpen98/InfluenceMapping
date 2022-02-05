#include "node.h"

namespace influenceMapping {
	void Node::setStatus(const NodeStatusE new_status) {
		node_status = new_status;
	}
	NodeStatusE Node::getStatus() const {
		return node_status;
	}
	void Node::setDistance(const double parent_distance) {
		distance = parent_distance + 0.1;
	}
	double Node::getDistance()const {
		return distance;
	}
	void selectNode(const std::vector<std::vector<Node>>& node, int& select_node_x, int& select_node_y) {
		double min_distance = 2;
		for (int y = 0; y < node.size(); y++) {
			for (int x = 0; x < node[y].size(); x++) {
				//ステータスがOpen以外のノードを除外
				if (node[y][x].getStatus() != OpenE) continue;
				double distance = node[y][x].getDistance();
				//距離が最大値未満のものを除外
				if (distance > min_distance) continue;
				//最大値の更新
				min_distance = distance;
				select_node_x = x;
				select_node_y = y;
			}
		}
	}
	void mobilizeOpenNode(const std::vector<std::vector<int>>& field, std::vector<std::vector<Node>>& node, const int& select_node_x, const int& select_node_y) {
		double p_distance = node[select_node_y][select_node_x].getDistance();
		if (select_node_x > 0)
			if (field[select_node_y][select_node_x - 1] == 0) {
				if (node[select_node_y][select_node_x - 1].getStatus() == NoneE) {
					node[select_node_y][select_node_x - 1].setStatus(OpenE);
					node[select_node_y][select_node_x - 1].setDistance(p_distance);
				}
			}
		if (select_node_x < window_square_w - 1)
			if (field[select_node_y][select_node_x + 1] == 0) {
				if (node[select_node_y][select_node_x + 1].getStatus() == NoneE) {
					node[select_node_y][select_node_x + 1].setStatus(OpenE);
					node[select_node_y][select_node_x + 1].setDistance(p_distance);
				}
			}
		if (select_node_y > 0)
			if (field[select_node_y - 1][select_node_x] == 0) {
				if (node[select_node_y - 1][select_node_x].getStatus() == NoneE) {
					node[select_node_y - 1][select_node_x].setStatus(OpenE);
					node[select_node_y - 1][select_node_x].setDistance(p_distance);
				}
			}
		if (select_node_y < window_square_h - 1)
			if (field[select_node_y + 1][select_node_x] == 0) {
				if (node[select_node_y + 1][select_node_x].getStatus() == NoneE) {
					node[select_node_y + 1][select_node_x].setStatus(OpenE);
					node[select_node_y + 1][select_node_x].setDistance(p_distance);
				}
			}
	}
	void dijkstra(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, int select_node_x, int select_node_y) {
		std::vector<std::vector<Node>> node(window_square_h, std::vector<Node>(window_square_w));
		//アクターの位置のノードをOpenにして、距離を設定する
		node[select_node_y][select_node_x].setStatus(OpenE);
		node[select_node_y][select_node_x].setDistance(-0.1);
		while (node[select_node_y][select_node_x].getDistance() <= 0.9) {
			mobilizeOpenNode(field, node, select_node_x, select_node_y);
			node[select_node_y][select_node_x].setStatus(ClosedE);
			selectNode(node, select_node_x, select_node_y);
		}
		for (int y = 0; y < window_square_h; y++)
			for (int x = 0; x < window_square_w; x++)
				influence_map[y][x] = node[y][x].getDistance();
	}
}