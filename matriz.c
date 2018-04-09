#include<stdio.h>
#include<stdlib.h>
#include "matriz.h"
//
int DeclararMatriz(int linhas, int colunas){

  int **Matriz; 
 	int i;
 	
	Matriz = (int*)malloc(linhas*sizeof(int*));
 	for (i = 0; i < linhas; ++i)
	{
 		Matriz[i] = (int*)malloc(colunas*sizeof(int));
	}
  
  return Matriz;
}

void DestruirMatriz(Matriz[][]){
  
  free(Matriz);

}

void ImprimirMatriz(){


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


