#include "../libs.h"

CoordXY StrategyDontShotZoneShip::Strategy()
{
	TIMENULL;
	if (this->_turns.getTop() == 0) {
		return CoordXY(rand() % 10, rand() % 10);
	}

	BattleStack<Turn> t;

	int limit = 0;
	if (this->_turns.getTop() > 5) {
		limit = this->_turns.getTop() - 5;
	}

	int sum = 0;
	for (size_t i = this->_turns.getTop(); i < limit; i-- ) {
		Turn turn = this->_turns.pop();
		if (turn.getStatusTurn() == StatusTurn::Hit) {
			sum++;
		}
		t.push(turn);
	}

	if (sum == 0)
	{
		return CoordXY(rand() % 10, rand() % 10);
	}	
	
	if (sum == 1) {
		bool h = false;
		int count = 0;
		int x_1, y_1;
		for(size_t i = t.getTop(); i >= 0; i--)
		{
			Turn turn = t.pop();
			if (turn.getStatusTurn() == StatusTurn::Hit) {

				x_1 = turn.getRow();
				y_1 = turn.getColumn();
				h = !h;
			}
			if (h) {
				count++;
			}
			this->_turns.push(turn);

		}

		
			if (count == 0)
			{
				return CoordXY(x_1, y_1 - 1);
			}
			else if (count = 1)
			{
				return CoordXY(x_1 - 1, y_1);
			}
			else if (count == 2)
			{
				return CoordXY(x_1, y_1 + 1);
			}
			else if (count == 3)
			{
				return CoordXY(x_1 + 1, y_1);
			}
		
	}

	if (sum == 2) {
		int x_1, y_1, x_2, y_2;
		bool ctrl = true;
		for (size_t i = t.getTop(); i >= 0; i--)
		{
			Turn turn = t.pop();
			if (ctrl) {
				if (turn.getStatusTurn() == StatusTurn::Hit) {

					x_1 = turn.getRow();
					y_1 = turn.getColumn();

				}
				ctrl = !ctrl;
			}
			else {
				if (turn.getStatusTurn() == StatusTurn::Hit) {

					x_2 = turn.getRow();
					y_2 = turn.getColumn();

				}
			}
			this->_turns.push(turn);

		}

		if (x_2 - x_1 == 1 && y_2 == y_1)
		{
			return CoordXY(x_2 + 1, y_2);
		}
		if (x_2 - x_1 == -1 && y_2 == y_1)
		{
			return CoordXY(x_1 - 1, y_2);
		}
		if (y_2 - y_1 == 1 && x_2 == x_1)
		{
			return CoordXY(x_2, y_2 + 1);
		}
		if (y_2 - y_1 == -1 && x_2 == x_1)
		{
			return CoordXY(x_1, y_2 - 1);
		}
	}
	
	return CoordXY();
}
