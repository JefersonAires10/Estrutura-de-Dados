#include <iostream>
#include <iomanip> 

using namespace std;

int main () {
    
    int n;
    cin >> n;
    int vetor[n];
    
    for (int i = 0; i < n; i++) {
        cin >> vetor[i];
    }
    
    for (int i = 1; i <= n; i++) {
        if (vetor[i - 1] > vetor[i]) {
            cout << "precisa de ajuste" << endl;
            return 0;
            
        }
    }
    
    cout << "ok" << endl;
    
    return 0;
}