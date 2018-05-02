#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

int **DeclararMatriz(int linhas, int colunas) {

	int **Matriz;
	int i;

	Matriz = (int**)malloc(linhas*sizeof(int*));
	for (i = 0; i < linhas; ++i)
	{
		Matriz[i] = (int*)malloc(colunas*sizeof(int));
	}

	return Matriz;
}

/*
void DestruirMatriz(int linhas, int colunas, int Matriz[][]){
  
 for (i = 0; i < linhas; ++i)
	{
		free(Matriz[i]);
	};

	free(Matriz);

}*/

void ImprimirMatriz(No **Matriz, char nome[]) {

	int i, j;
	No *encontrado = Percorre(Matriz, nome);

	if (encontrado == NULL)
	{
		printf("Erro: Matriz nao encontrada\n\n");
	}
	else
	{
		for (i = 0; i < encontrado->linhas; i++)
		{
			for (j = 0; j < encontrado->colunas; j++)
			{
				printf("%6.2d", encontrado->matriz[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
}

void AtribuirEleMatriz(No **Matriz, char nome[], int linha, int coluna, int n) {

	No *encontrado = Percorre(Matriz, nome);

	if (encontrado == NULL)
	{
		printf("Erro: Matriz solicitada nao existe\n\n");
	}
	else if (linha > encontrado->linhas || coluna > encontrado->colunas)
	{
		printf("Erro: Posicao maior do que dimensoes\n\n");
	}
	else
	{
		encontrado->matriz[linha - 1][coluna - 1] = n;
		printf("OK\n\n");
	}
}


void AtribuirLinMatriz(){


}


void AtribuirColMatriz(){


}

void TransporMatriz(No **Matriz, char nome[], char nomeResultado[]) {

	int **aux, i, j;
	No *encontrada = Percorre(Matriz, nome);

	aux = (int**)malloc(encontrada->colunas*sizeof(int*));

	for (i = 0; i < encontrada->colunas; ++i)
	{
		aux[i] = (int*)malloc(encontrada->linhas*sizeof(int));
	}

	for (i = 0; i < encontrada->linhas; i++)
	{
		for (j = 0; j < encontrada->colunas; j++)
		{
			aux[j][i] = encontrada->matriz[i][j];
		}
	}

	CriaNova(Matriz, aux, nomeResultado, encontrada->colunas, encontrada->linhas);
	ImprimirMatriz(Matriz, nomeResultado);
}

void SomarMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]) {

	int **aux, i, j;

	No *encontrada1 = Percorre(Matriz, nomePrimeira);
	No *encontrada2 = Percorre(Matriz, nomeSegunda);

	if (encontrada1 == NULL || encontrada2 == NULL)
	{
		printf("Erro: Uma das matrizes nao existe\n\n");
	}
	else if (Percorre(Matriz, Resultante) != NULL)
	{
		printf("Erro: Matriz resultante ja existe\n\n");
	}
	else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
	{
		aux = (int**)malloc((encontrada1)->linhas*sizeof(int*));

		for (i = 0; i < (encontrada1)->linhas; ++i)
		{
			aux[i] = (int*)malloc((encontrada1)->colunas*sizeof(int));
		}

		for (i = 0; i < (encontrada1)->linhas; i++)
		{
			for (j = 0; j < (encontrada1)->colunas; j++)
			{
				aux[i][j] = encontrada1->matriz[i][j] + encontrada2->matriz[i][j];
			}
		}
		CriaNova(Matriz, aux, Resultante, (encontrada1)->linhas, (encontrada1)->colunas);
		ImprimirMatriz(Matriz, Resultante);
	}
	else
	{
		printf("Erro: Dimensoes diferentes.\n\n");
	}
}

void DividirMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]) {

	int **aux, i, j, verifica0 = 0;

	No *encontrada1 = Percorre(Matriz, nomePrimeira);
	No *encontrada2 = Percorre(Matriz, nomeSegunda);

	for (i = 0; i < encontrada1->linhas; i++)
	{
		for (j = 0; j < encontrada1->colunas; j++)
		{
			if (encontrada2->matriz[i][j] == 0)
			{
				verifica0 = 1;
			}
		}
	}

	if (encontrada1 == NULL || encontrada2 == NULL)
	{
		printf("Erro: Uma das matrizes nao existe\n\n");
	}
	else if (Percorre(Matriz, Resultante) != NULL)
	{
		printf("Erro: Matriz resultante ja existe\n\n");
	}
	else if (verifica0 != 0)
	{
		printf("Erro: Segunda matriz contem zeros\n\n");
	}
	else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
	{
		aux = (int**)malloc((encontrada1)->linhas*sizeof(int*));

		for (i = 0; i < (encontrada1)->linhas; ++i)
		{
			aux[i] = (int*)malloc((encontrada1)->colunas*sizeof(int));
		}

		for (i = 0; i < (encontrada1)->linhas; i++)
		{
			for (j = 0; j < (encontrada1)->colunas; j++)
			{
				aux[i][j] = encontrada1->matriz[i][j] / encontrada2->matriz[i][j];
			}
		}
		CriaNova(Matriz, aux, Resultante, (encontrada1)->linhas, (encontrada1)->colunas);
		ImprimirMatriz(Matriz, Resultante);
	}
	else
	{
		printf("Erro: Dimensoes diferentes.\n\n");
	}

}

void MultiplicarMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]) {

	int **aux, i, j;

	No *encontrada1 = Percorre(Matriz, nomePrimeira);
	No *encontrada2 = Percorre(Matriz, nomeSegunda);

	if (encontrada1 == NULL || encontrada2 == NULL)
	{
		printf("Erro: Uma das matrizes nao existe\n\n");
	}
	else if (Percorre(Matriz, Resultante) != NULL)
	{
		printf("Erro: Matriz resultante ja existe\n\n");
	}
	else if (encontrada1->colunas == encontrada2->linhas)
	{
		aux = (int**)malloc((encontrada1)->linhas*sizeof(int*));

		for (i = 0; i < (encontrada1)->linhas; ++i)
		{
			aux[i] = (int*)malloc((encontrada2)->colunas*sizeof(int));
		}

		int k, auxi;

		for (i = 0; i < (encontrada1)->linhas; i++)
		{
			for (j = 0; j < (encontrada2)->colunas; j++)
			{
				auxi = 0;
				for (k = 0; k < encontrada2->linhas; k++)
				{
					auxi = auxi + (encontrada1->matriz[i][k] * encontrada2->matriz[k][j]);
				}

				aux[i][j] = auxi;
			}
		}

		CriaNova(Matriz, aux, Resultante, (encontrada1)->linhas, (encontrada2)->colunas);
		ImprimirMatriz(Matriz, Resultante);
	}
	else
	{
		printf("Erro: Dimensoes diferentes.\n\n");
	}

}

