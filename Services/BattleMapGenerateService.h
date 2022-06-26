#pragma once

//створює карту морського бою без кораблів
class BattleMapGenerateService {

	GameBoard _gameBoard;


public:
	BattleMapGenerateService();

	GameBoard getGameBoard();
};