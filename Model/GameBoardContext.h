#pragma once

class GameBoardContext {
	GameBoard _gameBoard;
	Ship** ships;

public:
	GameBoardContext(GameBoard gameBoard, Ship** ship);
};
