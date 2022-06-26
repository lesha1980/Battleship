#pragma once

class DoubleDeck : public MultiDeck 
{
	Deck _deck_1;
	Deck _deck_2;
	ZoneDeck _zoneDeck;
public:
	DoubleDeck(bool oriental, int x, int y);
	Deck getDeck_1();
	Deck getDeck_2();
};
