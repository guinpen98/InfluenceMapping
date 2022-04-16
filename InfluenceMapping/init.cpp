#include"main.h"

void loadChip(influenceMapping::Mapchip& mc, influenceMapping::Player& player, influenceMapping::Agent& agent) {
    std::vector<int> map_chip(influenceMapping::num_m_chip_ALL);
    LoadDivGraph("base.png", influenceMapping::num_m_chip_ALL, influenceMapping::num_m_chip_X, influenceMapping::num_m_chip_Y, influenceMapping::size_map_X, influenceMapping::size_map_Y, std::data(map_chip));
    mc.setMapchip(map_chip);
    std::vector<int> pl_chip(influenceMapping::num_c_chip_ALL);
    LoadDivGraph("bear.png", influenceMapping::num_c_chip_ALL, influenceMapping::num_c_chip_X, influenceMapping::num_c_chip_Y, influenceMapping::size_character_X, influenceMapping::size_character_Y, std::data(pl_chip));
    player.setCharacterchip(pl_chip);
    std::vector<int> npc_chip(influenceMapping::num_c_chip_ALL);
    LoadDivGraph("agent.png", influenceMapping::num_c_chip_ALL, influenceMapping::num_c_chip_X, influenceMapping::num_c_chip_Y, influenceMapping::size_character_X, influenceMapping::size_character_Y, std::data(npc_chip));
    agent.setCharacterchip(npc_chip);
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
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
    loadChip(mc, player,agent[0]);
    //main関数呼び出し
    influenceMapping::main(mc,player,agent);
    return DxLib::DxLib_End();
}