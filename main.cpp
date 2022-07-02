#include "libs.h"

int main() {

	startGame();
	return 0;
}

void startGame() {
	SETLOCAL;
	cout << "Добро пожаловать в игру Морской бой" << endl;
	void (*modes[2])() = { human_pc, pc_pc };
	int mode;
	cout << "В этой игре два режима: Человек-Компьютер и Компьютер-Компьютер" << endl;
	cout << "Выберите подходящий режим игры:" << endl;
	cout << "Нажмите 1, чтобы выбрать режим Человек-Компьютер" << endl;
	cout << "Нажмите 2, чтобы выбрать режим Компьютер-Компьютер" << endl;

	cin >> mode;

	if (mode == 1) {
		modes[0]();
	}
	else if (mode == 2) {
		modes[1]();
	}
	else {
		cout << "Введен некорректный номер режима игры" << endl;
		return;
	}


	GETCH;
}

void human_pc() {
	string login;
	cout << "Укажите логин для игры" << endl;
	cin >> login;

	GameView _gview;
	_gview._human_pc_mode(login);
}

void pc_pc() {
	GameView _gview;
	_gview._pc_pc_mode();
}