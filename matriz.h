#ifndef MATRIZ_H_
#define MATRIZ_H_

float **DeclararMatriz(int linhas, int colunas);
void DestruirMatriz(float **Matriz,int linhas, int colunas);
void ImprimirMatriz(float **Matriz, int linhas, int colunas);
void AtribuirEleMatriz(float **Matriz, int linha, int coluna, float n);
void AtribuirLinMatriz(float **Matriz, int linha, int quantidade, float n[]);
void AtribuirColMatriz(float **Matriz, int coluna, int quantidade, float n[]);
float **TransporMatriz(float **Matriz,int linhas, int colunas);
float **SomarMatriz(float **Matriz1,float **Matriz2, int linhas, int colunas);
float **DividirMatriz(float **Matriz1,float **Matriz2, int linhas, int colunas);
float **MultiplicarMatriz(float **Matriz1, float **Matriz2, int linhas1, int colunas2, int Colunas1Linhas2);
float **Multiplicar2Matrizes(float **Matriz1,float **Matriz2, int linhas, int colunas);

#endif
