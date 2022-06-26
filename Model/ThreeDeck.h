#pragma once

class ThreeDeck: public MultiDeck
{
	Deck _deck_1;
	Deck _deck_2;
	Deck _deck_3;
	ZoneDeck _zoneDeck;
public:
	ThreeDeck(bool oriental, int x, int y);
	Deck getDeck_1();
	Deck getDeck_2();
	Deck getDeck_3();
	ZoneDeck getZoneDeck();
};
