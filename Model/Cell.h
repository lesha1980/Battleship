#pragma once
#include "Enums/StatusCell.h"

class Cell {

	int _x;
	int _y;
	StatusCell _status;

public:
	Cell();
	Cell(int x, int y);

	void setX(int x);
	void setY(int y);
	void setStatusCell(StatusCell status);
	int getX();
	int getY();
	StatusCell getStatusCell();



};
