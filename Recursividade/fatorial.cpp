#include <iostream>

using namespace std;

int fatorial(int numero) {
    
    if (numero <= 1) {
        return 1;
    }
    else {
        return numero * fatorial(numero- 1);
    }

}

int main () {

    int Numero;
    cout << "Digite um numero: ";
    cin >> Numero;
    cout << "O fatorial deste numero eh: " << fatorial(Numero) << endl;
    
}