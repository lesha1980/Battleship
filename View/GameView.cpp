#include "../libs.h"

void GameView::_human_pc_mode(string login)
{
    GameHumanPCMode mode;
    Screen screen;
    mode.init();
}

void GameView::_pc_pc_mode()
{
    GamePCPCMode mode;
    Screen screen;
    mode.init();
    TIMENULL;
    Gamer* pc_gamer_1 = mode.getGamer_1();
    Gamer* pc_gamer_2 = mode.getGamer_2();
    GameBoard gb_1 = mode.getGameBoard_1();
    GameBoard gb_2 = mode.getGameBoard_2();
    Ship** ships = mode.getShips();
    GameBoard gb_2_1 = mode.getGameBoard_2_1();
    GameBoard gb_2_2 = mode.getGameBoard_2_2();
    Ship** ships_1 = mode.getShips_1();


    cout << "Определяем, какой компьютер делает ход первым" << endl;
    bool pc = rand() % 2;
    if (pc) {
        cout << "Первым делает ход " << pc_gamer_1->getLogin() << endl;
    }
    else {
        cout << "Первым делает ход " << pc_gamer_2->getLogin() << endl;
    }

    while (true) {

        cout << "Игра между компьютером " << pc_gamer_1->getLogin() << " и " << " компьютером " << pc_gamer_2->getLogin() << endl;
        
        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);
        screen.printScreenGamer_2(gb_2_1, gb_2_2, ships_1, ships);

        if (pc) {
            cout << "Ход делает " << pc_gamer_1->getLogin();
        }
        else {
            cout << "Ход делает " << pc_gamer_2->getLogin();
        }


    }
}
