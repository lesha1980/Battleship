#include "../libs.h"



void BattleShipMapBindingService::initGameBoardContext(GameBoard gameBoard, Ship** ships)
{
    Cell** _board = this->_gameBoard.getBoard();
	for (size_t i = 0; i < 10; i++) {
		switch (this->_ships[i]->getTypeShip()) {
		case TypeShip::SingleDeckShip:{
			SingleDeck sd = (SingleDeck&)this->_ships[i];
			Deck d = sd.getDeck();
			_board[d.getX()][d.getY()].setStatusCell(StatusCell::Occupied);
			}break;
		case TypeShip::DoubleDeckShip: {
			DoubleDeck sd = (DoubleDeck&)this->_ships[i];
			Deck d_1 = sd.getDeck_1();
			Deck d_2 = sd.getDeck_2();
			_board[d_1.getX()][d_1.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_2.getX()][d_2.getY()].setStatusCell(StatusCell::Occupied);
		}break;
		case TypeShip::ThreeDeckShip: {
			ThreeDeck sd = (ThreeDeck&)this->_ships[i];
			Deck d_1 = sd.getDeck_1();
			Deck d_2 = sd.getDeck_2();
			Deck d_3 = sd.getDeck_3();
			_board[d_1.getX()][d_1.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_2.getX()][d_2.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_3.getX()][d_3.getY()].setStatusCell(StatusCell::Occupied);
		}break;
		case TypeShip::FourDeckShip: {
			FourDeck sd = (FourDeck&)this->_ships[i];
			Deck d_1 = sd.getDeck_1();
			Deck d_2 = sd.getDeck_2();
			Deck d_3 = sd.getDeck_3();
			Deck d_4 = sd.getDeck_4();
			_board[d_1.getX()][d_1.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_2.getX()][d_2.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_3.getX()][d_3.getY()].setStatusCell(StatusCell::Occupied);
			_board[d_4.getX()][d_4.getY()].setStatusCell(StatusCell::Occupied);

		}break;
		}
	}

	this->_gameBoard.setCellsBoard(_board);
}

GameBoard BattleShipMapBindingService::getGameBoard()
{
	return this->_gameBoard;
}

Ship** BattleShipMapBindingService::getShips()
{
	return this->_ships;
}


