#include <iostream>
#include <iomanip>

using namespace std;

bool primo (int n) {
    
    for (int i = 2; i < n - 1; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (primo(i) == true) {
            cout << i << endl;
        }
    }

}