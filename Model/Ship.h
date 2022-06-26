#pragma once
#include "Enums/TypeShip.h"
#include "Enums/StatusShip.h"

class Ship {

protected:

	TypeShip _type_ship;
	StatusShip _status_ship;

public:
	Ship(TypeShip type_ship, StatusShip status_ship);
	TypeShip getTypeShip();
	StatusShip getStatusShip();


};
