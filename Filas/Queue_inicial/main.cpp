#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

int main() {
    Queue<int> fila; // cria fila vazia

    for(int i = 1; i <= 9; i++)
        fila.push(i);  // enfileira

    while(!fila.empty()) {
        cout << fila.front() << endl;
        fila.pop();
    }

}