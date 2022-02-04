#include"main.h"

void loadChip(influenceMapping::Mapchip& mc, influenceMapping::Player& player) {
    std::vector<int> map_chip(influenceMapping::num_m_chip_ALL);
    LoadDivGraph("base.png", influenceMapping::num_m_chip_ALL, influenceMapping::num_m_chip_X, influenceMapping::num_m_chip_Y, influenceMapping::size_map_X, influenceMapping::size_map_Y, std::data(map_chip));
    mc.setMapchip(map_chip);
    std::vector<int> pl_chip(influenceMapping::num_c_chip_ALL);
    LoadDivGraph("bear.png", influenceMapping::num_c_chip_ALL, influenceMapping::num_c_chip_X, influenceMapping::num_c_chip_Y, influenceMapping::size_character_X, influenceMapping::size_character_Y, std::data(pl_chip));
    player.setCharacterchip(pl_chip);
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
    loadChip(mc, player);
    /*
    //NPCチップロード
    life::NPC npc;
    std::vector<int> npc_chip(influenceMapping::num_c_chip_ALL);
    LoadDivGraph("dog.png", life::num_c_chip_ALL, life::num_c_chip_X, life::num_c_chip_Y, life::size_character_X, life::size_character_Y, std::data(npc_chip));
    npc.setCharacterchip(npc_chip);*/
    //main関数呼び出し
    influenceMapping::main(mc,player);
    return DxLib::DxLib_End();
}