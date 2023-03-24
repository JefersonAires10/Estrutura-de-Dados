#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

bool paraVogal(char v) {
    if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u') {
        return true;
    }
    return false;
}

int paraSilabas(string ss) {
    
    int cont_silabas;
    for (int i = 0; i < ss.size(); i++) {
        if(paraVogal(ss[i]) && (!(paraVogal(ss[i + 1])))) {
            cont_silabas++;
        }
        else if (!(paraVogal([ss.size() - 1])))
            cont_silabas++;
    }
    return cont_silabas;
}

int main () {
    
    int repet = 0, espaco = 0, contador = 0, verifica = 0;
    string texto;
    stringstream ss, aux;
    getline(cin, texto);
    ss << texto;
    
    while (ss >> aux) {
        repet = 1;
        verifica = 0;
    }
    
    if (paraSilabas) {
        
        for (int i = 0; i < texto.size(); i++) {
            
            if (paraVogal(texto[i]) && (!(paraVogal(texto[i + 1])))) {
                
                for (int j = 0; i <= 2; i++) {
                        cout << texto[j];
                        j+=2;
                }
                
                verifica = 1;
                
            }
            
            else {
                
                cout << texto[i];
                
            }
            
            
            
        }
    }
}