void Multiplicar2Matrizes(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]) {

	int **aux, i, j;

	No *encontrada1 = Percorre(Matriz, nomePrimeira);
	No *encontrada2 = Percorre(Matriz, nomeSegunda);

	if (encontrada1 == NULL || encontrada2 == NULL)
	{
		printf("Erro: Uma das matrizes nao existe\n\n");
	}
	else if (Percorre(Matriz, Resultante) != NULL)
	{
		printf("Erro: Matriz resultante ja existe\n\n");
	}
	else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
	{
		aux = (int**)malloc((encontrada1)->linhas*sizeof(int*));

		for (i = 0; i < (encontrada1)->linhas; ++i)
		{
			aux[i] = (int*)malloc((encontrada1)->colunas*sizeof(int));
		}

		for (i = 0; i < (encontrada1)->linhas; i++)
		{
			for (j = 0; j < (encontrada1)->colunas; j++)
			{
				aux[i][j] = encontrada1->matriz[i][j] * encontrada2->matriz[i][j];
			}
		}
		CriaNova(Matriz, aux, Resultante, (encontrada1)->linhas, (encontrada1)->colunas);
		ImprimirMatriz(Matriz, Resultante);
	}
	else
	{
		printf("Erro: Dimensoes diferentes.\n\n");
	}
}
