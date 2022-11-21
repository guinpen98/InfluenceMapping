#ifndef INFLUENCE_MAPPING_OBJECT_H
#define INFLUENCE_MAPPING_OBJECT_H
#include"agent.h"
namespace influenceMapping {
	constexpr int obj_num = 5;
	class Object {
	private:
		Vec2 coord = Vec2(10, 1);
	public:
		void setCoord(const Vec2 new_coord);
		Vec2 getCoord()const;
	};
	void objectAdd(const field_matrix& field, std::vector<Object>& object,const std::vector<Agent>& agent);
	bool closeToAgent(const std::vector<Agent>& agent, const Vec2 new_coord);
	void objectDelete(std::vector<Object>& object,const std::vector<Agent>& agent);
}

#endif // !INFLUENCE_MAPPING_OBJECT_H

