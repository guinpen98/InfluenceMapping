#ifndef INFLUENCE_MAPPING_AGENT_H
#define INFLUENCE_MAPPING_AGENT_H
#include"character.h"
namespace influenceMapping {
	enum AgentState {
		agentStopE
		, agentWalkE
	};
	constexpr int agent_num = 2;
	class Agent : public Character
	{
	private:
		AgentState state = agentStopE;
		int stop_count = 0;
	public:
		void setState(const enum AgentState new_state);
		AgentState getState()const;
		void walk();
		void pathSearch(const std::vector<std::vector<int>>& field, const std::vector<std::vector<double>>& influence_map);
		void behavior(const std::vector<std::vector<int>>& field,const std::vector<std::vector<double>>& influence_map);
		bool isReturn(const CharacterDirection new_direction);
	};
}
#endif // !INFLUENCE_MAPPING_AGENT_H