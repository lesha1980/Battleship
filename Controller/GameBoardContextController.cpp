#include "../libs.h"

GameBoardContextController::GameBoardContextController() {


}

void GameBoardContextController::binderShipBoard(GameBoard& gboard, Ship** ships)
{
    TIMENULL;
    
    int d = 0;
    while (d < 1) {
        bool ctrl = true;
        Ship* sd = nullptr;


        while (ctrl) {
            int x_1 = rand() % 10;
            int y_1 = rand() % 10;
            bool oriental_1 = rand() % 2;
            sd = this->_shipGenerateService.CreateFourDeck(x_1, y_1, oriental_1);
            this->_shipGenerateService.setShip(sd);

            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_1, y_1, TypeShip::FourDeckShip, oriental_1, gboard, this->_shipGenerateService);
            if (pl) {
                ctrl = !ctrl;
            }
            else {
                this->_shipGenerateService.logicDelShip();
            }
        }

        ships[0] = sd;
        d++;
    }

   
    /*bool oriental_1 = rand() % 2;

    Ship* sd_1 = this->_shipGenerateService.CreateFourDeck(x_1, y_1, oriental_1);
    ships[0] = sd_1;
    this->_shipGenerateService.setShip(sd_1);*/

    int i = 0;
    while (i < 2) {
        bool ctrl = true;
        Ship* sd_2 = nullptr;


        while (ctrl) {
            int x_2 = rand() % 10;
            int y_2 = rand() % 10;
            bool oriental_2 = rand() % 2;
            sd_2 = this->_shipGenerateService.CreateThreeDeck(x_2, y_2, oriental_2);
            this->_shipGenerateService.setShip(sd_2);
          
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_2, y_2, TypeShip::ThreeDeckShip, oriental_2, gboard, this->_shipGenerateService);
            if (pl) {
                ctrl = !ctrl;
            }
            else {
                this->_shipGenerateService.logicDelShip();
            }
        }

        ships[i + 1] = sd_2;
        i++;
    }

    int j = 0;
    while (j < 3) {
        bool ctrl = true;
        Ship* sd_3 = nullptr;


        while (ctrl) {
            int x_3 = rand() % 10;
            int y_3 = rand() % 10;
            bool oriental_3 = rand() % 2;
            sd_3 = this->_shipGenerateService.CreateDoubleDeck(x_3, y_3, oriental_3);
            this->_shipGenerateService.setShip(sd_3);
            //this->_shipMapValidationService.initShipMapValidationService(gboard, this->_shipGenerateService);
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_3, y_3, TypeShip::DoubleDeckShip, oriental_3, gboard, this->_shipGenerateService);
            if (pl) {
                ctrl = !ctrl;
            }
            else {
                this->_shipGenerateService.logicDelShip();
            }
        }

        ships[j + 3] = sd_3;
        j++;
    }

    int k = 0;
    while (k < 4) {
        bool ctrl = true;
        Ship* sd_4 = nullptr;


        while (ctrl) {
            int x_4 = rand() % 10;
            int y_4 = rand() % 10;
            sd_4 = this->_shipGenerateService.CreateSingleDeck(x_4, y_4);
            this->_shipGenerateService.setShip(sd_4);
            //this->_shipMapValidationService.initShipMapValidationService(gboard, this->_shipGenerateService);
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_4, y_4, TypeShip::ThreeDeckShip, true, gboard, this->_shipGenerateService);
            if (pl) {
                ctrl = !ctrl;
            }
            else {
                this->_shipGenerateService.logicDelShip();
            }
        }

        ships[k + 6] = sd_4;
        k++;
    }

    this->_shipMapBindingService.initGameBoardContext(gboard, ships);
}

bool GameBoardContextController::binderShipBoard(GameBoard& gboard, Ship** ships, int x, int y, TypeShip typeShip, bool oriental, int &count)
{
    TIMENULL;

    int x_1 = x;
    int y_1 = y;
    Ship* sd_1 = nullptr;
    if (typeShip == TypeShip::SingleDeckShip) {
        sd_1 = this->_shipGenerateService.CreateSingleDeck(x_1, y_1);
    }
    else if (typeShip == TypeShip::DoubleDeckShip) {
        sd_1 = this->_shipGenerateService.CreateDoubleDeck(x_1, y_1, oriental);
    }
    else if (typeShip == TypeShip::ThreeDeckShip) {
        sd_1 = this->_shipGenerateService.CreateThreeDeck(x_1, y_1, oriental);
    }
    else if (typeShip == TypeShip::FourDeckShip) {
        sd_1 = this->_shipGenerateService.CreateFourDeck(x_1, y_1, oriental);
    }

    if (count == 0)
    {
        ships[0] = sd_1;
        count++;
        return true;
    }

    for (size_t i = 0; i < count; i++) {
        this->_shipGenerateService.setShip(ships[i]);
    }
    bool pl = true;
    if (typeShip == TypeShip::SingleDeckShip) {
        pl = this->_shipMapValidationService.shipPlacingValidation(x_1, y_1, TypeShip::SingleDeckShip, oriental, gboard, this->_shipGenerateService);
    }
    else if (typeShip == TypeShip::DoubleDeckShip)
    {
        pl = this->_shipMapValidationService.shipPlacingValidation(x_1, y_1, TypeShip::DoubleDeckShip, oriental, gboard, this->_shipGenerateService);
    }
    else if (typeShip == TypeShip::ThreeDeckShip)
    {
        pl = this->_shipMapValidationService.shipPlacingValidation(x_1, y_1, TypeShip::ThreeDeckShip, oriental, gboard, this->_shipGenerateService);
    }
    else if (typeShip == TypeShip::FourDeckShip)
    {
        pl = this->_shipMapValidationService.shipPlacingValidation(x_1, y_1, TypeShip::FourDeckShip, oriental, gboard, this->_shipGenerateService);
    }

    if (!pl) {
        return false;
    }

    ships[count] = sd_1;
    count++;

    if (count == 10) {
        this->_shipMapBindingService.initGameBoardContext(gboard, ships);
    }
   
    return true;

}

