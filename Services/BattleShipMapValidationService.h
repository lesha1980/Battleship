#pragma once

class BattleShipMapValidationService
{
	BattleMapGenerateService _mapGenerateService;
	BattleShipGenerateService _shipGenerateService;

public:
	void initShipMapValidationService(BattleMapGenerateService mapGenerateService, BattleShipGenerateService shipGenerateService);
	bool shipPlacingValidation(int x, int y, TypeShip typeShip, bool oriental);
	bool checkZoneDeck(ZoneDeck d, int x, int y, TypeShip typeShip, bool oriental);
};
