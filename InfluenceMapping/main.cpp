#include "main.h"

using namespace std;

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

    void main(Player player) {
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

            for (int y = 0; y < window_square_h; y++)
                for (int x = 0; x < window_square_w; x++) {
                    unsigned int cr = GetColor(0, 0, 0);
                    switch (field[y][x])
                    {
                    case 1:
                        cr = GetColor(0, 100, 25);
                        break;
                    case 0:
                        cr = GetColor(0, 150, 50);
                        break;
                    default:
                        break;
                    }
                    DrawBox(x* square_size, y* square_size, (x + 1)* square_size, (y + 1)* square_size, cr, TRUE);
                }
            drawPlayer(player);
        }
    }
}