#pragma once

class GameBoard {

	Cell** _board;
	int _rows;
	int _columns;
	int* _lstRow;
	char* _lstCol;

public:

	GameBoard();

	virtual ~GameBoard();
};
