#include <stdio.h>
#include <stdlib.h>
#define MAX 10

typedef struct ELista {
   int lista[MAX];
   int fim;
}TLista;



int insere (TLista *l,int e,int p){
  int i;
  if(l->fim>=(MAX-1))
     return 1;
  else
    if ((p>=0) && (p<=(l->fim+1)))
    {
      l->fim=l->fim+1;
      for(i=l->fim;i>p;i--)
        l->lista[i]=l->lista[i-1];
      l->lista[p]=e;
      return 0;
    }
    else
        return 2;
 }

int remover (TLista *l, int p){
  int i;
  if (l->fim<0)
    return 1;
  else
    if ( (p>=0) && (p<=l->fim) )
       {
          for(i=p;i<l->fim;i++)
            l->lista[i]=l->lista[i+1];
          l->fim=l->fim-1;
          return 0;
       }
       else
          return 2;
}

void mostra(TLista l){
int i;
system("cls");
printf("* * * *   L I S T A    * * * *\n\n");
if (l.fim==-1)
    printf("\n\nLISTA VAZIA\n\n");
for (i=0;i<=l.fim;i++)
    printf("%d\t",l.lista[i]);
printf("\n\n");
system("pause");
}

int menu(){
int op;
system("cls");
printf("* * * *   M E N U   * * * *\n\n\n");
printf("\n1 - Insere  na lista");
printf("\n2 - Remover da lista");
printf("\n3 - Imprime lista");
printf("\n9 - Sair\n");
printf("\nDidite a sua opcao: ");
scanf("%d",&op);
return op;
}


int main()
{
    int flag,opcao,elemento,posicao;
    TLista lista;
    lista.fim=-1;
    do
    {
       opcao=menu();
       switch(opcao)
       {
             case 1 :  system("cls");
                       printf("\nDigite o elemento a ser inserido: ");
                       scanf("%d",&elemento);
                       printf("\nDigite a posicao: ");
                       scanf("%d",&posicao);
                       flag = insere(&lista,elemento,posicao);
                       if (flag==0)
                           printf("\n\nElemento inserido com sucesso.\n\n");
                       else
                           if (flag==1)
                              printf("\n\nImpossivel inserir...\nLista cheia.\n\n");
                           else
                                printf("\n\nImpossivel inserir...\nPosicao invalida.\n\n");
                       system("pause");
                       break;


             case 2 :  system("cls");
                       printf("\nDigite a posicao do elemento que sera removido: ");
                       scanf("%d",&posicao);
                       flag = remover(&lista,posicao);
                       if (flag==0)
                           printf("\nElemento removido com sucesso!\n\n");
                       else
                           if (flag==1)
                              printf("\nImpossivel remover...\nLista vazia!\n\n");
                           else
                               printf("\nImpossivel remover...\nPosicao invalida!\n\n");
                        system("pause");
                        break;

             case 3 :   mostra(lista);
                        break;
       }


    }while(opcao!=9);

    return 0;
}
