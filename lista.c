#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "lista.h"

typedef mno No;

struct mno{

	char nomeMatriz[50];
	int linhas;
	int colunas;
	int matriz[][];
	struct no *prox;
};

void CriaVazia(No **Lista)
{
	*Lista = NULL;
}

void AdicionarNo(No **mLista,char nomeMatriz[50],int linha,int coluna){

	if(mLista == NULL){
	No *aux = (No*) malloc(sizeof(No));
	strcpy(nomeMatriz,aux->nomeMatriz);
	aux->linhas = linha;
	aux->colunas = coluna;
	aux->matriz = DeclararMatriz(linha,coluna);
	aux->prox = NULL;
	*mLista = aux;
	}
	else{
		AdicionarNo(&(*mLista)->prox,nomeMatriz,linha,coluna);
	}

}


void RemoverNo(No **mLista, char nomeMatriz[50]){
	

}

