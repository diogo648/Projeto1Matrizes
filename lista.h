#ifndef LISTA_H_
#define LISTA_H_

typedef struct mno No;

void CriaVazia(No **lista);
void AdicionarNo(No **mLista, char nomeMatriz[50], int linha, int coluna);
void removerNo(No **mLista, char nomeMatriz[50]);

#endif
