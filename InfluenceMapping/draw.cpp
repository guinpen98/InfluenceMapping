#include "draw.h"

namespace influenceMapping {/*
    void drawMap(Vec2 camera_coord, std::vector<std::vector<int>>& field, life::Mapchip mc) {
        std::array<int, life::num_m_chip_ALL> map_chip = mc.getMapchip();
        for (int y = int(camera_coord.y); y < int(camera_coord.y) + 1 + window_square_h; y++) {
            for (int x = int(camera_coord.x); x < int(camera_coord.x) + 1 + window_square_w; x++) {
                unsigned int cr = GetColor(0, 0, 0);
                DrawExtendGraph(int((x - camera_coord.x) * square_size), int((y - camera_coord.y) * square_size), int((x - camera_coord.x + 1) * square_size), int((y - camera_coord.y + 1) * square_size), map_chip[33], TRUE);
                switch (field[y][x])
                {
                case 1:
                    cr = GetColor(255, 255, 255);
                    DrawExtendGraph(int((x - camera_coord.x) * square_size), int((y - camera_coord.y) * square_size), int((x - camera_coord.x + 1) * square_size), int((y - camera_coord.y + 1) * square_size), map_chip[81], TRUE);
                    break;
                case 0:
                    cr = GetColor(0, 0, 0);
                    break;
                default:
                    break;
                }
            }
        }
    }*/
    void drawPlayer(Player player) {
        Vec2 pc_coord = player.getInterimCoord();
        std::array<int, num_c_chip_ALL> player_chip = player.getCharacterchip();
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
    }/*
    void drawNPC(life::NPC npc, Vec2 camera_coord) {
        Vec2 pc_coord = npc.getInterimCoord();
        std::array<int, life::num_c_chip_ALL> npc_chip = npc.getCharacterchip();
        int graph_num = 0;
        switch (npc.getDirection())
        {
        case life::directionUpE:
            graph_num = 9;
            break;
            break;
        case life::directionLeftE:
            graph_num = 3;
            break;
        case life::directionRightE:
            graph_num = 6;
            break;
        default:
            break;
        }
        int cnt = npc.getWalkCnt();
        if ((cnt >= 0 && cnt <= walk_fps / 4) || (cnt >= walk_fps / 2 + 1 && cnt <= walk_fps / 4 * 3)) graph_num++;
        if (cnt >= walk_fps / 4 * 3 + 1 && cnt <= walk_fps) graph_num += 2;
        DrawExtendGraph(int((pc_coord.x - camera_coord.x) * square_size), int((pc_coord.y - camera_coord.y) * square_size), int((pc_coord.x - camera_coord.x + 1) * square_size), int((pc_coord.y - camera_coord.y + 1) * square_size), npc_chip[graph_num], TRUE);
    }*/
}