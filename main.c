//Nome: Diogo Christovão Cortez
//RA: 120349102
//Nome Marcelino Noguero de Souza
//RA: 16011538

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdio_ext.h>
#include "matriz.h"
#include "lista.h"


void main()
{
	int i, j, linhas, colunas;
	float valor, valores[50], **aux;
	char comando[5], nomeMatriz[50], nomeMatriz2[50], nomeMatrizRes[50];
	No *lista, *encontrada1, *encontrada2;
	CriaVazia(&lista);

	do
	{
		//Pega as siglas do comando 
		scanf("%s", comando);

		if (strcmp(comando, "CM") == 0)//Criar Matriz
		{
			scanf("%s", nomeMatriz);
			scanf("%d", &linhas);
			scanf("%d", &colunas);

			if (linhas < 1 || linhas > 50 || colunas < 1 || colunas > 50)
			{
				printf("Erro: Dimensoes invalidas (<1 ou >50)\n\n");
			}
			else if (Percorre(&lista, nomeMatriz) != NULL)
			{
				printf("Erro: Matriz ja existe\n\n");
			}
			else
			{
				aux = DeclararMatriz(linhas, colunas);
				AdicionarNo(&lista, aux, nomeMatriz, linhas, colunas);
				printf("OK\n\n");
			}

		}
		else if (strcmp(comando, "DM") == 0)//Destruir Matriz
		{
			scanf("%s", nomeMatriz);
			encontrada1 = Percorre(&lista, nomeMatriz);
			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz nao encontrada\n\n");
			}
			else
			{
				DestruirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
				RemoverNo(&lista, nomeMatriz);
				printf("OK\n\n");
			}
		}
		else if (strcmp(comando, "IM") == 0)//Imprimir Matriz --- Perguntar Edmar
		{
			scanf("%s", nomeMatriz);
			encontrada1 = Percorre(&lista, nomeMatriz);

			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz nao encontrada\n\n");
			}
			else
			{
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
		}
		else if (strcmp(comando, "AE") == 0)//Atribuir um elemento a Matriz
		{
			scanf("%s", nomeMatriz);
			scanf("%d", &linhas);
			scanf("%d", &colunas);
			scanf("%f", &valor);

			encontrada1 = Percorre(&lista, nomeMatriz);

			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz solicitada nao existe\n\n");
			}
			else if (linhas > encontrada1->linhas || colunas > encontrada1->colunas)
			{
				printf("Erro: Posicao maior do que dimensoes\n\n");
			}
			else
			{
				AtribuirEleMatriz(encontrada1->matriz, linhas, colunas, valor);
				printf("OK\n\n");
			}
		}
		else if (strcmp(comando, "AL") == 0)//Atribuir uma linha a Matriz --- Perguntar Edmar
		{
			scanf("%s", nomeMatriz);
			scanf("%d", &linhas);
			i = -1;

			do
			{
				i++;
			} while (scanf("%f", &valores[i]) && i < 50);
			__fpurge(stdin);

			encontrada1 = Percorre(&lista, nomeMatriz);

			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz solicitada nao existe\n\n");
			}
			else if (linhas > encontrada1->linhas || linhas < 1)
			{
				printf("Erro: Linha fora das dimensoes\n\n");
			}
			else if (i > encontrada1->colunas)
			{
				printf("Erro: Quantidade de numeros maior que dimensoes\n\n");
			}
			else
			{
				AtribuirLinMatriz(encontrada1->matriz, linhas, i, valores);
				printf("OK\n\n");
			}
		}
		
		else if (strcmp(comando, "AC") == 0)//Atribuir uma coluna a Matriz --- Perguntar Edmar
		{
			scanf("%s", nomeMatriz);
			scanf("%d", &colunas);

			i = -1;

			do
			{
				i++;
			} while (scanf("%f", &valores[i]) && i < 50);
			__fpurge(stdin);

			encontrada1 = Percorre(&lista, nomeMatriz);

			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz solicitada nao existe\n\n");
			}
			else if (colunas > encontrada1->colunas || colunas < 1)
			{
				printf("Erro: Coluna fora das dimensoes\n\n");
			}
			else if (i > encontrada1->linhas)
			{
				printf("Erro: Quantidade de numeros maior que dimensoes\n\n");
			}
			else
			{
				AtribuirColMatriz(encontrada1->matriz, colunas, i, valores);
				printf("OK\n\n");
			}
		}
		else if (strcmp(comando, "TM") == 0)//Transpor uma Matriz
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatrizRes);

			encontrada1 = Percorre(&lista, nomeMatriz);

			if (encontrada1 == NULL)
			{
				printf("Erro: Matriz nao encontrada\n\n");
			}
			else if (Percorre(&lista, nomeMatrizRes) != NULL)
			{
				printf("Erro: Matriz resultante ja existe\n\n");
			}
			else
			{
				aux = TransporMatriz(encontrada1->matriz, encontrada1->colunas, encontrada1->linhas);
				AdicionarNo(&lista, aux, nomeMatrizRes, encontrada1->colunas, encontrada1->linhas);
				encontrada1 = Percorre(&lista, nomeMatrizRes);
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
		}		
		else if (strcmp(comando, "SM") == 0)//Somar duas Matrizes
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);

			encontrada1 = Percorre(&lista, nomeMatriz);
			encontrada2 = Percorre(&lista, nomeMatriz2);

			if (encontrada1 == NULL || encontrada2 == NULL)
			{
				printf("Erro: Uma das matrizes nao existe\n\n");
			}
			else if (Percorre(&lista, nomeMatrizRes) != NULL)
			{
				printf("Erro: Matriz resultante ja existe\n\n");
			}
			else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
			{
				aux = SomarMatriz(encontrada1->matriz, encontrada2->matriz, encontrada1->linhas, encontrada1->colunas);
				AdicionarNo(&lista, aux, nomeMatrizRes, encontrada1->colunas, encontrada1->linhas);
				encontrada1 = Percorre(&lista, nomeMatrizRes);
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
			else
			{
				printf("Erro: Dimensoes diferentes.\n\n");
			}
		}
		
		else if (strcmp(comando, "DV") == 0)//Dividir uma Matriz por outra
		{
			int verifica0;

			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);

			encontrada1 = Percorre(&lista, nomeMatriz);
			encontrada2 = Percorre(&lista, nomeMatriz2);

			for (i = 0; i < encontrada1->linhas; i++)
			{
				for (j = 0; j < encontrada1->colunas; j++)
				{
					if (encontrada2->matriz[i][j] == 0)
					{
						verifica0 = 1;
					}
				}
			}

			if (encontrada1 == NULL || encontrada2 == NULL)
			{
				printf("Erro: Uma das matrizes nao existe\n\n");
			}
			else if (Percorre(&lista, nomeMatrizRes) != NULL)
			{
				printf("Erro: Matriz resultante ja existe\n\n");
			}
			else if (verifica0 == 1)
			{
				printf("Erro: Segunda matriz contem zeros\n\n");
			}
			else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
			{
				
				aux = DividirMatriz(encontrada1->matriz, encontrada2->matriz, encontrada1->linhas, encontrada1->colunas);
				AdicionarNo(&lista, aux, nomeMatrizRes, encontrada1->colunas, encontrada1->linhas);
				encontrada1 = Percorre(&lista, nomeMatrizRes);
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
			else
			{
				printf("Erro: Dimensoes diferentes.\n\n");
			}
		}
		
		else if (strcmp(comando, "MM") == 0)//Multiplicar uma Matriz por outra
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);

			encontrada1 = Percorre(&lista, nomeMatriz);
			encontrada2 = Percorre(&lista, nomeMatriz2);

			if (encontrada1 == NULL || encontrada2 == NULL)
			{
				printf("Erro: Uma das matrizes nao existe\n\n");
			}
			else if (Percorre(&lista, nomeMatrizRes) != NULL)
			{
				printf("Erro: Matriz resultante ja existe\n\n");
			}
			else if (encontrada1->colunas == encontrada2->linhas)
			{
				aux = MultiplicarMatriz(encontrada1->matriz, encontrada2->matriz, encontrada1->linhas, encontrada2->colunas, encontrada1->colunas);
				AdicionarNo(&lista, aux, nomeMatrizRes, encontrada1->colunas, encontrada1->linhas);
				encontrada1 = Percorre(&lista, nomeMatrizRes);
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
			else
			{
				printf("Erro: Dimensoes diferentes.\n\n");
			}
		}
		else if (strcmp(comando, "ME") == 0)//Multiplicar uma Matriz por outra (elemento a elemento)
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);

			encontrada1 = Percorre(&lista, nomeMatriz);
			encontrada2 = Percorre(&lista, nomeMatriz2);

			if (encontrada1 == NULL || encontrada2 == NULL)
			{
				printf("Erro: Uma das matrizes nao existe\n\n");
			}
			else if (Percorre(&lista, nomeMatrizRes) != NULL)
			{
				printf("Erro: Matriz resultante ja existe\n\n");
			}
			else if (encontrada1->linhas == encontrada2->linhas && encontrada1->colunas == encontrada2->colunas)
			{
				aux = Multiplicar2Matrizes(encontrada1->matriz, encontrada2->matriz, encontrada1->linhas, encontrada1->colunas);
				AdicionarNo(&lista, aux, nomeMatrizRes, encontrada1->colunas, encontrada1->linhas);
				encontrada1 = Percorre(&lista, nomeMatrizRes);
				ImprimirMatriz(encontrada1->matriz, encontrada1->linhas, encontrada1->colunas);
			}
			else
			{
				printf("Erro: Dimensoes diferentes.\n\n");
			}
		}
		else if (strcmp(comando, "FE") == 0)
		{
			printf("\nSaindo...\n");
		}
		else
		{
			printf("Comando desconhecido\n\n");
		}

	} while (strcmp(comando, "FE") != 0); //Finaliza execuo
	
	free(lista);
}
