#include <stdlib.h>
#include <stdio.h>
#include "matriz.h"
#include "lista.h"


void main(){

int linhas;
int colunas;
int valor;
char comando[2];
char nomeMatriz[50];
char nomeMatriz2[50];
char nomeMatrizRes[50]


No *lista;
	
	//Pega as siglas do comando	
	scanf("%s",comando);

	switch(comando)
	{
	
	  case CM: //Criar Matriz
	     scanf("%s",nomeMatriz);
	     scanf("%d",&linhas);
	     scanf("%d",&colunas);
	    AdicionarNo(*lista,nomeMatriz,linhas,colunas);
	  break;
	 
	  case DM: //Destruir Matriz
	    scanf("%s",nomeMatriz);
            RemoverNo(*lista,nomeMatriz);	
	  break;

	  case IM: //Imprimir Matriz -- Perguntar Edmar
            scanf("%s",nomeMatriz);	
  	    ImprimirMatriz(); 
	  break; 
	  
 	  case AE: //Atribuir um elemento a Matriz
	    scanf("%s",nomeMatriz);
	    scanf("%d",linhas);
            scanf("%d",colunas);
	    scanf("%d",valor);		
            AtribuirEleMatriz();
	  break; 

	  case AL: //Atribuir uma linha a Matriz --- Perguntar Edmar
	    scanf("%s",nomeMatriz);
	    scanf("%d",linhas);	
	    AtribuirLinMatriz();
	  break;
 
	  case AC: //Atribuir uma coluna a Matriz --- Perguntar Edmar
	    scanf("%s",nomeMatriz);
	    scanf("%d",colunas);	
	    AtribuirColMatriz();
	  break; 

	  case TM: //Transpor uma Matriz
            scanf("%s",nomeMatriz);
	    scanf("%s",nomeMatrizRes);	
            TransporMatriz();
	  break;
  
	  case SM: //Somar duas Matrizes
            scanf("%s",nomeMatriz);
	    scanf("%s",nomeMatriz2);	
            SomarMatriz();
	  break;
 
	  case DV: //Dividir uma Matriz por outra
	    scanf("%s",nomeMatriz);
	    scanf("%s",nomeMatriz2);
            scanf("%s",nomeMatrizRes);
	    DividirMatriz();
          break;

	  case MM: //Multiplicar uma Matriz por outra
	    scanf("%s",nomeMatriz);
	    scanf("%s",nomeMatriz2);
            scanf("%s",nomeMatrizRes);
	    MultiplicarMatriz();
          break;
  
	  case ME: //Multiplicar uma Matriz por outra (elemento a elemento)
	    scanf("%s",nomeMatriz);
	    scanf("%s",nomeMatriz2);
            scanf("%s",nomeMatrizRes);	
	    Multiplicar2Matrizes();
	  break; 

	  case FE: //Finaliza a execucao
	   exit(0);
	  break;
	}

}
