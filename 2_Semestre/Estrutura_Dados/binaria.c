#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#define MAX 10

int busc_binaria(int v[], int item){

int inicio = v[0], fim =v[MAX-1]; 

while (inicio <= fim)
{   
    int meio = (inicio + fim)/2; /*Calculo do meio do vetor*/
    if(v[meio] == item) /*valor encontrado no meio*/
    {   
        return meio;
    }
    if(v[meio]<item) /*Caso valor do meio do vetor for menor que item , procurará pela */
        inicio = meio +1;
    else
        fim = meio;

}

return -1;
}

int main()
{
   int vector[MAX] = {5, 23, 27, 30, 39, 45, 56, 71, 80, 92};


    for (int i = 0; i <MAX-1; i++) {

        /*Valor para ser encontrado */
        int item = vector[i];

      
        printf("encontrado %d: \t%d\n", item, busc_binaria(vector, item));
        
        printf("\n");
    }
   
    return 0;
   
}
