#include<stdio.h>
#include<stdlib.h>
#include "lista.h"


typedef mno no;

struct mno{

	char nomeMatriz[50];
	int dimensao[2]; 
	struct no *prox;
};



