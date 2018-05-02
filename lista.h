#ifndef LISTA_H_
#define LISTA_H_

typedef struct mno No;

void CriaVazia(No **lista);
void AdicionarNo(No **mLista, char nomeMatriz[], int linha, int coluna);
void removerNo(No **mLista, char nomeMatriz[]);
void CriaNova(No **Matriz, int **matrizNova, char nome[], int linha, int coluna);
No *Percorre(No **Matriz, char nome[]);

#endif
