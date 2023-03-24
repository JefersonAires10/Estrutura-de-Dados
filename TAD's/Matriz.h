#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

class Matriz
{
private:
    int linhas;  // numero de linhas
    int colunas; // numero de colunas
    int **mat;   // ponteiro de matriz

public:
    // Constructor
    Matriz(int n, int m)
    {
        linhas = n;
        colunas = m;

        mat = new int *[n];
        for (int i = 0; i < n; i++)
        {
            mat[i] = new int[m]{0};
        }
        std::cout << "Matriz Criada" << std::endl;
    }
    void print()
    {
        for (int i = 0; i < linhas; i++)
        {
            for (int j = 0; j < colunas; j++)
            {
                std::cout << mat[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    ~Matriz()
    {
        for (int i = 0; i < linhas; i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
        std::cout << "Matriz deleted" << std::endl;
    }
};

#endif
