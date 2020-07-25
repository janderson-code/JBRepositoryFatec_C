#include <stdio.h>
#include <locale.h>/*Biblioteca para aparacer sinais ortográficos*/
#include <stdlib.h>
#include <math.h>
#include "unistd.h"/*Biblioteca para uso da função sleep no linux no lugar de system("pause") */
#define MAX 10

/*Estruturas*/
typedef struct{
	
	int pilha[MAX];
	int topo;
}TPilha;


typedef struct {
   int fila[MAX];
   int fim;

}TFila;

/*Funções*/

void conta_par(TFila f){

	int qt;
	for(int i=0;i<MAX;i++)
	  if(f.fila[i]%2==0)
	    qt++;
	  else
	     qt;	
	

	system("clear");
	printf("\nQuantidade de numeros pares é %d",qt);

}


int remove_Fim(TFila *f, int *e){

 int i;

 if (f->fim>=0)
 {
     *e=f->fila[f->fim];/*Devolver elemento que esta sendo removido*/
	   f->fim = f->fim-1;
	   return 0;
 }
 else
    return 1; 
}


int insere_inicio (TFila *f, int *e){

  int i;

  if (f->fim<(MAX-1))
  {
  	f->fim=f->fim+1;
  for (i=(f->fim);i>0;i--)
      f->fila[i]=f->fila[i-1];
  f->fila[0]=*e;
  return 0;
  }
  else
  	return 1;

}



void tela()
{
    system("clear");
    printf("* * *   M E N U   * * *\n\n\n");
    printf("\n1 - Insere na fila");
    printf("\n2 - Remove Fim da fila");
    printf("\n3 - Inverte");
    printf("\n4 - Mostra ");
    printf("\n5 - Conta numeros pares ");
    printf("\n9 - FIM\n\n");
    printf("Digite a sua opcao: ");
}

void mostra (TFila f)
{
    int i;
    system("clear");
    printf("* * * *   F I L A   * * * *\n\n");
    for(i=0;i<=(f.fim);i++)
        printf("\t%d",f.fila[i]);
    printf("\n\n");
    sleep(2);/*Função para congelar tela por 2 segundos*/
}

void Inverte(TPilha * p,TFila *f){

	/*Falhou*/
	int aux[MAX];
    int i;
    for (i=0;i<MAX;i++)
        aux[f->fila[MAX-1]-i]=p->pilha[i];
    for (i=0;i<MAX;i++)
        p->pilha[i]=aux[i]; 




}

int main()
{	
	setlocale(LC_ALL,"portuguese");/*Idioma para teclado portugues com acento*/
	TPilha pilha;
    TFila fila;
    char op;
    int flag,elemento;
    fila.fim=-1;
    do
    {
        tela();
        //fflush(stdin);
        scanf(" %c",&op);

        switch (op)
        {
            case '1' : system("clear");
                       printf("* * *   I N S E R E  N O  I N Í C I O   D A  F I L A   * * *\n\n");
                       printf("\nDigite um numero inteiro: ");
                       scanf("%d",&elemento);
                       flag = insere_inicio(&fila,&elemento);
                       if (flag==0)
                          printf("Elemento inserido com sucesso!\n\n");
                       else
                          printf("Impossível inserir...\nFila cheia!\n\n");
                       sleep(2);/*Função para congelar tela por 2 segundos*/
                       break;


          case '2' :  system("clear");
                      printf("* * *   R E M O V E  E L E M E N T O   D O  F I M  D A  F I L A  * * *\n\n");
                      flag = remove_Fim(&fila,&elemento);
                      if (flag==0)
                      {
                          printf("\nElemento removido com sucesso...\n");
                          printf("\nElemento removido: %d\n\n",elemento);
                      }
                      else
                          printf("\nImpossível remover...\nFila vazia!\n\n");

                      sleep(2);/*Função para congelar tela por 2 segundos*/
                      break;

          case '3' :  Inverte(&pilha,&fila);
                      break;
          case '4' : mostra(fila);
          			  break;
          case '5':conta_par(fila);
          			break;
       }			 


    }while(op!='9');


    return 0;
}
