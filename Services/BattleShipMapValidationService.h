#pragma once

class BattleShipMapValidationService
{


public:

	bool shipPlacingValidation(int x, int y, TypeShip typeShip, bool oriental, GameBoard& gboard, BattleShipGenerateService& shipGenerateService);
	bool checkZoneDeck(ZoneDeck d, int x, int y, TypeShip typeShip, bool oriental);
};
