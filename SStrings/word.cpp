#include <iostream>
#include <iomanip> 
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

int main () {
    
    string texto, aux;
    stringstream p;
    int palavra1 = 0;
    getline (cin, texto);
    p << texto;
    
    char c;
    cin >> c;
    cin.ignore();
    
    for (int i = 0; i < texto.size(); i++) {
        switch (c) {
            case 'M':
            texto[i] = toupper(texto[i]);
            cout << texto[i];
            break;
            
            case 'm': 
            texto[i] = tolower(texto[i]);
            cout << texto[i];
            break;
            
            case 'p':
            while (p >> aux) {
                if (aux.size() > 1) {
                    aux[0] = toupper(aux[0]);
                }
                else if (aux.size() == 1) {
                    aux[0] = tolower(aux[0]);
                }
                if (palavra1 == 0) {
                    cout << aux;
                }
                else {
                    cout << " " << aux;   
                }
                palavra1 = 1;
            }
            break;

            case 'i':
            if (texto[i] >= 'A' && texto[i] <= 'Z') {
                texto[i] = tolower(texto[i]);
                cout << texto[i];
            }
            else if (texto[i] >= 'a' && texto[i] <= 'z') {
                texto[i] = toupper(texto[i]);
                cout << texto[i];
            }
            else if ( ! (isalpha(texto[i]))) {
                cout << texto[i]; 
            }
            break;

        }
    }
    
    return 0;
}