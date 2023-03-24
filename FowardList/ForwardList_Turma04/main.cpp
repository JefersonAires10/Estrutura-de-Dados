#include <iostream>
#include "ForwardList.h"
using namespace std;

int main() {
    ForwardList lst;

    for(int i = 1; i <= 9; i++) 
        lst.push_back(i * 0.7);
    
    cout << lst.toString() << endl;
}