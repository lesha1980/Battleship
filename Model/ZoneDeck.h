#pragma once

class ZoneDeck {

	CoordXY _coord_1;
	CoordXY _coord_2;
	CoordXY _coord_3;
	CoordXY _coord_4;
	
public:
	ZoneDeck();
	ZoneDeck(CoordXY coord_1, CoordXY coord_2, CoordXY coord_3, CoordXY coord_4);
	CoordXY getCoord_1();
	CoordXY getCoord_2();
	CoordXY getCoord_3();
	CoordXY getCoord_4();
	void setCoord_1(CoordXY coord_1);
	void setCoord_2(CoordXY coord_2);
	void setCoord_3(CoordXY coord_3);
	void setCoord_4(CoordXY coord_4);

};