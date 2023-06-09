#include <iostream>
#include <stack>
#include <string>
#include "Stack.h"
using namespace std;

string reverse(string line) {
    Stack<char> pilha;
    string str;
    for (int i = 0; i <= line.size(); i++) {
        if (line[i] == ' ' || line[i] != '\0') {
            pilha.push(line[i]);
        }
        else {
            while (!pilha.empty()) {
                str += pilha.top();
                pilha.pop();
            }
            str += " ";
        }
    }
    return str;
}

int main() {
    
    Stack<int> *pilha = new Stack<int>();
    for (int i = 55; i <= 62; i++) {
        pilha->push(i);
    }
    while (!pilha->empty()) {
        cout << pilha->top() << endl;
        pilha->top();
    }

    delete pilha;
}