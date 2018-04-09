#include<stdio.h>
#include<stdlib.h>
#include "lista.h"


typedef mno No;

struct mno{

	char nomeMatriz[50];
	int dimensao[2];
	int matriz[][];
	struct no *prox;
};

void AdicionarNo(No **mLista,char nomeMatriz[50],dimensao[2]){

	if(mLista == NULL){
	No *aux = (No*) malloc(sizeof(No));
	strcpy(nomeMatriz,aux->nomeMatriz);
	aux->dimensao[0] = dimensao[0];
	aux->dimensao[1] = dimensao[1];
	aux->matriz = DeclararMatriz(dimensao[0],dimensao[1]);
	aux->prox = NULL;
	*mLista = aux;
	}
	else{
		AdicionarNo(&(*mLista)->prox,nomeMatriz,dimensao);
	}

}


void RemoverNo(No **mLista, char nomeMatriz[50]){


}

