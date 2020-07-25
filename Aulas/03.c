#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>


typedef struct Aluno
{
    int nmat; /*Numero da matricula*/
    float nota[3];/*Notas*/
    float media; /*Médias*/
}Aluno;/*Fim da definição*/



int main()
{   Aluno jose;
    jose.nmat = 123456;
    jose.nota[0]= 10, jose.nota[1] = 10,jose.nota[2]=10;
    jose.media = (jose.nota[0]+jose.nota[1]+jose.nota[2])/3;

    printf("matricula %d\n",jose.nmat);
    printf("Média é igual a %.2f\n",jose.media);


    
    return 0;
}
