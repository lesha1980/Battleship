#pragma once

class MultiDeck : public Ship 
{
protected:
	int _size;
	Deck* _deck;

public:
	MultiDeck(int size);

	virtual ~MultiDeck();
};
