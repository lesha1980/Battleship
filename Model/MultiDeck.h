#pragma once

class MultiDeck : public Ship 
{
protected:
	int _size;
	Deck* _deck;
	bool _oriental;                      //розм≥щенн€ корабл€: вертикально true та горизонтально false

public:
	MultiDeck(int size, bool oriental);

	virtual ~MultiDeck();
};
