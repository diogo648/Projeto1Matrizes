#ifndef MATRIZ_H_
#define MATRIZ_H_

int **DeclararMatriz(int linhas, int colunas);
void DestruirMatriz(No *Matriz, char nome[]);
void ImprimirMatriz(No **Matriz, char nome[]);
void AtribuirEleMatriz(No **Matriz, char nome[], int linha, int coluna, int n);
void AtribuirLinMatriz();
void AtribuirColMatriz();
void TransporMatriz(No **Matriz, char nome[], char nomeResultado[]);
void SomarMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]);
void DividirMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]);
void MultiplicarMatriz(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]);
void Multiplicar2Matrizes(No **Matriz, char nomePrimeira[], char nomeSegunda[], char Resultante[]);

