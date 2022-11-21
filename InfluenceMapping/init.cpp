#include "main.h"
#include <DxLib.h>

namespace influenceMapping {
    void loadChip(Mapchip& mc, Player& player, Agent& agent) {
        std::vector<int> map_chip(num_m_chip_ALL);
        LoadDivGraph("base.png", num_m_chip_ALL, num_m_chip_X, num_m_chip_Y, size_map_X, size_map_Y, std::data(map_chip));
        mc.setMapchip(map_chip);
        std::vector<int> pl_chip(num_c_chip_ALL);
        LoadDivGraph("bear.png", num_c_chip_ALL, num_c_chip_X, num_c_chip_Y, size_character_X, size_character_Y, std::data(pl_chip));
        player.setCharacterchip(pl_chip);
        std::vector<int> npc_chip(num_c_chip_ALL);
        LoadDivGraph("agent.png", num_c_chip_ALL, num_c_chip_X, num_c_chip_Y, size_character_X, size_character_Y, std::data(npc_chip));
        agent.setCharacterchip(npc_chip);
    }
}


int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int)
{
    DxLib::SetOutApplicationLogValidFlag(FALSE);
    DxLib::ChangeWindowMode(TRUE);
    DxLib::SetGraphMode(window_w, window_h, 32);
    DxLib::SetMainWindowText("InfluenceMapping");
    if (DxLib::DxLib_Init() == -1) return -1;
    DxLib::SetDrawScreen(DX_SCREEN_BACK);
    // チップロード
    influenceMapping::Mapchip mc;
    influenceMapping::Player player;
    std::vector<influenceMapping::Agent> agent(influenceMapping::agent_num);
    influenceMapping::loadChip(mc, player,agent[0]);
    //main関数呼び出し
    influenceMapping::main(mc,player,agent);
    return DxLib::DxLib_End();
}