#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include "lista.h"


void CriaVazia(No **Lista)
{
	*Lista = NULL;
}


void RemoverNo(No **Lista, char nomeMatriz[]) {

	No *aux;

	if (strcmp((*Lista)->nomeMatriz, nomeMatriz) == 0)
	{
		aux = *Lista;
		*Lista = (*Lista)->prox;
		free(aux);
	}
	else
	{
		RemoverNo(&(*Lista)->prox, nomeMatriz);
	}
}

No *Percorre(No **Lista, char nome[]) {

	if (*Lista == NULL)
	{
		return NULL;
	}
	else if (strcmp((*Lista)->nomeMatriz, nome) == 0)
	{
		return *Lista;
	}
	else
	{
		Percorre(&(*Lista)->prox, nome);
	}
}

void AdicionarNo(No **Lista, float **matrizNova, char nome[], int linha, int coluna)
{
	if (*Lista == NULL) {
		No *aux = (No*)malloc(sizeof(No));

		if(!aux)
		{
		   printf("Erro: Heap Overflow\n");
		}
		else
		{
		  strcpy(aux->nomeMatriz, nome);
		  aux->linhas = linha;
		  aux->colunas = coluna;
		  aux->matriz = matrizNova;
		  aux->prox = NULL;
		  *Lista = aux;
		}
	}
	else {
		AdicionarNo(&(*Lista)->prox, matrizNova, nome, linha, coluna);
	}
}
