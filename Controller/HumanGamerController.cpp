#include "../libs.h"

Gamer* HumanGamerController::createGamer(string login)
{
	return this->_gamerService.getHumanGamer(login);
}
