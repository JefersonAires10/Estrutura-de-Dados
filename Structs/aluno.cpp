#include <iostream>
#include <iomanip> 
#include <string>
#include <cctype>

using namespace std;

struct Aluno {

    string nome;
    int matricula;
    string disciplina;
    double nota;

};

int paraAluno(int x) {

    if (x >= 7) {
        cout << " aprovado(a) em ";  
    }
    else if (x < 7) {
        cout << " reprovado(a) em ";
    }
    
    return x;
    
}  

int main () {

    Aluno jef; 

    cin >> jef.nome;
    cin >> jef.matricula;
    cin >> jef.disciplina;
    cin >> jef.nota;

    cout << jef.nome;
    
    paraAluno(jef.nota);
    
    cout << jef.disciplina;
    
    return 0;
    
}
