#pragma once

class MultiDeck : public Ship 
{
protected:
	int _size;
	bool _oriental;                      //розм≥щенн€ корабл€: вертикально true та горизонтально false

public:
	MultiDeck(int size, bool oriental, TypeShip typeShip, StatusShip statusShip);

	virtual ~MultiDeck() {

	}
};
