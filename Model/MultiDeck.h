#pragma once

class MultiDeck : public Ship 
{
protected:
	int _size;
	bool _oriental;                      //��������� �������: ����������� true �� ������������� false

public:
	MultiDeck(int size, bool oriental, TypeShip typeShip, StatusShip statusShip);

	virtual ~MultiDeck() {

	}
};
