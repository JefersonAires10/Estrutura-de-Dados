#include <iostream>
#include <iomanip> 
#include <string>
#include <cctype>

using namespace std;

struct Registro {
        
    string nome;
    int matricula;
    string disciplina;
    double nota;
    
};

Registro leAluno() {

    Registro alunoA;
    Registro alunoB;
    
    cin >> alunoA.nome; 
    cin >> alunoA.matricula; 
    cin >> alunoA.disciplina; 
    cin >> alunoA.nota;
    
    cin >> alunoB.nome; 
    cin >> alunoB.matricula;
    cin >> alunoB.disciplina; 
    cin >> alunoB.nota;

}

void paraAlunos(Registro x, Registro y) {
    if (x.nota == y.nota) {    
        cout << x.nome << ", " << showpoint << fixed << setprecision(1) << x.nota;
    }
    else if (x.nota > y.nota) {   
        cout << x.nome << ", " << showpoint << fixed << setprecision(1) << " " << x.nota;
    }
    else {   
        cout << y.nome << "," << showpoint << fixed << setprecision(1) << y.nota;
    } 
}

int main () {
 
    Registro AlunoA, AlunoB; 
    
    AlunoA = leAluno();
    AlunoB = leAluno();

    paraAlunos(AlunoA, AlunoB); 

}