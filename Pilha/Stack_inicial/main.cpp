#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack<int> pilha;

    for(int i = 1; i <= 9; i++)
        pilha.push(i);

    while (!pilha.empty()) {
        cout << pilha.top() << " ";
        pilha.pop();
    }
    cout << endl;
}
