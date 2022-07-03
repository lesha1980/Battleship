#include "../libs.h"

Gamer::Gamer(string login)
{
    this->_login = login;
    
}

string Gamer::getLogin()
{
    return this->_login;
}

void Gamer::setTurn(Turn turn)
{
    this->_turns.push(turn);
}

Turn Gamer::theLastTurn()
{
    return this->_turns.peek();
}





