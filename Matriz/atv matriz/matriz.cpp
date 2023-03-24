// Arquivo de Implementacao do TAD Matriz
#include <iostream>
#include <iomanip>
#include "Matriz.h"
using namespace std;

// Aloca espaco dinamicamente para matriz com m lin e n col
Matriz::Matriz(int m, int n)
{
	this->lin = m;
	this->col = n;
	
	this->mat = new int *[m];
	for (int i = 0; i < m; i++)
	{
		this->mat[i] = new int[n];
	}
	
}

// Destrutor: Libera a memoria que foi alocada dinamicamente no construtor
Matriz::~Matriz()
{
	for (int i = 0; i < lin; i++)
	{
		delete[] mat[i];
	}
	delete[] mat;
	std::cout << "matriz liberada" << std::endl;
}

// Retorna o numero de lin da matriz
int Matriz::linhas()
{
	return this->lin;
}

// Retorna o numero de col da matriz
int Matriz::colunas()
{
	return this->col;
}

// Retorna o valor da celula [i][j] da matriz
int Matriz::getValor(int i, int j)
{
	return this->mat[i][j];
}

// Atribui valor a celula [i][j] da matriz
void Matriz::setValor(int valor, int i, int j)
{
	this->mat[i][j] = valor;
}

// Imprimir a matriz
void Matriz::print()
{
	for (int i = 0; i < lin; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			cout << setw(7) << mat[i][j];
		}
		cout << "\n";
	}
}

// Soma matrizes
Matriz *Matriz::soma(Matriz &B)
{
	if (this->lin != B.lin || this->col != B.col)
	{
		return nullptr;
	}
	else
	{
		Matriz *mat = new Matriz(this->lin, this->col);
		for (int i = 0; i < lin; i++)
		{
			for (int j = 0; j < col; j++)
			{
				mat->mat[i][j] = this->mat[i][j] + B.mat[i][j];
			}
		}
		return mat;
	}
}

// Multiplica matrizes
Matriz *Matriz::multiplica(Matriz &B)
{
	if (!(this->col == B.lin))
	{
		return nullptr;
	}
	
	Matriz *newMat = new Matriz(this->lin, B.col);
	for (int i = 0; i < this->lin; i++)
	{
		for (int j = 0; j < B.col; j++)
		{
			for (int w = 0; w < this->col; w++)
			{
				newMat->mat[i][j] += this->mat[i][w] * B.mat[w][j];
			}
		}
	}
    return newMat;
}