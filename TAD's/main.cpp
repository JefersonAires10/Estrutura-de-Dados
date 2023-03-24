#include <iostream>
#include "point.h"
using namespace std;

int main() {

    Point p1(3.0, 4.0);
    Point p2(5.0, 9.0);
    
    cout << "distancia entre p1 e p2: " << p1.distancia(p2) << endl;
    cout << "distancia entre p2 e p1: " << p2.distancia(p1) << endl;    

    Point *pPonto = new Point(7.8, 6.7);
    delete pPonto; 

}

