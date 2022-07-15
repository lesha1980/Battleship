#include "../libs.h"

CoordXY StrategyRandomShot::Strategy()
{
	TIMENULL;

	int x = rand() % 10;
	int y = rand() % 10;

	return CoordXY(x, y);
}
