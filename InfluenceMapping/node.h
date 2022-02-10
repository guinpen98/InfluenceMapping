#ifndef INFLUENCE_MAPPING_NODE_H
#define INFLUENCE_MAPPING_NODE_H
#include<vector>
#include"object.h"
#include"configuration.h"
namespace influenceMapping {
	enum NodeStatusE {
		NoneE
		, OpenE
		, ClosedE
	};

	class Node {
	private:
		NodeStatusE node_status = NoneE;
		double distance = 0.0;
	public:
		void setStatus(const NodeStatusE new_status);
		NodeStatusE getStatus() const;
		void setDistance(const double parent_distance);
		double getDistance()const;
	};

	void selectNode(const std::vector<std::vector<Node>>& node, int& select_node_x, int& select_node_y);
	void mobilizeOpenNode(const std::vector<std::vector<int>>& field, std::vector<std::vector<Node>>& node, const int& select_node_x, const int& select_node_y);
	void objectInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const Object object);
	void calculatingInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const std::vector<Object>& object, const Vec2& p_coord, std::vector<Agent>& agent);
	void playerInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const Vec2& p_coord);
	void agentInfluence(const std::vector<std::vector<int>>& field, std::vector<std::vector<double>>& influence_map, const std::vector<Agent>& agent);
}

#endif // !INFLUENCE_MAPPING_NODE_H
