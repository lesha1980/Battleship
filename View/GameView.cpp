#include "../libs.h"

void GameView::_human_pc_mode(string login)
{
    GameHumanPCMode mode;
    Screen screen;
    
    mode.init();
    TIMENULL;
    Gamer* pc_gamer_1 = mode.getGamer_1();
    Gamer* pc_gamer_2 = mode.getGamer_2();
    GameBoard gb_1 = mode.getGameBoard_1();
    GameBoard gb_2 = mode.getGameBoard_2();
    Ship** ships = mode.getShips();
    Ship** ships_1 = mode.getShips_1();
    cout << "Определяем, кто делает ход первым: человек или компьютер" << endl;
    bool pc = rand() % 2;
    if (pc) {
        cout << "Первым делает ход " << pc_gamer_1->getLogin() << endl;
    }
    else {
        cout << "Первым делает ход " << pc_gamer_2->getLogin() << endl;
    }


    cout << "Определяем стратегию, которой будет придерживаться компьютер " << pc_gamer_2->getLogin() << endl;
    bool pc2_s = rand() % 2;

    cout << "Игрок " << pc_gamer_2->getLogin() << " будет придерживаться ";
    if (pc2_s) {
        cout << " оптимальной стратегии " << endl;
        mode.setStrategyGamer_2(new StrategyDontShotZoneShip());
    }
    else {
        cout << " стратегии случайного выстрела " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
    }

    while (true) {

        cout << "Игра между " << pc_gamer_1->getLogin() << " и " << " компьютером " << pc_gamer_2->getLogin() << endl;

        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);

        if (pc) {
            cout << "Ход делает " << pc_gamer_1->getLogin();
        }
        else {
            cout << "Ход делает " << pc_gamer_2->getLogin();
        }


    }

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

    cout << "Определяем стратегию, которой будет придерживаться игрок " << pc_gamer_1->getLogin() << endl;
    bool pc1_s = rand() % 2;

    cout << "Игрок " << pc_gamer_1->getLogin() << " будет придерживаться ";
    if (pc1_s) {
        cout << " оптимальной стратегии " << endl;
        mode.setStrategyGamer_1(new StrategyDontShotZoneShip());
        
    }
    else {
        cout << " стратегии случайного выстрела " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
    }

    cout << "Определяем стратегию, которой будет придерживаться игрок " << pc_gamer_2->getLogin() << endl;
    bool pc2_s = rand() % 2;

    cout << "Игрок " << pc_gamer_2->getLogin() << " будет придерживаться ";
    if (pc2_s) {
        cout << " оптимальной стратегии " << endl;
        mode.setStrategyGamer_2(new StrategyDontShotZoneShip());
    }
    else {
        cout << " стратегии случайного выстрела " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
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
