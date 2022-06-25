#pragma once

class Deck {                      //клас палуба, зображуэ клітинку на полі боя, що відноситься до тіла корабля

	int _x;                       //рядок в якому знаходиться палуба
	int _y;                       //колонка, в якій знаходиться палуба

public:
	Deck();
	Deck(int x, int y);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();


};