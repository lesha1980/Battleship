#include "../libs.h"

GameBoard::GameBoard()
{
	this->_rows = 10;
	this->_columns = 10;
	this->_lstRow = new int[] { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	this->_lstCol = new char[] {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	this->_board = new Cell* [this->_rows];
	
	for (size_t i = 0; i < this->_rows; i++)
	{
		this->_board[i] = new Cell[this->_columns];
		for (size_t j = 0; j < this->_columns; j++)
		{
			Cell cell(i, j);
			this->_board[i][j] = cell;
		}
	}
}

int GameBoard::getRows()
{
	return this->_rows;
}

int GameBoard::getColumns()
{
	return this->_columns;
}

int* GameBoard::getLstRow()
{
	return this->_lstRow;
}

char* GameBoard::getLstColumns()
{
	return this->_lstCol;
}

GameBoard::~GameBoard()
{
	
	for (size_t i = 0; i < this->_rows; i++)
	{
		delete[] this->_board[i];
	}
	delete[] this->_board;

}
