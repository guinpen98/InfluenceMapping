#include "draw.h"

namespace influenceMapping {
    void drawMap(field_matrix& field, Mapchip& mc) {
        for (int y = 0; y < window_square_h; y++) {
            for (int x = 0; x < window_square_w; x++) {
                DrawExtendGraph(x * square_size,y * square_size,(x + 1) * square_size,(y + 1) * square_size, mc.getMapchip()[33], TRUE);
                switch (field[y][x])
                {
                case 1:
                    DrawExtendGraph(x  * square_size, y * square_size, (x + 1) * square_size, (y + 1) * square_size, mc.getMapchip()[81], TRUE);
                    break;
                case 0:
                    break;
                default:
                    break;
                }
            }
        }
    }
    void drawInfluenceRate(std::vector<std::vector<double>>& influence_map) {
        for (int y = 0; y < window_square_h; y++)
            for (int x = 0; x < window_square_w; x++) {
                DrawBox(x * square_size, y * square_size, (x + 1) * square_size, (y + 1) * square_size, GetColor(int(255 * (1 - influence_map[y][x])), 0, int(255 * influence_map[y][x])), TRUE);
            }
    }
    void drawObject(std::vector<Object>& object, Mapchip& mc) {
        for (int i = 0; i < object.size(); i++) {
            Vec2 coord = object[i].getCoord();
            DrawExtendGraph(int((coord.x) * square_size), int((coord.y) * square_size), int((coord.x + 1) * square_size), int((coord.y + 1) * square_size), mc.getMapchip()[95], TRUE);
        }
    }
    void drawPlayer(Player& player) {
        Vec2 pc_coord = player.getInterimCoord();
        std::vector<int> player_chip = player.getCharacterchip();
        int graph_num = 0;
        switch (player.getDirection())
        {
        case directionUpE:
            graph_num = 9;
            break;
            break;
        case directionLeftE:
            graph_num = 3;
            break;
        case directionRightE:
            graph_num = 6;
            break;
        default:
            break;
        }
        int cnt = player.getWalkCnt();
        if ((cnt >= 0 && cnt <= walk_fps / 4) || (cnt >= walk_fps / 2 + 1 && cnt <= walk_fps / 4 * 3)) graph_num++;
        if (cnt >= walk_fps / 4 * 3 + 1 && cnt <= walk_fps) graph_num += 2;
        DrawExtendGraph(int((pc_coord.x) * square_size), int((pc_coord.y) * square_size), int((pc_coord.x + 1) * square_size), int((pc_coord.y + 1) * square_size), player_chip[graph_num], TRUE);
    }
    void drawAgent(std::vector<Agent>& agent) {
        std::vector<int> agent_chip = agent[0].getCharacterchip();
        for (int i = 0; i < agent_num; i++) {
            Vec2 pc_coord = agent[i].getInterimCoord();
            int graph_num = 0;
            switch (agent[i].getDirection())
            {
            case directionUpE:
                graph_num = 9;
                break;
                break;
            case directionLeftE:
                graph_num = 3;
                break;
            case directionRightE:
                graph_num = 6;
                break;
            default:
                break;
            }
            int cnt = agent[i].getWalkCnt();
            if ((cnt >= 0 && cnt <= walk_fps / 4) || (cnt >= walk_fps / 2 + 1 && cnt <= walk_fps / 4 * 3)) graph_num++;
            if (cnt >= walk_fps / 4 * 3 + 1 && cnt <= walk_fps) graph_num += 2;
            DrawExtendGraph(int((pc_coord.x) * square_size), int((pc_coord.y) * square_size), int((pc_coord.x + 1) * square_size), int((pc_coord.y + 1) * square_size), agent_chip[graph_num], TRUE);
        }
    }
}