#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <stack>

class Queue {
private:
    std::stack<int> prateleira;
    std::stack<int> deposito;
    
public:
    Queue() = default;
    void enfileirar(const int value);
    void retirar();
    int front();
};

#endif