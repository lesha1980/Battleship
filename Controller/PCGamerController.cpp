#include "../libs.h"

Gamer* PCGamerController::createGamer(string login)
{
	return this->_gamerService.getPCGamer(login);
}
