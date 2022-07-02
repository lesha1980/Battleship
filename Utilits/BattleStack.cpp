#include "../libs.h"




template<typename T>
inline bool BattleStack<T>::push(T elem)
{
	if (this->isEmpty()) {
		this->_arr[this->_top] = elem;
		this->_top++;
		return true;
	}
	return false;
}

template<typename T>
T BattleStack<T>::pop()
{
	T elem;
	if (this->isFull()) {
		elem = this->_arr[this->_top];
		this->_top--;
	}
	return elem;
}

template<typename T>
T BattleStack<T>::peek()
{
	T elem;
	if (this->isFull()) {
		elem = this->_arr[this->_top];
		
	}
	return elem;
}

template<typename T>
bool BattleStack<T>::isEmpty()
{
	if (this->_top <= 110 && this->_top >= 0)
		return true;
	return false;
}

template<typename T>
bool BattleStack<T>::isFull()
{
	if (this->_top > 110)
		return true;
	return false;
}
