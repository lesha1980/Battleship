#pragma once

class GameBoardContextController {

	BattleMapGenerateService _mapGenerateService;
	BattleShipGenerateService _shipGenerateService;
	BattleShipMapBindingService _shipMapBindingService;
	BattleShipMapValidationService _shipMapValidationService;

public:
	GameBoardContextController();

	void binderShipBoard();
	GameBoard getGameBoard();
	Ship** getShips();
};
