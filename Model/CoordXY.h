#pragma once

class CoordXY {
	int _x;
	int _y;

public:
	CoordXY();
	CoordXY(int x, int y);
	int getX();
	int getY();
	void setX(int x);
	void setY(int y);

	CoordXY operator+(CoordXY& coord);
	CoordXY operator-(CoordXY& coord);
	bool operator<(const CoordXY& coord);
	bool operator>(const CoordXY& coord);
	bool operator<=(const CoordXY& coord);
	bool operator>=(const CoordXY& coord);
	bool operator==(const CoordXY& coord);
	bool operator!=(const CoordXY& coord);
	

};
