#include <iostream>
#include <stack>
#include "Queue.h"

using namespace std;

int main() {

    int Consultas;
    Queue *fila = new Queue();
    cin >> Consultas;

    for (int i = 0; i < Consultas; i++) {
        int consulta = 0;
        int valor;
        cin >> consulta;
        if (consulta == 1) {
            cin >> valor;
            fila->enfileirar(valor);
        }
        else if (consulta == 2) {
            fila->retirar();
        }
        else {
            cout << fila->front() << endl;
        }
    }

    return 0;
}
