#include <iostream>
#include <cmath>

using namespace std;
   
void Triangulo(int vet[] , int n) {
    if (n < 1) {
        return;
    }
    
    int aux[n - 1];
    
    int j;
    for (j= 0; j < n - 1; j++) {
        int y = vet[j] + vet[j + 1];
        aux[j] = y;
    }
    
    Triangulo(aux, n - 1);
    
    for (int w = 0; w < n ; w++) {

        if(w == n - 1) {
            cout << vet[w] << " ";
        }
        else {
            cout << vet[w] << ", ";
        }
    }
                
    cout << endl;

}
   
int main() {
    
    int total = 0;
    
    int n = 0;
    cin >> n;

    int vet[n];
    for (int i = 0; i < n; i++) {
        cin >> vet[i];
    }

    total = sizeof(vet) / sizeof(vet[0]);
    
    Triangulo(vet, total); 
    
    return 0;
}