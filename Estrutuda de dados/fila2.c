#include<stdio.h>
int main(){
    int v1[10];
    int v2[10];
    int op = 0 ;
    int s = 1;
    int r = 1;
    int n = 0;
    void remover(int v1[], int v2[]);
    void inserir(int v1[], int v2[],int n);
    void carrega(int v1[]);
    void menu();
    do{
    menu();
    scanf("%d",&op);
    carrega(v1);
    if(op == 1)
        remover(v1,v2);
    if(op == 2){
            printf("Valor a inserir");
            scanf("%d",&n);
        inserir(v1,v2,n);
        }
    printf("\nSair?\n digite 0 para sair");
    scanf("%d",&s);
    }while( s != 0);

    printf("===%d",s);


}
void remover(int v1[], int v2[]){
    int r = 1;
    int c = r;
    for(int i = 0; c < 10; i++,c++ ){

                v2[i] = v1[c];


    }
            for(int i = 0; i < 10; i++){
            printf("%d\t",v1[i]);
        }
        printf("\n");
        for(int i = 0; i < (10 - r); i++){
            printf("%d\t",v2[i]);
        }
}

void inserir(int v1[], int v2[],int n){
    int r = 1;

    int c = r;
    for(int i = 0; i < 10; i++, c++){
        if(i == 0)
            v2[i + 1] = v1[i];
         v2[c] = v1[i];
    }
        v2[0] = n;
       for(int i = 0; i < 10; i++){
        printf("%d\t",v2[i]);
    }
}
void carrega(int v1[]){
    printf("CARREGUE VETOr: \n");
    for(int i = 0; i < 10; i++){
        scanf("%d",&v1[i]);
    }
}

void menu(){
    printf("\n========MENU=======\n\n");
    printf("1 - REMOVER INICIO\n");
    printf("2 - INSERE INICIO\n");
}
