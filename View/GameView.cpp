#include "../libs.h"

void GameView::_human_pc_mode(string login)
{
    GameHumanPCMode mode;
    mode.init();
}

void GameView::_pc_pc_mode()
{
    GamePCPCMode mode;
    mode.init();
    Gamer* pc_gamer_1 = mode.getGamer_1();
    Gamer* pc_gamer_2 = mode.getGamer_2();
}
