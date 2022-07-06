#pragma once

class GameActionController {

	StrategyContextService _strategy_gamer_1;
	StrategyContextService _strategy_gamer_2;

public:

	void setStrategyGamer1(StrategyGame* strategy);
	void setStrategyGamer2(StrategyGame* strategy);
};
