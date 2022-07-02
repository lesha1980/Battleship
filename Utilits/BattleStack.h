#pragma once

template<typename T> 
 class BattleStack {

    T _arr[110];
    int _top;

public:
    BattleStack() {
        this->_top = 0;
    }
    bool push(T elem);
    T pop();
    T peek();
    bool isEmpty();
    bool isFull();

};
