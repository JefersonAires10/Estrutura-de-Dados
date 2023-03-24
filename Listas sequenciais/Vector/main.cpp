#include <iostream>
#include "Vector.h"
using namespace std;

void print (const Vector& lst) {
	cout << "Capacity: "<< lst.capacity() << endl;
	cout << "Size: "<< lst.size() << endl;
	
	for (int i = 0; i < lst.size(); i++){
		cout << lst[i] << " ";
	}
	cout << endl;
}

int main () {
	Vector lista;

	for (int i = 21; i < 58; i++) {
 		lista.push_back (i);
    }
	print(lista);
}