#include "../libs.h"

GameBoardContextController::GameBoardContextController() {


}

void GameBoardContextController::binderShipBoard(GameBoard& gboard, Ship** ships)
{
    TIMENULL;
    
    int x_1 = rand() % 10;
    int y_1 = rand() % 10;
    bool oriental_1 = rand() % 2;

    Ship* sd_1 = this->_shipGenerateService.CreateFourDeck(x_1, y_1, oriental_1);
    ships[0] = sd_1;
    this->_shipGenerateService.setShip(sd_1);

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
           // this->_shipMapValidationService.initShipMapValidationService(gboard, this->_shipGenerateService);
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

/*GameBoard GameBoardContextController::getGameBoard()
{
    return this->_shipMapBindingService.getGameBoard();
}
*/

/*Ship** GameBoardContextController::getShips()
{
    return this->_shipMapBindingService.getShips();
}*/
