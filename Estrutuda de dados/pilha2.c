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


void push(TPilha *p){
	
	if(p->topo<MAX-1)
	{
		p->topo =p->topo+1;/*seta para ponteiro da estrutura*/
		printf("\nDigite o elemento a ser inserido na pilha\n");
		scanf("%d",&p->pilha[p->topo]);
		printf("\nElemento inserido com sucesso!\n\n");
	}
	else
		printf("\nImpossivel inserir,,,\nPilha cheia!\n\n");

}

void pop(TPilha *p){
	
	if(p->topo>=0)
	{ 
	   p->topo=p->topo-1;
	   printf("\nElemento excluido com sucesso");
	}
	else
		printf("\nImpossível remover,Pilha vazia\n");

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


int main(){	int op;
	TPilha p1;
	p1.topo = -1;

	do
	{
		menu();
		scanf("%d",&op);


		switch (op)
		{
			case 1: push(&p1);
					break;
			case 2: pop(&p1);
					break;
			case 3: mostra(p1);
					break;
			case 4: restart(&p1);
					break;

		}


		
	} while (op!=9);

	return 0;
}