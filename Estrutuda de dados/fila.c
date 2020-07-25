#include <stdio.h>
#include <locale.h>/*Biblioteca para aparacer sinais ortográficos*/
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
# define MAX 5

struct TFila
{
    fila[MAX];
    int fim;
};

typedef struct Tfila TFila;


void insere_inicio (TFila *f, int e){

 int i;

  f->fim=f->fim+1;
    for (i=(f->fim);i>0;i--)
        f->fila[i]=f->fila[i-1];
    f->fila[0]=e;}

void remove_inicio(TFila *f){

int i;

for ( i = 0; i <(f->fim); i++)
{
    f->fila[i] = f->fila[i+1];
    f->fim =f->fim-1;
}



}





int main() {
 int fila[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
 int qt;
 int inserir;
 int i;
 
 printf("Quantidade inicial da fila: ");
 scanf(" %d", &qt);
 
//remover
 qt--;
 for (i = 0; i <= qt; i++){
 fila[i] = fila[i+1];
 }

 //inserir
 
 printf("Valor a inserir: ");
 scanf(" %d", &inserir);
 
 qt++;
 for (i = qt; i > 0; i--){
 fila[i] = fila[i-1];
 }
 fila[0] = inserir;
 
 //mostrar
 for (i = 0; i < qt; i++){
 printf("%d\n", fila[i]);
 }
 
 return 0;
}

