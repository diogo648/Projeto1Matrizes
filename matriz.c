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

void ImprimirMatriz(int linhas, int colunas,int Matriz[][]){
	
	for (i = 0; i < linhas; i++)
	{
 		for (j = 0; j < colunas; j++)
		{
 			printf(" %d ",Matriz[i][j]);
		}
		printf("\n");
	}

}

Matriz AtribuirEleMatriz(int Matriz[][],int linhas, int colunas, int n){
	
	int n, linha, coluna;
	printf("linha =");
	scanf("%d",&linha);
	printf("coluna =");
	scanf("%d",&coluna);
	printf("n = ");
	scanf("%d",&n);
	

	Matriz[linha-1][coluna-1]=n;
	
	return Matriz;

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


