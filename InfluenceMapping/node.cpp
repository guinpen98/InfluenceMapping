#include "node.h"

namespace influenceMapping {
	void Node::setStatus(const NodeStatusE new_status) {
		node_status = new_status;
	}
	NodeStatusE Node::getStatus() const {
		return node_status;
	}
	void Node::setDistance(const double parent_distance) {
		distance = parent_distance - displacement_influence;
	}
	double Node::getDistance()const {
		return distance;
	}
	void selectNode(const std::vector<std::vector<Node>>& node, int& select_node_x, int& select_node_y) {
		double max_distance = -1.0;
		for (int y = 0; y < node.size(); y++) {
			for (int x = 0; x < node[y].size(); x++) {
				//ステータスがOpen以外のノードを除外
				if (node[y][x].getStatus() != OpenE) continue;
				double distance = node[y][x].getDistance();
				//距離が最大値未満のものを除外
				if (distance < max_distance) continue;
				//最大値の更新
				max_distance = distance;
				select_node_x = x;
				select_node_y = y;
			}
		}
	}
	void mobilizeOpenNode(const std::vector<std::vector<int>>& field, std::vector<std::vector<Node>>& node, const int& select_node_x, const int& select_node_y) {
		double p_distance = node[select_node_y][select_node_x].getDistance();
		if (select_node_x > 0) openNode(field,node, select_node_x - 1, select_node_y,p_distance);
		if (select_node_x < window_square_w - 1)openNode(field, node, select_node_x + 1, select_node_y, p_distance);
		if (select_node_y > 0) openNode(field, node, select_node_x, select_node_y - 1, p_distance);
		if (select_node_y < window_square_h - 1) openNode(field, node, select_node_x, select_node_y + 1, p_distance);
	}
	void openNode(const std::vector<std::vector<int>>& field, std::vector<std::vector<Node>>& node, const int& open_node_x, const int& open_node_y,const double p_distance) {
		if (field[open_node_y][open_node_x] != 0) return;
		if (node[open_node_y][open_node_x].getStatus() != NoneE) return;
		node[open_node_y][open_node_x].setStatus(OpenE);
		node[open_node_y][open_node_x].setDistance(p_distance);
	}
	void objectInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const Object object) {
		int o_x = int(object.getCoord().x), o_y = int(object.getCoord().y);
		std::vector<std::vector<Node>> node(window_square_h, std::vector<Node>(window_square_w));
		//オブジェクトの位置のノードをOpenにして、距離を設定する
		node[o_y][o_x].setStatus(OpenE);
		node[o_y][o_x].setDistance(1.0 + displacement_influence);
		while (node[o_y][o_x].getDistance() >= displacement_influence && node[o_y][o_x].getStatus() == OpenE) {
			mobilizeOpenNode(field, node, o_x, o_y);
			node[o_y][o_x].setStatus(ClosedE);
			selectNode(node, o_x, o_y);
		}
		for (int y = 0; y < window_square_h; y++)
			for (int x = 0; x < window_square_w; x++)
				if (influence_map[y][x] < node[y][x].getDistance()) influence_map[y][x] = node[y][x].getDistance();

	}
	void calculatingInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const std::vector<Object>& object, const Vec2& p_coord, std::vector<Agent>& agent) {
		for (int i = 0; i < object.size(); i++)
			objectInfluence(field, influence_map, object[i]);

		playerInfluence(field, influence_map, p_coord);
		agentInfluence(field,influence_map,agent);
	}
	void playerInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const Vec2& p_coord) {
		int p_x = int(p_coord.x), p_y = int(p_coord.y);
		std::vector<std::vector<Node>> node(window_square_h, std::vector<Node>(window_square_w));
		//プレイヤーの位置のノードをOpenにして、距離を設定する
		node[p_y][p_x].setStatus(OpenE);
		node[p_y][p_x].setDistance(1.0 + displacement_influence);
		while (node[p_y][p_x].getDistance() >= displacement_influence && node[p_y][p_x].getStatus() == OpenE) {
			mobilizeOpenNode(field, node, p_x, p_y);
			node[p_y][p_x].setStatus(ClosedE);
			selectNode(node, p_x, p_y);
		}
		for (int y = 0; y < window_square_h; y++)
			for (int x = 0; x < window_square_w; x++)
				influence_map[y][x] = influence_map[y][x] * 0.3 + (1.0 - node[y][x].getDistance()) * 0.4;
	}
	void agentInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const std::vector<Agent>& agent){
		//std::vector<std::vector<double>> temp_map(window_square_h, std::vector<double>(window_square_w, 1.0));
		for (int i = 0; i < agent_num; i++) {
			int a_x = int(agent[i].getNextCoord().x), a_y = int(agent[i].getNextCoord().y);
			std::vector<std::vector<Node>> node(window_square_h, std::vector<Node>(window_square_w));
			//オブジェクトの位置のノードをOpenにして、距離を設定する
			node[a_y][a_x].setStatus(OpenE);
			node[a_y][a_x].setDistance(1.0 + displacement_influence);
			while (node[a_y][a_x].getDistance() >= displacement_influence && node[a_y][a_x].getStatus() == OpenE) {
				mobilizeOpenNode(field, node, a_x, a_y);
				node[a_y][a_x].setStatus(ClosedE);
				selectNode(node, a_x, a_y);
			}
			for (int y = 0; y < window_square_h; y++)
				for (int x = 0; x < window_square_w; x++)
					influence_map[y][x] += (1.0 - node[y][x].getDistance()) * 0.15;
		}
	}
}