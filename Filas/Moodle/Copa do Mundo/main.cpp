#include <iostream>
#include <queue>
using namespace std;

int main() {

    queue<char> Equipe; // crio uma fila para armazenar as equipes
    
    for (int i = 'A'; i <= 'P'; ++i) { // percorro as 16 equipes
        Equipe.push(i); // adiciono a equipe na fila 
    }
    for (int i = 0; i < 15; i++) {
        int result1, result2; // placar da partida
        cin >> result1 >> result2;
        int aux1, aux2; // variaveis auxiliares para armazenar os resultados
        aux1 = Equipe.front();
        Equipe.pop();
        aux2 = Equipe.front();
        Equipe.pop();

        if (result1 > result2) { // comparo os placares
            Equipe.push(aux1); // adiciono a equipe 1 no final da fila
        }
        else {
            Equipe.push(aux2); // adiciono a equipe 2 no final da fila, caso tenha um maior placar
        }
    }
    cout << Equipe.front() << endl; // letra da equipe vencedora
}