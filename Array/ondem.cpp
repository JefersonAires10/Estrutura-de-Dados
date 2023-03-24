#include <iostream>

using namespace std;

int verifica (int v[], int n) { //n é o tamanho do vetor
    if (n > 1) {
        for (int i = 1; i < n; i++) { 
            if (v[i-1] > v[i]) {
                return 0;
            } 
        }
        return 1;
    }
}
int main() {

    int vetor[7] = {1, 2, 3, 9, 6, 3}; //pode ser mudado para ler os valores

    if(verifica(vetor, 5)){
        printf("Esta em ordem crescente");
    } else{
        printf("Nao esta em ordem crescente");
    }

    return 0;
}
