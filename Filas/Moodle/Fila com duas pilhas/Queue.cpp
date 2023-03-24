#include <iostream>
#include <stack>
#include "Queue.h"

using namespace std;

void Queue::enfileirar(const int value) {
    while (!prateleira.empty()) {
        deposito.push(prateleira.top());
        prateleira.pop();
    }
    prateleira.push(value);
    
    while (!deposito.empty()) {
        prateleira.push(deposito.top());
        deposito.pop();
    }
}

void Queue::retirar() {
    if (!prateleira.empty()) {
        prateleira.pop();
    }
}

int Queue::front() {
    if (!prateleira.empty()) {
        return prateleira.top();
    }
}