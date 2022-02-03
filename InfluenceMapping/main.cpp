#include "main.h"

namespace influenceMapping {
    bool update() { return (DxLib::ScreenFlip() != -1 && DxLib::ClearDrawScreen() != -1 && DxLib::ProcessMessage() != -1); }

    void readMapFile(vector<vector<int>>& field) {
        ifstream ifs("influence_mapping.csv");
        string str;
        int i = 0;
        while (getline(ifs, str))
        {
            string token;
            istringstream stream(str);
            //1行のうち、文字列とコンマを分解する
            while (getline(stream, token, ','))
            {
                field[i / window_square_w][i % window_square_w] = stoi(token.c_str());
                i++;
            }
        }
    }

    void main(Mapchip mc, Player player) {
        //地形の二次元配列
        vector<vector<int>> field(window_square_h, vector<int>(window_square_w));
        //地形ファイルの読み込み
        readMapFile(field);
        //key入力
        char key_state[256];
        while (update()) {
            if (player.getState() == PlayerState::stopE) {
                GetHitKeyStateAll(key_state);
                if (key_state[KEY_INPUT_A] || key_state[KEY_INPUT_LEFT]) player.inputProcess(directionLeftE, field);
                else if (key_state[KEY_INPUT_D] || key_state[KEY_INPUT_RIGHT]) player.inputProcess(directionRightE, field);
                else if (key_state[KEY_INPUT_W] || key_state[KEY_INPUT_UP]) player.inputProcess(directionUpE, field);
                else if (key_state[KEY_INPUT_S] || key_state[KEY_INPUT_DOWN]) player.inputProcess(directionDownE, field);
            }
            if (player.getState() == PlayerState::walkE) player.walk();

            std::vector<std::vector<Node>> node(window_square_h, vector<Node>(window_square_w));
            Vec2 p_coord = player.getNextCoord();
            dijkstra(field, node, int(p_coord.x), int(p_coord.y));

            drawMap(field, mc);
            drawInfluenceRate(node);
            drawPlayer(player);
        }
    }
}