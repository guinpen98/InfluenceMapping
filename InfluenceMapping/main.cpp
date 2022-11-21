#include "main.h"
#include"node.h"
#include"load_file.h"
#include"draw.h"
#include<DxLib.h>

namespace influenceMapping {
    bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

    void main(Mapchip& mc, Player& player, std::vector<Agent>& agent) {
        //地形の二次元配列
        field_matrix field(window_square_h, std::vector<int>(window_square_w));
        //地形ファイルの読み込み
        readMapFile(field);
        //Objectの配列
        std::vector<Object> object;
        //key入力
        char key_state[256];
        //agentの初期位置設定
        agent[0].resetCoord(Vec2(8,1), Vec2(8, 1), Vec2(8, 1));
        agent[1].resetCoord(Vec2(1,8), Vec2(1, 8), Vec2(1, 8));
        agent[2].resetCoord(Vec2(18,13), Vec2(18, 13), Vec2(18, 13));
        //agentの番号をセット
        for (int i = 0; i < agent_num; i++)
            agent[i].setNumber(i);
        while (update()) {
            if (object.size() < obj_num) objectAdd(field,object,agent);
            objectDelete(object,agent);
            if (player.getState() == PlayerState::stopE) {
                GetHitKeyStateAll(key_state);
                if (key_state[KEY_INPUT_A] || key_state[KEY_INPUT_LEFT]) player.inputProcess(CharacterDirection::directionLeftE, field);
                else if (key_state[KEY_INPUT_D] || key_state[KEY_INPUT_RIGHT]) player.inputProcess(CharacterDirection::directionRightE, field);
                else if (key_state[KEY_INPUT_W] || key_state[KEY_INPUT_UP]) player.inputProcess(CharacterDirection::directionUpE, field);
                else if (key_state[KEY_INPUT_S] || key_state[KEY_INPUT_DOWN]) player.inputProcess(CharacterDirection::directionDownE, field);
            }
            if (player.getState() == PlayerState::walkE) player.walk();

            influence_matrix influence_map(window_square_h, influence_array(window_square_w,0.0));
            calculatingInfluence(field, influence_map, object, player.getNextCoord(),agent);
            for (int i = 0; i < agent_num; i++) {
                if (agent[i].getState() == AgentState::agentStopE) agent[i].behavior(field, influence_map,agent);
                if (agent[i].getState() == AgentState::agentWalkE) agent[i].walk();
            }

            drawMap(field, mc);
            //drawInfluenceRate(influence_map);
            drawObject(object,mc);
            drawAgent(agent);
            drawPlayer(player);
        }
    }
}