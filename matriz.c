#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

float **DeclararMatriz(int linhas, int colunas) {

	float **Matriz;
	int i, j;

	Matriz = (float**)malloc(linhas*sizeof(float*));
	for (i = 0; i < linhas; ++i)
	{
		Matriz[i] = (float*)malloc(colunas*sizeof(float));

	}

	return Matriz;
}

void DestruirMatriz(float **Matriz,int linhas, int colunas) {

	int i;

	for (i = 0; i < linhas; ++i)
	{
		free(Matriz[i]);
	};

	free(Matriz);
}

void ImprimirMatriz(float **Matriz, int linhas, int colunas) {

	int i, j;
	
	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			printf("%6.2f", Matriz[i][j]);			
		}
		printf("\n");
	}
	printf("\n");
}

void AtribuirEleMatriz(float **Matriz, int linha, int coluna, float n) {

	Matriz[linha - 1][coluna - 1] = n;
}


void AtribuirLinMatriz(float **Matriz, int linha, int quantidade, float n[]){

	int i;

	for (i = 0; i < quantidade; i++)
	{
		Matriz[linha-1][i] = n[i];
	}

}


void AtribuirColMatriz(float **Matriz, int coluna, int quantidade, float n[]){

	int i;

	for (i = 0; i < quantidade; i++)
	{
		Matriz[i][coluna - 1] = n[i];
	}
}

float **TransporMatriz(float **Matriz, int linhas, int colunas) {

	float **aux;
	int i, j;

	aux = (float**)malloc(linhas*sizeof(float*));

	for (i = 0; i < linhas; ++i)
	{
		aux[i] = (float*)malloc(colunas*sizeof(float));

	}

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			aux[i][j] = Matriz[j][i];
		}
	}

	return aux;
}

float **SomarMatriz(float **Matriz1,float **Matriz2, int linhas, int colunas) {

	float **aux;
	int i, j;
		
		aux = (float**)malloc(linhas*sizeof(float*));

		for (i = 0; i < linhas; ++i)
		{
			aux[i] = (float*)malloc(colunas*sizeof(float));
		}

		for (i = 0; i < linhas; i++)
		{
			for (j = 0; j < colunas; j++)
			{
				aux[i][j] = Matriz1[i][j] + Matriz2[i][j];
			}
		}
		return aux;

}

float **DividirMatriz(float **Matriz1, float **Matriz2, int linhas, int colunas) {

	float **aux;
	int i, j;

	aux = (float**)malloc(linhas*sizeof(float*));

	for (i = 0; i < linhas; ++i)
	{
		aux[i] = (float*)malloc(colunas*sizeof(float));
	}

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			aux[i][j] = Matriz1[i][j] / Matriz2[i][j];
		}
	}
	return aux;

}

float **MultiplicarMatriz(float **Matriz1, float **Matriz2, int linhas1, int colunas2, int Colunas1Linhas2) {

	float **aux, auxi;
	int i, j, k;

		aux = (float**)malloc(linhas1*sizeof(float*));

		for (i = 0; i < linhas1; ++i)
		{
			aux[i] = (float*)malloc(colunas2*sizeof(float));
		}

		for (i = 0; i < linhas1; i++)
		{
			for (j = 0; j < colunas2; j++)
			{
				auxi = 0;
				for (k = 0; k < Colunas1Linhas2; k++)
				{
					auxi = auxi + (Matriz1[i][k] * Matriz2[k][j]);
				}

				aux[i][j] = auxi;
			}
		}

		return aux;
}

float **Multiplicar2Matrizes(float **Matriz1, float **Matriz2, int linhas, int colunas) {

	float **aux;
	int i, j;

	aux = (float**)malloc(linhas*sizeof(float*));

	for (i = 0; i < linhas; ++i)
	{
		aux[i] = (float*)malloc(colunas*sizeof(float));
	}

	for (i = 0; i < linhas; i++)
	{
		for (j = 0; j < colunas; j++)
		{
			aux[i][j] = Matriz1[i][j] * Matriz2[i][j];
		}
	}
	return aux;
}
