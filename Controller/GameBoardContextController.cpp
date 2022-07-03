#include "../libs.h"

GameBoardContextController::GameBoardContextController() {


}

void GameBoardContextController::binderShipBoard()
{
    TIMENULL;
    GameBoard _gboard = this->_mapGenerateService.getGameBoard();
    
    int x_1 = rand() % 11;
    int y_1 = rand() % 11;
    bool oriental_1 = rand() % 2;

    Ship* sd_1 = this->_shipGenerateService.CreateFourDeck(x_1, y_1, oriental_1);
    this->_shipGenerateService.setShip(sd_1);    

    int i = 0;
    while (i < 2) {
        bool ctrl = true;
        Ship* sd_2 = nullptr;


        while (ctrl) {
            int x_2 = rand() % 11;
            int y_2 = rand() % 11;
            bool oriental_2 = rand() % 2;
            sd_2 = this->_shipGenerateService.CreateThreeDeck(x_2, y_2, oriental_2);
            this->_shipMapValidationService.initShipMapValidationService(this->_mapGenerateService, this->_shipGenerateService);
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_2, y_2, TypeShip::ThreeDeckShip, oriental_2);
            if (pl) {
                ctrl = !ctrl;
            }
        }

        this->_shipGenerateService.setShip(sd_2);
        i++;
    }

    int j = 0;
    while (j < 3) {
        bool ctrl = true;
        Ship* sd_3 = nullptr;


        while (ctrl) {
            int x_3 = rand() % 11;
            int y_3 = rand() % 11;
            bool oriental_3 = rand() % 2;
            sd_3 = this->_shipGenerateService.CreateDoubleDeck(x_3, y_3, oriental_3);
            this->_shipMapValidationService.initShipMapValidationService(this->_mapGenerateService, this->_shipGenerateService);
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_3, y_3, TypeShip::DoubleDeckShip, oriental_3);
            if (pl) {
                ctrl = !ctrl;
            }
        }

        this->_shipGenerateService.setShip(sd_3);
        j++;
    }

    int k = 0;
    while (k < 4) {
        bool ctrl = true;
        Ship* sd_4 = nullptr;


        while (ctrl) {
            int x_4 = rand() % 11;
            int y_4 = rand() % 11;
            sd_4 = this->_shipGenerateService.CreateSingleDeck(x_4, y_4);
            this->_shipMapValidationService.initShipMapValidationService(this->_mapGenerateService, this->_shipGenerateService);
            bool pl = this->_shipMapValidationService.shipPlacingValidation(x_4, y_4, TypeShip::ThreeDeckShip, true);
            if (pl) {
                ctrl = !ctrl;
            }
        }

        this->_shipGenerateService.setShip(sd_4);
        k++;
    }

    this->_shipMapBindingService.initGameBoardContext(_gboard, this->_shipGenerateService.getShips());
}

GameBoard GameBoardContextController::getGameBoard()
{
    return this->_shipMapBindingService.getGameBoard();
}

Ship** GameBoardContextController::getShips()
{
    return this->_shipMapBindingService.getShips();
}
