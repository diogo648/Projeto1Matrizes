#ifndef LISTA_H_
#define LISTA_H_

typedef struct mno No;

struct mno {

	char nomeMatriz[50];
	int linhas;
	int colunas;
	float **matriz;
	No *prox;
};

void CriaVazia(No **Lista);
void AdicionarNo(No **Lista, float **matrizNova, char nome[], int linha, int coluna);
void RemoverNo(No **Lista, char nomeMatriz[]);
No *Percorre(No **Lista, char nome[]);

#endif
