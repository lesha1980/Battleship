#pragma once

class Deck {                      //���� ������, �������� ������� �� ��� ���, �� ���������� �� ��� �������

	int _x;                       //����� � ����� ����������� ������
	int _y;                       //�������, � ��� ����������� ������

public:
	Deck();
	Deck(int x, int y);

	void setX(int x);
	void setY(int y);
	int getX();
	int getY();


};