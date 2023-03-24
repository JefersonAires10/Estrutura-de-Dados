#include <iostream>
#include <string>

using namespace std;

// Retorna o números de ocorrências do caractere 'c' na string 'str' (com 'n' caracteres).
// Algoritmo deve ser recursivo e sem comandos de repetição.

int contaCaracteres(string str, int n, char c) {
    
    int j = n - 1; 
    
    if (j < 0) {
        return 0;
    }
    
    else {
        if (c == str[j]) {
            return contaCaracteres(str, j--, c) + 1;    
            
        }
        else {
            return contaCaracteres(str, j--, c);
        }
    }
}

int main() {
    
    char caracter;
    string str;
    getline(cin,str);
    
    cin >> caracter;
    
    int tamanho = contaCaracteres(str, (int)str.size(), caracter);
    cout << tamanho; 
    
    return 0;
}