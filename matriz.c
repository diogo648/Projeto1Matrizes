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

void DestruirMatriz(Matriz[][]){
  
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

void AtribuirEleMatriz(){


}


void AtribuirLinMatriz(){


}


void AtribuirColMatriz(){


}

void TransporMatriz(){


}

void SomarMatriz(){


}

void DividirMatriz(){


}

void MUltiplicarMatriz(){


}

void MUltiplicar2Matrizes(){


}


