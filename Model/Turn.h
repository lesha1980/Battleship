#pragma once

//����, �� ����� ��� ������

class Turn {
	int _clmn;
	int _rw;
	StatusTurn _status_turn;
public:
	Turn();
	Turn(int clmn, int rw);
	void setStatusTurn(StatusTurn status);

};
