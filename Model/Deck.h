#pragma once

class Deck {                      //клас палуба, зображуэ клітинку на полі боя, що відноситься до тіла корабля

	int _x;                       //рядок в якому знаходиться палуба
	int _y;                       //колонка, в якій знаходиться палуба
	int _number;                  //номер палуби: від 1 до 4
	bool _status;                 //статус палуби: 0 підбита; 1 діє

public:
	Deck();
	Deck(int x, int y, int number);

	void setX(int x);
	void setY(int y);
	void setNumber(int number);
	void setStatus(bool status);
	int getX();
	int getY();
	int getNumber();
	bool getStatus();

	

};