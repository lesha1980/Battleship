#pragma once

class FourDeck: public MultiDeck 
{
	Deck _deck_1;
	Deck _deck_2;
	Deck _deck_3;
	Deck _deck_4;
	ZoneDeck _zoneDeck;
public:
	FourDeck(bool oriental, int x, int y);
	Deck getDeck_1();
	Deck getDeck_2();
	Deck getDeck_3();
	Deck getDeck_4();
	ZoneDeck getZoneDeck();
	void selfTest();

	virtual ~FourDeck() {

	}
};
