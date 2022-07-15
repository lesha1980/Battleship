#include "../libs.h"
#include "Cell.h"

Cell::Cell()
{
	this->_x = 0;
	this->_y = 0;
	this->_status = StatusCell::UnknownCell;
}

Cell::Cell(int x, int y)
{
	this->_x = x;
	this->_y = y;
	this->_status = StatusCell::Free;
}

Cell::Cell(Cell& cell)
{
	this->_x = cell.getX();
	this->_y = cell.getY();
	this->_status = cell.getStatusCell();
}

void Cell::setX(int x)
{
	this->_x = x;
}

void Cell::setY(int y)
{
	this->_y = y;
}

void Cell::setStatusCell(StatusCell status)
{
	this->_status = status;
}

int Cell::getX()
{
	return this->_x;
}

int Cell::getY()
{
	return this->_y;
}

StatusCell Cell::getStatusCell()
{
	return this->_status;
}

Cell& Cell::operator=(const Cell& cell)
{
	this->_x = cell._x;
	this->_y = cell._y;
	this->_status = cell._status;

	return *this;
}
