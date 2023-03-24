#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main () {
    
    int cont1 = 0, cont2 = 0;
    int quantidade_de_produtos = 0;
    cin >> quantidade_de_produtos; 
    
    float valor_do_produto[quantidade_de_produtos];
    float chute1[quantidade_de_produtos];
    char chute2[quantidade_de_produtos];
    
    
    for (int i = 0; i < quantidade_de_produtos; i++) {
        cin >> valor_do_produto[i];
    }
    for (int i = 0; i < quantidade_de_produtos; i++) {
        cin >> chute1[i];
    }
    for (int i = 0; i < quantidade_de_produtos; i++) {
        cin.ignore() >> chute2[i];
    }
    
    for (int i = 0; i < quantidade_de_produtos; i++) {
        if (chute1[i] == valor_do_produto[i]) {
            cont1++;
        }
        else if (chute1[i] > valor_do_produto[i] && chute2[i] == 'm') {
            cont2++;
        }
        else if (chute1[i] < valor_do_produto[i] && chute2[i] == 'M') {
            cont2++;
        }
        else {
            cont1++;
        }
        
    }
    if (cont1 > cont2) { 
        cout << "primeiro" << endl;
    }
    else if (cont1 < cont2) {
        cout << "segundo" << endl;
    }
    else {
        cout << "empate"  << endl;
    }
    
    return 0;
}