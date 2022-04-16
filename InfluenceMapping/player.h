#ifndef INFLUENCE_MAPPING_PLAYER_H
#define INFLUENCE_MAPPING_PLAYER_H
#include"character.h"
#include"configuration.h"
namespace influenceMapping {
	enum PlayerState {
		stopE
		, walkE
		, actionE
	};
	class Player : public Character
	{
	private:
		PlayerState state = stopE;
	public:
		void setState(const enum PlayerState new_state);
		PlayerState getState()const;
		void inputProcess(CharacterDirection direction, field_matrix& field);
		void walk();
	};
}
#endif // !INFLUENCE_MAPPING_PLAYER_H