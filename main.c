#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"
#include "lista.h"


void main()
{
	int linhas;
	int colunas;
	int valor;
	char comando[5];
	char nomeMatriz[50];
	char nomeMatriz2[50];
	char nomeMatrizRes[50];

	No *lista;
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
				AdicionarNo(&lista, nomeMatriz, linhas, colunas);
			}

		}
		else if (strcmp(comando, "DM") == 0)//Destruir Matriz
		{
			scanf("%s", nomeMatriz);
			//RemoverNo(*lista, nomeMatriz);
		}
		else if (strcmp(comando, "IM") == 0)//Imprimir Matriz --- Perguntar Edmar
		{
			scanf("%s", nomeMatriz);
			ImprimirMatriz(&lista, nomeMatriz);
		}
		else if (strcmp(comando, "AE") == 0)//Atribuir um elemento a Matriz
		{
			scanf("%s", nomeMatriz);
			scanf("%d", &linhas);
			scanf("%d", &colunas);
			scanf("%d", &valor);
			AtribuirEleMatriz(&lista, nomeMatriz, linhas, colunas, valor);
		}
		else if (strcmp(comando, "AL") == 0)//Atribuir uma linha a Matriz --- Perguntar Edmar
		{
			scanf("%s", &nomeMatriz);
			scanf("%d", &linhas);

			AtribuirLinMatriz();
		}
		else if (strcmp(comando, "AC") == 0)//Atribuir uma coluna a Matriz --- Perguntar Edmar
		{
			scanf("%s", &nomeMatriz);
			scanf("%d", &colunas);
			AtribuirColMatriz();
		}
		else if (strcmp(comando, "TM") == 0)//Transpor uma Matriz
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatrizRes);
			TransporMatriz(&lista, nomeMatriz, nomeMatrizRes);
		}
		else if (strcmp(comando, "SM") == 0)//Somar duas Matrizes
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);
			SomarMatriz(&lista, nomeMatriz, nomeMatriz2, nomeMatrizRes);
		}
		else if (strcmp(comando, "DV") == 0)//Dividir uma Matriz por outra
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);
			DividirMatriz(&lista, nomeMatriz, nomeMatriz2, nomeMatrizRes);
		}
		else if (strcmp(comando, "MM") == 0)//Multiplicar uma Matriz por outra
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);
			MultiplicarMatriz(&lista, nomeMatriz, nomeMatriz2, nomeMatrizRes);
		}
		else if (strcmp(comando, "ME") == 0)//Multiplicar uma Matriz por outra (elemento a elemento)
		{
			scanf("%s", nomeMatriz);
			scanf("%s", nomeMatriz2);
			scanf("%s", nomeMatrizRes);
			Multiplicar2Matrizes(&lista, nomeMatriz, nomeMatriz2, nomeMatrizRes);
		}
		else
		{
			printf("Comando desconhecido\n\n");
		};
		
	} while (strcmp(comando, "FE") != 0); //Finaliza execução

}
