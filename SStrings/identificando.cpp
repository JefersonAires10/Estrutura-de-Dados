#include <iostream>
#include <iomanip> 
#include <string>
#include <sstream>

using namespace std;
bool paraStr(string a) {
    
    for (int i = 0; i < a.size(); i++) {
        if (isalpha(a[i])) {
            return true;
        }
    }
    return false;
}
bool paraFloat(string a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            return true;
        }
    }
    return false;
}

int main () {
    
    string texto, auxiliar;
    stringstream stream;
    
    getline (cin, texto);
    stream << texto;

    while (stream >> auxiliar) {
        
        if (paraStr(auxiliar)) {
            cout << "str" << " ";
        }
        else if (paraFloat(auxiliar)) {
            cout << "float" << " ";
        }
        else {
            cout << "int" << " ";
        }
    }
    
    
}