#include <iostream>

using namespace std;

int main() {
    int matriz[3][3];
    for(int l = 0; l < 3; l++){
        for(int c = 0; c < 3; c++){
            cin >> matriz[l][c];
        }
    }
    
    int cont = 0;

    if(matriz[0][0] > matriz[1][0])
        cont++;
    if(matriz[1][0] > matriz[2][0])
        cont++;
 
    if(matriz[0][1] > matriz[1][1])
        cont++;
    if(matriz[1][1] > matriz[2][1])
        cont++;
    
    if(matriz[0][2] > matriz[1][2])
        cont++;
    if(matriz[1][2] > matriz[2][2])
        cont++;

    cout << cont << endl;
    
}