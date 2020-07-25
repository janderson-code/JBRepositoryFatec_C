#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void select_sort (int v[])
{
   int i, j, min, aux;
   for (i = 0; i < (MAX-2); i++)
  {
     min = i;
     for (j = (i+1); j < MAX-1; j++) {
       if(v[j] < v[min])
         min = j;
     }
     if (v[i] != v[min]) {
       aux = v[i];
       v[i] = v[min];
       v[min] = aux;
     }
  }
}

 

  void insert_sort (int v[])
  {
      int escolhido, j,i;

 

      for (i = 1; i < MAX; i++) {
         escolhido = v[i];
         j = i - 1;

 

         while ((j >= 0) && (v[j] > escolhido))
        {
             v[j + 1] = v[j];
             j--;
        }

 

        v[j + 1] = escolhido;
    }
  }

 


int busca_seq(int v[], int chave)
{
    int i,achou;
    achou=0;
    i=0;
    while ((achou==0) && (i<MAX))
    {
        if (v[i]==chave)
            achou=1;
        else
            i++;
    }
    if (achou==1)
        return i;
    else
        return -1;
}

 

 

void bolha (int v[])
{
    int i, j, temp;

 

    for (i = 0; i < MAX - 1; i++){
             for (j = (i+1); j < MAX; j++){
                  if (v[j] < v[i]){
                       temp = v[i];
                       v[i] = v[j];
                       v[j] = temp;
                  }
              }
        }
}

 

 

 


int main()
{

 

    int i,flag,chave;
    int vetor[MAX]={9,4,2,7,5,6,1,0,8,10};
    for(i=0;i<=MAX-1;i++)
        printf(" %d",vetor[i]);
    printf("\n\n");
    bolha(vetor);
    for(i=0;i<=MAX-1;i++)
        printf(" %d",vetor[i]);
    printf("\n\n");
    printf("\nDigite uma chave de busca: ");
    scanf("%d",&chave);
    flag=(busca_seq(vetor,chave));
    if (flag==-1)
        printf("\nO numero %d nao esta no vetor.\n",chave);
    else
        printf("\nO numero %d esta na posicao: %d\n",chave,flag);

 


    return 0;
}