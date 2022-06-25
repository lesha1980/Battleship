#pragma once

class BattleMapGenerateService {

	GameBoard _gameBoard_1;
	GameBoard _gameBoard_2;

public:
	BattleMapGenerateService();

	GameBoard getGameBoard_1();
	GameBoard getGameBoard_2();
};