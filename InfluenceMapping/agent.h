﻿#ifndef INFLUENCE_MAPPING_AGENT_H
#define INFLUENCE_MAPPING_AGENT_H
#include"character.h"
namespace influenceMapping {
	enum class AgentState {
		agentStopE
		, agentWalkE
	};
	constexpr int agent_num = 3;
	class Agent : public Character
	{
	private:
		AgentState state = AgentState::agentStopE;
		int stop_count = 0;
		int number = 0;
	public:
		void setState(const enum AgentState new_state);
		AgentState getState()const;
		void setNumber(const int new_num);
		int getNumber()const;
		void walk();
		void pathSearch(const field_matrix& field, const influence_matrix& influence_map);
		void behavior(const field_matrix& field,const influence_matrix& influence_map, std::vector<Agent>& agent);
		bool isSameCoord(const std::vector<Agent>& agent, const Vec2 next_coord);
		bool isReturn(const CharacterDirection new_direction);
	};
}
#endif // !INFLUENCE_MAPPING_AGENT_H