#pragma once

class GameBoardContext {
	GameBoard _gameBoard;
	Ship** ships;

public:
	GameBoardContext(GameBoard gameBoard, Ship** ship);

	~GameBoardContext() {
		for (size_t i = 0; i < 10; i++)
		{
			delete  this->ships[i];
		}
		delete[] this->ships;
	}
};
