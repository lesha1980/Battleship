#pragma once

//створює карту морського бою без кораблів
class BattleMapGenerateService {

	GameBoard _gameBoard;


public:

	GameBoard getGameBoard();
	void setGameBoard(GameBoard gboard);
};