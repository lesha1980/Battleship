#pragma once


class SingleDeck: public Ship 
{
	Deck _deck;
	ZoneDeck _zoneDeck;

public:
	SingleDeck(int x, int y);
	Deck getDeck();
	

};