#pragma once

class BattleShipMapBindingService {

	GameBoard _gameBoard;
	Ship** _ships;

public:
	BattleShipMapBindingService();
	BattleShipMapBindingService(GameBoard gameBoard, Ship** ships);
	void getGameBoardContext();
};
