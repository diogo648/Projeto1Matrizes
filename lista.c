#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "lista.h"

typedef mno No;

struct mno {

	char nomeMatriz[50];
	int linhas;
	int colunas;
	int **matriz;
	No *prox;
};

void CriaVazia(No **Lista)
{
	*Lista = NULL;
}

void AdicionarNo(No **mLista, char nomeMatriz[], int linha, int coluna) {

	if (*mLista == NULL) {
		No *aux = (No*)malloc(sizeof(No));
		strcpy(aux->nomeMatriz, nomeMatriz);
		aux->linhas = linha;
		aux->colunas = coluna;
		aux->matriz = DeclararMatriz(linha, coluna);
		aux->prox = NULL;
		*mLista = aux;
		printf("OK\n\n");
	}
	else {
		AdicionarNo(&(*mLista)->prox, nomeMatriz, linha, coluna);
	}

}


void RemoverNo(No **mLista, char nomeMatriz[50]){
	

}

No *Percorre(No **Matriz, char nome[]) {

	if (*Matriz == NULL)
	{
		return NULL;
	}
	else if (strcmp((*Matriz)->nomeMatriz, nome) == 0)
	{
		return *Matriz;
	}
	else
	{
		Percorre(&(*Matriz)->prox, nome);
	}
}

void CriaNova(No **Matriz, int **matrizNova, char nome[], int linha, int coluna)
{
	if (*Matriz == NULL) {
		No *aux = (No*)malloc(sizeof(No));
		strcpy(aux->nomeMatriz, nome);
		aux->linhas = linha;
		aux->colunas = coluna;
		aux->matriz = matrizNova;
		aux->prox = NULL;
		*Matriz = aux;
	}
	else {
		CriaNova(&(*Matriz)->prox, matrizNova, nome, linha, coluna);
	}
}
