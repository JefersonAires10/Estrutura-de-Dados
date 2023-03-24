#include <iostream>
#include <chrono>
#include <cstdlib> // ramdom
#include <string>
using namespace std;

// // algoritmo de ordenacao bubblesort --- complexidade O(n^2)
template <typename T>
void BublleSort(T A[], int l, int  r) {
    bool trocou = true;
    for (int i = l; i < r && trocou; ++i) {
        trocou = false;
        for (int j = r; j > i; j--) {
            if (A[j] < A[j - 1]) {
                T aux = A[j];
                A[j] = A[j - 1];
                A[j - 1] = aux;
                trocou = true;
            }
        }
    }
}

template <typename T>
void print (T A[], int l, int r) {
    for (int i = l; i <= r; i++) {
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
    int tamanho = 100000;

    int vec[tamanho];

    for (int i = 0; i < tamanho; i++) {
        vec[i] = 1 + rand() % 1000;
    }
    //int vec[] = {23,45,1,2,7,5,99,23,90,75,43,12,78,7,5,4,4,3};
    int n = sizeof(vec) / sizeof(vec[0]);

    teste_algoritmo(vec, 0, n-1, "BublleSort", BublleSort);

}