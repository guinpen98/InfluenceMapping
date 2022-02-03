#include"main.h"


int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    DxLib::SetOutApplicationLogValidFlag(FALSE);
    DxLib::ChangeWindowMode(TRUE);
    DxLib::SetGraphMode(window_w, window_h, 32);
    DxLib::SetMainWindowText("Life");
    if (DxLib::DxLib_Init() == -1) return -1;
    DxLib::SetDrawScreen(DX_SCREEN_BACK);/*
    // マップチップロード
    life::Mapchip mc;
    std::array<int, life::num_m_chip_ALL> map_chip = mc.getMapchip();
    LoadDivGraph("base.png", life::num_m_chip_ALL, life::num_m_chip_X, life::num_m_chip_Y, life::size_map_X, life::size_map_Y, std::data(map_chip));
    mc.setMapchip(map_chip);*/
    //キャラクターチップロード
    influenceMapping::Player player;
    std::array<int, influenceMapping::num_c_chip_ALL> pl_chip = player.getCharacterchip();
    LoadDivGraph("bear.png", influenceMapping::num_c_chip_ALL, influenceMapping::num_c_chip_X, influenceMapping::num_c_chip_Y, influenceMapping::size_character_X, influenceMapping::size_character_Y, std::data(pl_chip));
    player.setCharacterchip(pl_chip);
    /*
    //NPCチップロード
    life::NPC npc;
    std::array<int, life::num_c_chip_ALL> npc_chip = npc.getCharacterchip();
    LoadDivGraph("dog.png", life::num_c_chip_ALL, life::num_c_chip_X, life::num_c_chip_Y, life::size_character_X, life::size_character_Y, std::data(npc_chip));
    npc.setCharacterchip(npc_chip);*/
    //main関数呼び出し
    influenceMapping::main(player);
    return DxLib::DxLib_End();
}