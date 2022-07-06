#pragma once

class StrategyGame {

public:
	virtual CoordXY Strategy() = 0;

	virtual ~StrategyGame() {

	}
};
