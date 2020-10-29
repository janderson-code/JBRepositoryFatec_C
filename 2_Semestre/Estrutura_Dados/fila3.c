#include <stdio.h>
#include <locale.h>/*Biblioteca para aparacer sinais ortográficos*/
#include <stdlib.h>
#include <math.h>
#include "unistd.h"/*Biblioteca para uso da função sleep no linux no lugar de system("pause") */
#define MAX 10

typedef struct {
   int fila[MAX];
   int fim;

}TFila;



int remove_inicio(TFila *f, int *e){

 int i;

 if (f->fim>=0)
 {
     *e=f->fila[0];
     for(i=0;i<(f->fim);i++)
        f->fila[i]=f->fila[i+1];
     f->fim=f->fim-1;
     return 0;
 }
 else
    return 1;
}


/*void insere_inicio (TFila *f, int e){

  int i;

  f->fim=f->fim+1;
  for (i=(f->fim);i>0;i--)
      f->fila[i]=f->fila[i-1];
  f->fila[0]=e;
}*/


int insere_fim (TFila *f, int e)
{
    if (f->fim>=(MAX-1))
        return 1;
    else
    {
        f->fim=f->fim+1;
        f->fila[f->fim]=e;
        return 0;
    }
}


void tela()
{
    system("clear");
    printf("* * *   M E N U   * * *\n\n\n");
    printf("\n1 - Insere na fila");
    printf("\n2 - Remove da fila");
    printf("\n3 - Mostra fila");
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


int main()
{
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
                       printf("* * *   I N S E R E   F I L A   * * *\n\n");
                       printf("\nDigite um numero inteiro: ");
                       scanf("%d",&elemento);
                       flag = insere_fim(&fila,elemento);
                       if (flag==0)
                          printf("Elemento inserido com sucesso!\n\n");
                       else
                          printf("Impossivel inserir...\nFila cheia!\n\n");
                       sleep(2);/*Função para congelar tela por 2 segundos*/
                       break;


          case '2' :  system("clear");
                      printf("* * *   R E M O V E  E L E M E N T O   D A   P I L H A   * * *\n\n");
                      flag = remove_inicio(&fila,&elemento);
                      if (flag==0)
                      {
                          printf("\nElemento removido com sucesso...\n");
                          printf("\nElemento removido: %d\n\n",elemento);
                      }
                      else
                          printf("\nImpossivel remover...\nFila vazia!\n\n");

                      sleep(2);/*Função para congelar tela por 2 segundos*/
                      break;

          case '3' :  mostra(fila);
                      break;

       }


    }while(op!='9');


    return 0;
}
