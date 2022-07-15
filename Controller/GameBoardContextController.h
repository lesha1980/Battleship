#pragma once

class GameBoardContextController {

	//BattleMapGenerateService _mapGenerateService;
	BattleShipGenerateService _shipGenerateService;
	BattleShipMapBindingService _shipMapBindingService;
	BattleShipMapValidationService _shipMapValidationService;

public:
	GameBoardContextController();

	void binderShipBoard(GameBoard& gboard, Ship** ship);
	bool binderShipBoard(GameBoard& gboard, Ship** ship, int x, int y, TypeShip typeShip, bool oriental, int& count);
	
};
