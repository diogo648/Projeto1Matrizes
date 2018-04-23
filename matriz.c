#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"

int DeclararMatriz(int linhas, int colunas){

  int **Matriz; 
 	int i;
 	
	Matriz=(int**)malloc(linhas*sizeof(int*));
 	for (i = 0; i < linhas; ++i)
	{
 		Matriz[i] = (int*)malloc(colunas*sizeof(int));
	}
  
  return Matriz;
}

void DestruirMatriz(int linhas, int colunas, int Matriz[][]){
  
 for (i = 0; i < linhas; ++i)
	{
		free(Matriz[i]);
	};

	free(Matriz);

}

void ImprimirMatriz(No **Matriz, char nome[]) {

	int i, j;

	if (Matriz == NULL)
	{
		printf("Matriz não encontrada\n");
	}
	else if (strcmp((*Matriz)->nomeMatriz, nome) == 0)
	{

		for (i = 0; i < (*Matriz)->linhas; i++)
		{
			for (j = 0; j < (*Matriz)->colunas; j++)
			{
				printf("%6.2d", (*Matriz)->matriz[i][j]);
				
			}
			printf("\n");
		}
	}
	else
	{
		ImprimirMatriz(&(*Matriz)->prox, nome);
	}
}

void AtribuirEleMatriz(No **Matriz,char nome[], int n) {

	int linha, coluna, i, j;

	if (Matriz == NULL)
	{
		printf("Matriz não encontrada\n");
	}
	else if (strcmp((*Matriz)->nomeMatriz, nome) == 0)
	{
		printf("linha =");
		scanf("%d", &linha);
		printf("coluna =");
		scanf("%d", &coluna);
		printf("n = ");
		scanf("%d", &n);

		if (linha > (*Matriz)->linhas || coluna > (*Matriz)->colunas)
		{
			printf("Erro: Posicao maior do que dimensoes\n");
		}
		else
		{
			(*Matriz)->matriz[linha - 1][coluna - 1] = n;
		}
	}
	else
	{
		AtribuirEleMatriz(&(*Matriz)->prox, nome, 7);
	}

}


void AtribuirLinMatriz(){


}


void AtribuirColMatriz(){


}

Matriz TransporMatriz(int linhas, int colunas, int Matriz[][], char nome[50]){
	
	int **Matriz1;
	Matriz1=(int**)malloc(linhas*sizeof(int*));

 	for (i = 0; i < linhas; ++i)
	{
		Matriz1[i]=(int*)malloc(colunas*sizeof(int));
	}
	
	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			Matriz1[j][i]=Matriz[i][j];
		}
	}

	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			printf(" %d ",Matriz1[i][j]);
		}
		printf("\n");
	}
	
	return Matriz;
}

Matriz SomarMatriz(int linhas, int colunas,int Matriz[],int Matriz1){

	int **aux;
	
	aux=(int**)malloc(linhas*sizeof(int*));

 	for (i = 0; i < linhas; ++i)
	{
		aux[i]=(int*)malloc(colunas*sizeof(int));
	}
	
	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			aux[i][j] = Matriz1[i][j]+Matriz[i][j];
		}
	}
	return aux;
}

void DividirMatriz(){
	
	int **aux;
	
	aux=(int**)malloc(linhas*sizeof(int*));

 	for (i = 0; i < linhas; ++i)
	{
		aux[i]=(int*)malloc(colunas*sizeof(int));
	}
	
	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			aux[i][j] = Matriz1[i][j]/Matriz[i][j];
		}
	}
	return aux;
	
}

void MUltiplicarMatriz(){


}

void MUltiplicar2Matrizes(int linhas, int colunas,int Matriz[],int Matriz1){
	
	int **aux;
	
	aux=(int**)malloc(linhas*sizeof(int*));

 	for (i = 0; i < linhas; ++i)
	{
		aux[i]=(int*)malloc(colunas*sizeof(int));
	}
	
	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			aux[i][j] = Matriz1[i][j]*Matriz[i][j];
		}
	}
	return aux;

}


