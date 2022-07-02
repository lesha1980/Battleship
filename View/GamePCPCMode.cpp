#include "../libs.h"

void GamePCPCMode::init()
{

	this->_gamer1 = this->_pcgamer_ctrl.createGamer("PC-1");
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	
}
