#include <sstream> //cabeçalho que contém o tipo de dado stringstream
#include <vector>  //cabeçalho que contém a estrutura de dados vector
#include <string>
#include <iostream>

using namespace std;

void printVector(vector<int> vector, int vect) {
    
    if (vect == 1) {
        cout << vector[vect - 1] << " ";
    }
    else {
        printVector(vector, vect - 1); 
        cout << vector[vect - 1] << " ";
    }

}
void printContrario(vector<int> vector, int vect) {
    
    if (vect == 1) {
        cout << vector[vect - 1] << " ";
    }
    else { 
        cout << vector[vect - 1] << " ";
        printContrario(vector, vect - 1);
    }

}
void printInverso(vector<int> vector, int a, int b) {
    int aux;
    if (a < b) {
        aux = vector[a];
        vector[a] = vector[b - 1];
        vector[b - 1] = aux;
        printInverso(vector, a + 1, b - 1);
    }
}
int printSoma(vector<int> vector, int vect) {
    
    if (vect == 1) {
        return vector[vect - 1];
    }
    else {
        return vector[vect - 1] + printSoma(vector, vect - 1);
    }

}
int printMultiplicacao(vector<int> vector, int vect) {
    
    if (vect == 1) {
        return vector[vect - 1];
    }
    else {
        return vector[vect - 1] * printMultiplicacao(vector, vect - 1);
    }

}
int printMenor(vector<int> vector, int vect) {
    
    if (vect == 1) {
        return vector[vect - 1];
    }
    else {
        int menor;
        menor = printMenor(vector, vect - 1);
        if (menor < vector[vect - 1]) {
            return menor;
        }
        else {
            return vector[vect - 1];
        }
    }

}

int main() {
    
    string str; 
    getline(cin, str);
    stringstream sstr(str);
    vector <int> vetor;

    int valor;
    while (sstr >> valor) {
        vetor.push_back(valor);
    }
    //imprime o vector que foi passado
    cout << "vet: [ "; 
    printVector(vetor, vetor.size());
    cout << "]" << endl;

    // imprime o vector que foi passado revertido, da última posição para a primeira;
    cout << "rvet: [ "; 
    printContrario(vetor, vetor.size());
    cout << "]" << endl;
    
    // imprime a soma dos elementos do vector;
    cout << "sum: " << printSoma(vetor, vetor.size()) << endl; 

    // imprime a multiplicação dos elementos do vector;
    cout << "mult: " << printMultiplicacao(vetor, vetor.size()) << endl;
    
    // imprime o menor elemento do vector;
    cout << "min: " << printMenor(vetor, vetor.size()) << endl;

    // imprime o vector invertido, a mesma coisa do printContrario
    cout << "inv: [ "; 
    printContrario(vetor, vetor.size());
    cout << "]" << endl;
    
}