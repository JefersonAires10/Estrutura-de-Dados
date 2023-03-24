#include <iostream>
#include <iomanip> 
#include <string>
#include <cctype>

using namespace std;

bool paraVogal(char v) {
    if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u') {
        return true;
    }
    return false;
}

int main () {
    
    string txt;
    getline(cin, txt);
    
    for (int i = 0; i < txt.size(); i++) {
        if ((txt[i] == ' ') && ((paraVogal(txt[i - 1]) == true) && (paraVogal(txt[i + 1]) == true))) {
            i += 2;
            if (txt[i] == ' ') {
                cout << txt[i + 2];
                i += 2;
            }
            else {
                cout << txt[i]; 
            }
        }
        else {
            cout << txt[i];
        }
    }
    
    return 0;
    
}