#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include "unistd.h"

typedef struct estrutura{

int i;
float f;

}Testrutura;


int main()
{
	Testrutura a,b,c[3];


	for (int i = 0; i < 3; i++)
	{
		printf("Digite um numero inteiro\n");
		scanf("%d",&c[i].i);
		printf("Digite um numero real\n");;
		scanf("%f",&c[i].f);
	}
	printf("\n\n");

	for (int i = 0; i <3; ++i)
	{
		printf("\nc[%d](i) = %d",i,c[i].i);
		printf("\nc[%d](f) = %f",i,c[i].f);
	}
	return 0;
}