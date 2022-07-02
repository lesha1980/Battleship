#include "libs.h"

int main() {

	startGame();
	return 0;
}

void startGame() {
	SETLOCAL;
	cout << "����� ���������� � ���� ������� ���" << endl;
	void (*modes[2])() = { human_pc, pc_pc };
	int mode;
	cout << "� ���� ���� ��� ������: �������-��������� � ���������-���������" << endl;
	cout << "�������� ���������� ����� ����:" << endl;
	cout << "������� 1, ����� ������� ����� �������-���������" << endl;
	cout << "������� 2, ����� ������� ����� ���������-���������" << endl;

	cin >> mode;

	if (mode == 1) {
		modes[0]();
	}
	else if (mode == 2) {
		modes[1]();
	}
	else {
		cout << "������ ������������ ����� ������ ����" << endl;
		return;
	}


	GETCH;
}

void human_pc() {
	string login;
	cout << "������� ����� ��� ����" << endl;
	cin >> login;

	GameView _gview;
	_gview._human_pc_mode(login);
}

void pc_pc() {
	GameView _gview;
	_gview._pc_pc_mode();
}