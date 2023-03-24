#include <iostream>
#include <cstdlib> // pesquisar: biblioteca <random>
#include <chrono>
#include <string>
using namespace std;

// algoritmo de ordenacao bubblesort --- complexidade O(n^2)
// muito lento para arrays muito grandes




template <typename T>
void selectionsort(T A[], int l, int r ) {
    for (int i = l; i < r; i++) {
        int indexMin = i;
        for (int j = i + 1; j <= r; j++) {
            if (A[j] < A[indexMin]) 
                indexMin = j;
        }
        int aux = A[i];
        A[i] = A[indexMin];
        A[indexMin] = aux;
    }
}

template< typename T >
void print(T A[], int l, int r) {
    for(int i = l; i <= r; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template< typename T >
void testa_algoritmo(T A[], int l, int r, string name, void (*func)(T[], int, int)) {
    auto start = std::chrono::steady_clock::now();
    func(A, l, r);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    auto duration = 
        std::chrono::duration_cast<std::chrono::nanoseconds>(elapsed_time);
    cout << name << " time: " << duration.count() << " nanoseconds" << endl;
}

int main() {
    const int n = 9000;
    int vec[n], vec2[n], vec3[n];
    for(int i = 0; i < n; i++) {
        vec[i] = vec2[i] = vec3[i] = rand() % 1000;
    }
    cout << endl;
    testa_algoritmo(vec, 0, n-1, "bubblesort", bubblesort);
    cout << endl;
    testa_algoritmo(vec2, 0, n-1, "insertionsort", insertionsort);
    cout << endl;
    testa_algoritmo(vec3, 0, n-1, "selectionsort", selectionsort);
    cout << endl;
}
