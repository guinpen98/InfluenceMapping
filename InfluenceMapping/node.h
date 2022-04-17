#ifndef INFLUENCE_MAPPING_NODE_H
#define INFLUENCE_MAPPING_NODE_H
#include<vector>
#include"object.h"
#include"configuration.h"
namespace influenceMapping {
	constexpr double displacement_influence = 0.1;

	
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

	using node_array = std::vector<Node>;
	using node_matrix = std::vector<node_array>;

	void selectNode(const node_matrix& node, int& select_node_x, int& select_node_y);
	void mobilizeOpenNode(const field_matrix& field, node_matrix& node, const int& select_node_x, const int& select_node_y);
	void openNode(const field_matrix& field, node_matrix& node, const int& open_node_x, const int& open_node_y,const double p_distance);
	void objectInfluence(const field_matrix& field, influence_matrix& influence_map, const Object object);
	void calculatingInfluence(const field_matrix& field, influence_matrix& influence_map, const std::vector<Object>& object, const Vec2& p_coord, std::vector<Agent>& agent);
	void playerInfluence(const field_matrix& field, influence_matrix& influence_map, const Vec2& p_coord);
	void agentInfluence(const field_matrix& field, influence_matrix& influence_map, const std::vector<Agent>& agent);
}

#endif // !INFLUENCE_MAPPING_NODE_H
