#pragma once

class MultiDeck : public Ship 
{
protected:
	int _size;
	Deck* _deck;
	bool _oriental;                      //��������� �������: ����������� true �� ������������� false

public:
	MultiDeck(int size, bool oriental);

	virtual ~MultiDeck();
};
