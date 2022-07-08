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
    GameBoard gb_2_2 = mode.getGameBoard_2_2();
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

        int sum = 0;
        int sum1 = 0;
        for (size_t i = 0; i < 10; i++)
        {
            ships[i]->selfTest();
            if (ships[i]->getStatusShip() == StatusShip::Dead)
            {
                sum++;
            }
            ships_1[i]->selfTest();
            if (ships_1[i]->getStatusShip() == StatusShip::Dead)
            {
                sum1++;
            }
        }

        if (sum == 10 && sum1 < 10) {
            cout << "Игрок " << pc_gamer_1->getLogin() << " выиграл морское сражение!";
            break;
        }
        if (sum < 10 && sum1 == 10)
        {
            cout << "Игрок " << pc_gamer_2->getLogin() << " выиграл морское сражение!";
            break;
        }
          

        cout << "Игра между " << pc_gamer_1->getLogin() << " и " << " компьютером " << pc_gamer_2->getLogin() << endl;

        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);

        if (pc) {
            cout << "Ход делает " << pc_gamer_1->getLogin();

            int x, y;
            cout << "Укажите координаты цели выстрела" << endl;
            cout << "Укажите координату x " << endl;
            cin >> x;
            cout << "Укажите координату y " << endl;
            cin >> y;

            if (x > 10 || x < 0) {
                cout << "Неверно указана координата x. Требуется переходить" << endl;
                continue;
            }
            if (y > 10 || y < 0) {
                cout << "Неверно указана координата y. Требуется переходить" << endl;
                continue;
            }
            pc = !pc;

           

                bool hit = false;
                for (size_t i = 0; i < 10; i++)
                {
                    
                    Ship* ship = ships_1[i];
                    if (typeid(ship) == typeid(SingleDeck))
                    {
                        SingleDeck* sd = (SingleDeck*)ship;
                        Deck d = sd->getDeck();
                        int x_1 = d.getX();
                        int y_1 = d.getY();

                        if (x_1 == x && y_1 == y)
                        {
                            cout << "Фиксируем попадание в цель" << endl;
                            d.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }

                    }
                    else if (typeid(ship) == typeid(DoubleDeck))
                    {
                        DoubleDeck* dd = (DoubleDeck*)ship;
                        Deck d1 = dd->getDeck_1();
                        Deck d2 = dd->getDeck_2();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                    }
                    else if (typeid(ship) == typeid(ThreeDeck))
                    {
                        ThreeDeck* td = (ThreeDeck*)ship;
                        Deck d1 = td->getDeck_1();
                        Deck d2 = td->getDeck_2();
                        Deck d3 = td->getDeck_3();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                    }
                    else if (typeid(ship) == typeid(FourDeck))
                    {
                        FourDeck* fd = (FourDeck*)ship;
                        Deck d1 = fd->getDeck_1();
                        Deck d2 = fd->getDeck_2();
                        Deck d3 = fd->getDeck_3();
                        Deck d4 = fd->getDeck_4();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                        else if (d4.getX() == x && d4.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                            gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                            hit = !hit;
                        }
                    }
                }
                if (!hit) {
                    cout << "Выстрел мимо цели игрока" << pc_gamer_1->getLogin() << endl;
                    gb_1.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                    Turn turn(x, y);
                    turn.setStatusTurn(StatusTurn::Past);
                    pc_gamer_1->setTurn(turn);
                }
            

            
           
        }
        else {
            cout << "Ход делает " << pc_gamer_2->getLogin();

            int x, y;
            CoordXY coord = mode.getXYByStrategyGamer2();
            x = coord.getX();
            y = coord.getY();
            pc = !pc;

            if (gb_2.getBoard()[x][y].getStatusCell() == StatusCell::Occupied)
            {
                cout << "Зафиксировано попадание в цель игроком" << pc_gamer_2->getLogin() << endl;
                gb_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);

                for (size_t i = 0; i < 10; i++)
                {
                    Ship* ship = ships[i];
                    if (typeid(ship) == typeid(SingleDeck))
                    {
                        SingleDeck* sd = (SingleDeck*)ship;
                        Deck d = sd->getDeck();
                        int x_1 = d.getX();
                        int y_1 = d.getY();

                        if (x_1 == x && y_1 == y)
                        {
                            cout << "Фиксируем попадание в цель" << endl;
                            d.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }

                    }
                    else if (typeid(ship) == typeid(DoubleDeck))
                    {
                        DoubleDeck* dd = (DoubleDeck*)ship;
                        Deck d1 = dd->getDeck_1();
                        Deck d2 = dd->getDeck_2();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(ThreeDeck))
                    {
                        ThreeDeck* td = (ThreeDeck*)ship;
                        Deck d1 = td->getDeck_1();
                        Deck d2 = td->getDeck_2();
                        Deck d3 = td->getDeck_3();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(FourDeck))
                    {
                        FourDeck* fd = (FourDeck*)ship;
                        Deck d1 = fd->getDeck_1();
                        Deck d2 = fd->getDeck_2();
                        Deck d3 = fd->getDeck_3();
                        Deck d4 = fd->getDeck_4();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d4.getX() == x && d4.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                }
            }
            else if (gb_2.getBoard()[x][y].getStatusCell() == StatusCell::Free)
            {
                cout << "Выстрел мимо цели игрока" << pc_gamer_2->getLogin() << endl;
                gb_2.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                Turn turn(x, y);
                turn.setStatusTurn(StatusTurn::Hit);
                pc_gamer_2->setTurn(turn);
            }

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
        mode.setStrategyGamer_2(new StrategyRandomShot());
    }
   
    while (true) {

   
        int sum = 0;
        int sum1 = 0;
        for (size_t i = 0; i < 10; i++)
        {
            ships[i]->selfTest();
            if (ships[i]->getStatusShip() == StatusShip::Dead)
            {
                sum++;
            }
            ships_1[i]->selfTest();
            if (ships_1[i]->getStatusShip() == StatusShip::Dead)
            {
                sum1++;
            }
        }

        if (sum == 10 && sum1 < 10) {
            cout << "Игрок " << pc_gamer_1->getLogin() << " выиграл морское сражение!";
            break;
        }
        if (sum < 10 && sum1 == 10)
        {
            cout << "Игрок " << pc_gamer_2->getLogin() << " выиграл морское сражение!";
            break;
        }

       
        
        cout << "Игра между компьютером " << pc_gamer_1->getLogin() << " и " << " компьютером " << pc_gamer_2->getLogin() << endl;
        
        screen.printScreenGamer_1(gb_1, gb_2, ships, ships_1);
        cout << endl;
        screen.printScreenGamer_2(gb_2_1, gb_2_2, ships_1, ships);
       
        GETCH;
        CLEARSCREEN;
       

        if (pc) {
            cout << "Ход делает " << pc_gamer_1->getLogin();

            int x, y;
            CoordXY coord = mode.getXYByStrategyGamer1();
            x = coord.getX();
            y = coord.getY();
            pc = !pc;

            if (gb_2_2.getBoard()[x][y].getStatusCell() == StatusCell::Occupied)
            {
                cout << "Зафиксировано попадание в цель игроком" << pc_gamer_1->getLogin() << endl;
                gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                gb_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);

                for (size_t i = 0; i < 10; i++)
                {
                    Ship* ship = ships_1[i];
                    if (typeid(ship) == typeid(SingleDeck))
                    {
                        SingleDeck* sd = (SingleDeck*)ship;
                        Deck d = sd->getDeck();
                        int x_1 = d.getX();
                        int y_1 = d.getY();

                        if (x_1 == x && y_1 == y)
                        {
                            cout << "Фиксируем попадание в цель" << endl;
                            d.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }

                    }
                    else if (typeid(ship) == typeid(DoubleDeck))
                    {
                        DoubleDeck* dd = (DoubleDeck*)ship;
                        Deck d1 = dd->getDeck_1();
                        Deck d2 = dd->getDeck_2();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(ThreeDeck))
                    {
                        ThreeDeck* td = (ThreeDeck*)ship;
                        Deck d1 = td->getDeck_1();
                        Deck d2 = td->getDeck_2();
                        Deck d3 = td->getDeck_3();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(FourDeck))
                    {
                        FourDeck* fd = (FourDeck*)ship;
                        Deck d1 = fd->getDeck_1();
                        Deck d2 = fd->getDeck_2();
                        Deck d3 = fd->getDeck_3();
                        Deck d4 = fd->getDeck_4();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                        else if (d4.getX() == x && d4.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_1->setTurn(turn);
                        }
                    }
                }
            }
            else if (gb_2_2.getBoard()[x][y].getStatusCell() == StatusCell::Free)
            {
                cout << "Выстрел мимо цели игрока" << pc_gamer_1->getLogin() << endl;
                gb_2_2.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                gb_1.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                Turn turn(x, y);
                turn.setStatusTurn(StatusTurn::Hit);
                pc_gamer_1->setTurn(turn);
            }
        }
        else {
            cout << "Ход делает " << pc_gamer_2->getLogin();

            int x, y;
            CoordXY coord = mode.getXYByStrategyGamer2();
            x = coord.getX();
            y = coord.getY();
            pc = !pc;

            if (gb_2.getBoard()[x][y].getStatusCell() == StatusCell::Occupied)
            {
                cout << "Зафиксировано попадание в цель игроком" << pc_gamer_2->getLogin() << endl;
                gb_2.getBoard()[x][y].setStatusCell(StatusCell::HitCell);
                gb_2_1.getBoard()[x][y].setStatusCell(StatusCell::HitCell);

                for (size_t i = 0; i < 10; i++)
                {
                    Ship* ship = ships[i];
                    if (typeid(ship) == typeid(SingleDeck))
                    {
                        SingleDeck* sd = (SingleDeck*)ship;
                        Deck d = sd->getDeck();
                        int x_1 = d.getX();
                        int y_1 = d.getY();

                        if (x_1 == x && y_1 == y)
                        {
                            cout << "Фиксируем попадание в цель" << endl;
                            d.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }

                    }
                    else if (typeid(ship) == typeid(DoubleDeck))
                    {
                        DoubleDeck* dd = (DoubleDeck*)ship;
                        Deck d1 = dd->getDeck_1();
                        Deck d2 = dd->getDeck_2();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(ThreeDeck))
                    {
                        ThreeDeck* td = (ThreeDeck*)ship;
                        Deck d1 = td->getDeck_1();
                        Deck d2 = td->getDeck_2();
                        Deck d3 = td->getDeck_3();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                    else if (typeid(ship) == typeid(FourDeck))
                    {
                        FourDeck* fd = (FourDeck*)ship;
                        Deck d1 = fd->getDeck_1();
                        Deck d2 = fd->getDeck_2();
                        Deck d3 = fd->getDeck_3();
                        Deck d4 = fd->getDeck_4();

                        if (d1.getX() == x && d1.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d1.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d2.getX() == x && d2.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d2.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d3.getX() == x && d3.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                        else if (d4.getX() == x && d4.getY() == y)
                        {
                            cout << "Фиксируем попадание в цель " << endl;
                            d3.setStatus(0);
                            Turn turn(x, y);
                            turn.setStatusTurn(StatusTurn::Hit);
                            pc_gamer_2->setTurn(turn);
                        }
                    }
                }
            }
            else if (gb_2_2.getBoard()[x][y].getStatusCell() == StatusCell::Free)
            {
                cout << "Выстрел мимо цели игрока" << pc_gamer_2->getLogin() << endl;
                gb_2.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                gb_2_1.getBoard()[x][y].setStatusCell(StatusCell::SingleShot);
                Turn turn(x, y);
                turn.setStatusTurn(StatusTurn::Hit);
                pc_gamer_2->setTurn(turn);
            }
        }

      
    }

    
}
