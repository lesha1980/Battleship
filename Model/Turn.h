#pragma once

//����, �� ����� ��� ������

class Turn {
	char _clmn;
	int _rw;
	StatusTurn _status_turn;
public:
	Turn(char clmn, int rw);
	void setStatusTurn(StatusTurn status);

};
