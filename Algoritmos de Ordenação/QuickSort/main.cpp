#include <iostream>
#include <cstdlib> // pesquisar: biblioteca <random>
#include <chrono>
#include <string>
using namespace std;

// algoritmo de ordenacao bubblesort --- complexidade O(n^2)
// muito lento para arrays muito grandes


//algoritmo para particionar um array em dois subarrays 
int partition(int A[], int l, int r) {
    int pivo = A[r];
    int j = l;
    for (int k = l; k < r; k++) {
        if (A[k] <= pivo) {
            int aux = A[k];
            A[k] = A[j];
            A[j] = aux;
            j++;
        }
    }
    A[r] = A[j];
    A[j] = pivo;
    return j;
}

// Quicksort
// ordena do indice l ou r
void quicksort(int A[], int l, int r) {
    if (l < r) {
        int p = partition(A, l, r);
        quicksort(A, l, p - 1);
        quicksort(A, p + 1, r);
    }
}

template< typename T >
void print(T A[], int l, int r) {
    for(int i = l; i <= r; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

template <typename T>
void teste_algoritmo(T A[], int l, int r, string name, void (*func)(T[], int, int)) {
    auto start = std::chrono::steady_clock::now();
    func(A, l, r);
    auto end = std::chrono::steady_clock::now();
    auto elapsed_time = end - start;
    auto duration = 
        std::chrono::duration_cast<std::chrono::seconds>(elapsed_time);
    cout << "BublleSort Time: " << duration.count() << "s\n";
}

int main() {
    const int n = 9000;
    int vec[n];
    for(int i = 0; i < n; i++) {
        vec[i] = rand() % 1000;
    }
    cout << endl;
    testa_algoritmo(vec, 0, n-1, "quicksort", quicksort);
    cout << endl;   
}
