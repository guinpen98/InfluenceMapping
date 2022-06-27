#include "load_file.h"

namespace influenceMapping {
    void readMapFile(std::vector<std::vector<int>>& field) {
        std::ifstream ifs("influence_mapping.csv");
        std::string str;
        int i = 0;
        while (getline(ifs, str))
        {
            std::string token;
            std::istringstream stream(str);
            //1行のうち、文字列とコンマを分解する
            while (getline(stream, token, ','))
            {
                field[i / window_square_w][i % window_square_w] = std::stoi(token.c_str());
                i++;
            }
        }
    }
}