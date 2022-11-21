#ifndef INFLUENCE_MAPPING_PLAYER_H
#define INFLUENCE_MAPPING_PLAYER_H
#include"character.h"
namespace influenceMapping {
	enum class PlayerState:int {
		stopE
		, walkE
		, actionE
	};
	class Player : public Character
	{
	private:
		PlayerState state = PlayerState::stopE;
	public:
		void setState(const PlayerState new_state);
		PlayerState getState()const;
		void inputProcess(CharacterDirection direction, field_matrix& field);
		void walk();
	};
}
#endif // !INFLUENCE_MAPPING_PLAYER_H