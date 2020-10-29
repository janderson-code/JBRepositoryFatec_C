#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#define Max 5

void push (int p[], int *t){

	int num;

	printf("Digite um numero inteiro\n");
	scanf("%d",&num);

		if(*t<(Max-1))
		{
			*t=*t+1;
			p[*t]=num;
			printf("\nElemento inserido com sucesso!!");
		}
		else
			printf("\nImpossível inserir\nPilha cheia");

		
	}

void pop (int *t){

	if(*t>=0)
	{ 
	   *t=*t-1;
	   printf("\nElemento excluido com sucesso");
	}
	else
		printf("\nImpossível remover,Pilha vazia\n");

	pause();
}

void mostra (int p[],int t){

	int i;
	system("clear");
	printf("* * * * IMPRESSÃO DA PILHA * * * *\nImpossível");

	for (int i = t; i >=0;i--)		
	{
		printf("\n%d",p[i] );
	}

	pause();
}


int main(){
	
	int pilha[Max],topo,op;
	topo =-1;

	do
	{
		system("clear");
		printf("*****MENU*****\n");
		printf("\n1Push");
		printf("\n2Pop");
		printf("\n3Mostrar Pilha");
		printf("\n9Sair");
		printf("Digite sua opção\n");
		scanf("%d",&op);

		switch (op)
		{ case 1: push(pilha,&topo);
				   break;
		  case 2: pop(&topo);
		  		  break;
		  case 3:mostra(pilha,topo);
		  		 break;

		}
	} while (op!=9);



	return 0;
}