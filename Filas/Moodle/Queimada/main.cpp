// Queimada com pilha 
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    
    // leitura da entrada
    string line;
    getline(cin, line);
    // crie uma matriz de char com os tamanhos passados
    // e leia a entrada
    int n, m;
    cin >> n >> m;
    char mat[n][m];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }

    stack<char> pilha;

    for (int i = 0; i < line.size(); i++) {
        if (line[i] == ' ') {
            while (!pilha.empty()) {
                cout << pilha.top();
                pilha.pop();
            }
            cout << " ";
        } else {
            pilha.push(line[i]);
        }
    }
    while (!pilha.empty()) {
        cout << pilha.top();
        pilha.pop();
    }
    cout << endl;
}