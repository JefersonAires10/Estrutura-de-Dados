#include <iostream>

using namespace std;

int main () {
    
    int matriz[3][3];
    int somal0 = 0, somal1 = 0, somal2 = 0;
    int somac0 = 0, somac1 = 0, somac2 = 0;
    int somaDP = 0, somaDS = 0;
    
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            cin >> matriz[l][c];
        }
    }
      
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somal0 = matriz[0][0] + matriz[0][1] + matriz[0][2];
//        }
//    }
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somal1 = matriz[1][0] + matriz[1][1] + matriz[1][2];
//        }
//    }
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somal2 = matriz[2][0] + matriz[2][1] + matriz[2][2];
//       }
//    }
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somac0 = matriz[0][0] + matriz[1][0] + matriz[2][0];
//        }
//    }
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somac1 = matriz[0][1] + matriz[1][1] + matriz[2][1];
//        }
//  }
//    for (int l = 0; l < 3; l++) {
//        for (int c = 0; c < 3; c++) {
            somac2 = matriz[0][2] + matriz[1][2] + matriz[2][2];
//        }
//    }
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            somaDP = matriz[0][0] + matriz[1][1] + matriz[2][2];
        }
    }
    for (int l = 0; l < 3; l++) {
        for (int c = 0; c < 3; c++) {
            somaDS = matriz[0][2] + matriz[1][1] + matriz[2][0];
        }
    }
    
    if (somal0 == somal1 && somal1 == somal2 && 
    somal2 == somac0 && somac0 == somac1 && 
    somac1 == somac2 && somac2 == somaDP && somaDP == somaDS) {
        cout << "sim" << endl;
        
    }
    else {
        cout << "nao" << endl;
    }
    
    return 0;
}

//00 01 02
//10 11 12
//20 21 22