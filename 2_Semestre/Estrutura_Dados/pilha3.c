#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>
#define MAX 5

typedef struct{
	
	int pilha[MAX];
	int topo;
}TPilha;


int push(TPilha *p,int e){
	
	if(p->topo<(MAX-1))
	{
		p->topo =p->topo+1;/*seta para ponteiro da estrutura*/
		p->pilha[p->topo]=e;
		return 0;
	}
	else
		return 1;

}

int pop(TPilha *p,int *e){
	
	if(p->topo>=0)
	{ 
	   *e=p->pilha[p->topo];/*Devolver elemento que esta sendo removido*/
	   p->topo = p->topo-1;
	   return 0;
	   
	}
	else
		return 1;

}

void mostra (TPilha p){

	int i;
	system("clear");
	printf("* * * * IMPRESSÃO DA PILHA * * * *\nImpossível");

	if(p.topo <0)
		printf("PILHA vazia");

	
	for (i = p.topo; i >=0;i--)		
		printf("\n%d",p.pilha[i]);
	printf("\n\n");

	pause();
}

void menu(){
		system("clear");
		printf("*****MENU*****\n");
		printf("\n1-Push");
		printf("\n2-Pop");
		printf("\n3-Mostrar Pilha");
		printf("\n4-Zerar Pilha");
		printf("\n9Sair");
		printf("Digite sua opção\n");

}

void restart(TPilha *p){

	p->topo = -1;

}


int main(){	
	int op,elemento,flag;
	TPilha p1;
	p1.topo = -1;

	do
	{
		menu();
		scanf("%d",&op);


		switch (op)
		{
				case 1: printf("\n\nDigite um numero inteiro ");
						scanf("%d",&elemento);
						flag =push(&p1,elemento);
						if (flag == 0)
							printf("Elemento inserido com sucesso\n");
						else
							printf("\nImpossivel inserir\nPilha Cheia!!");
					break;
			case 2: flag = pop(&p1,&elemento);
					if (flag ==0)
					{
						printf("\nElemento removido com sucesso\n\n");
						printf("\nElemento removido:%d\n\n",elemento);
					}
					else
						printf("\nImpossivel remover pilha vazia");
					break;
			case 3: mostra(p1);
					break;
			case 4: restart(&p1);
					break;

		}


		
	} while (op!=9);

	return 0;
}