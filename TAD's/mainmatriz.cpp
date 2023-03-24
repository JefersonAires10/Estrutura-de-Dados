#include <iostream>
#include "Matriz.h"

using namespace std;

int main () {
    int linhas, colunas;
    cin >> linhas >> colunas;

    Matriz matriz(linhas, colunas);
    matriz.print();
}
