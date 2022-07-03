#pragma once

class BattleShipMapBindingService {

	GameBoard _gameBoard;
	Ship** _ships;
	

public:	
	void initGameBoardContext(GameBoard gameBoard, Ship** ships);
	GameBoard getGameBoard();
	Ship** getShips();
	
};
