#include "../libs.h"

Gamer* BattleGamerGenerateService::getPCGamer(string login)
{
	return new ComputerGamer(login);
}

Gamer* BattleGamerGenerateService::getHumanGamer(string login)
{
	return new HumanGamer(login);
}
