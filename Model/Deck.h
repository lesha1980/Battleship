#pragma once

class Deck {                      //���� ������, �������� ������� �� ��� ���, �� ���������� �� ��� �������

	int _x;                       //����� � ����� ����������� ������
	int _y;                       //�������, � ��� ����������� ������
	int _number;                  //����� ������: �� 1 �� 4
	bool _status;                 //������ ������: 0 ������; 1 䳺

public:
	Deck();
	Deck(int x, int y, int number);

	void setX(int x);
	void setY(int y);
	void setNumber(int number);
	void setStatus(bool status);
	int getX();
	int getY();
	int getNumber();
	bool getStatus();

	

};