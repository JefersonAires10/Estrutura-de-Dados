//nao sei o tipo da variável, auto.
// vector<int>::iterator = auto;

#include <iostream>

#include <vector>

using namespace std;

void imprimir(const vector <int> & vec) {

    for (auto it = vec.begin(); it != vec.end(); it++) { 

        cout << *it << " ";

    }

    cout << endl;
    
}

int main() { 

    vector <int> vec { 5, 5, 1, 2, 3, 5, 5, 4, 5, 6, 7, 8, 5, 5, 5 };

    imprimir(vec);

    auto it = vec.begin();

    while ( it != vec.end()) {

        if (*it == 5) {

            vec.erase(it);

        }

        else {

            it++;

        }

    }

    imprimir(vec);

}
