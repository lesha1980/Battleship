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
    cout << "����������, ��� ������ ��� ������: ������� ��� ���������" << endl;
    bool pc = rand() % 2;
    if (pc) {
        cout << "������ ������ ��� " << pc_gamer_1->getLogin() << endl;
    }
    else {
        cout << "������ ������ ��� " << pc_gamer_2->getLogin() << endl;
    }


    cout << "���������� ���������, ������� ����� �������������� ��������� " << pc_gamer_2->getLogin() << endl;
    bool pc2_s = rand() % 2;

    cout << "����� " << pc_gamer_2->getLogin() << " ����� �������������� ";
    if (pc2_s) {
        cout << " ����������� ��������� " << endl;
        mode.setStrategyGamer_2(new StrategyDontShotZoneShip());
    }
    else {
        cout << " ��������� ���������� �������� " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
    }

    while (true) {

        cout << "���� ����� " << pc_gamer_1->getLogin() << " � " << " ����������� " << pc_gamer_2->getLogin() << endl;

        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);

        if (pc) {
            cout << "��� ������ " << pc_gamer_1->getLogin();
        }
        else {
            cout << "��� ������ " << pc_gamer_2->getLogin();
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


    cout << "����������, ����� ��������� ������ ��� ������" << endl;
    bool pc = rand() % 2;
    if (pc) {
        cout << "������ ������ ��� " << pc_gamer_1->getLogin() << endl;
    }
    else {
        cout << "������ ������ ��� " << pc_gamer_2->getLogin() << endl;
    }

    cout << "���������� ���������, ������� ����� �������������� ����� " << pc_gamer_1->getLogin() << endl;
    bool pc1_s = rand() % 2;

    cout << "����� " << pc_gamer_1->getLogin() << " ����� �������������� ";
    if (pc1_s) {
        cout << " ����������� ��������� " << endl;
        mode.setStrategyGamer_1(new StrategyDontShotZoneShip());
        
    }
    else {
        cout << " ��������� ���������� �������� " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
    }

    cout << "���������� ���������, ������� ����� �������������� ����� " << pc_gamer_2->getLogin() << endl;
    bool pc2_s = rand() % 2;

    cout << "����� " << pc_gamer_2->getLogin() << " ����� �������������� ";
    if (pc2_s) {
        cout << " ����������� ��������� " << endl;
        mode.setStrategyGamer_2(new StrategyDontShotZoneShip());
    }
    else {
        cout << " ��������� ���������� �������� " << endl;
        mode.setStrategyGamer_1(new StrategyRandomShot());
    }

    while (true) {

        cout << "���� ����� ����������� " << pc_gamer_1->getLogin() << " � " << " ����������� " << pc_gamer_2->getLogin() << endl;
        
        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);
        screen.printScreenGamer_2(gb_2_1, gb_2_2, ships_1, ships);

        if (pc) {
            cout << "��� ������ " << pc_gamer_1->getLogin();
        }
        else {
            cout << "��� ������ " << pc_gamer_2->getLogin();
        }


    }
}
