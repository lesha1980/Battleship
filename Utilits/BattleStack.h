#pragma once

template<typename T> 
 class BattleStack {

    T _arr[110];
    int _top;

public:
    BattleStack<T>() {
        this->_top = 0;
    }
    bool push(T elem) {
        if (this->isEmpty()) {
            this->_arr[this->_top] = elem;
            this->_top++;
            return true;
        }
        return false;
    }
    T pop() {
        T elem;
        if (this->isFull()) {
            elem = this->_arr[this->_top];
            this->_top--;
        }
        return elem;
    }
    T peek() {
        T elem;
        if (this->isFull()) {
            elem = this->_arr[this->_top];

        }
        return elem;
    }
    bool isEmpty() {
        if (this->_top <= 110 && this->_top >= 0)
            return true;
        return false;
    }
    bool isFull() {
        if (this->_top > 110)
            return true;
        return false;
    }

};
