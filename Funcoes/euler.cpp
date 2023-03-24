#include <iostream>
#include <iomanip>

using namespace std;

double fatorial (int n) {
    
    double fatorial = 1;
    
    for (int i = n; i >= 1; i--) {
        fatorial *= i;
    }
    
    return fatorial;
}

double euler(int n) {
    double e = 1;
    for (int i = 1; i <= n; i++) {
        e += 1/fatorial(i);
    }
    return e;
}
int main () {
    
    double number;
    cin >> number; 
    
    cout << fixed << setprecision(6) << euler(number) << endl;
    
    return 0;
}