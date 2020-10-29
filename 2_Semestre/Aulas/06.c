#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>

void retangulo(int,int);/*protótipo*/

int main()
{   setlocale(LC_ALL,"portuguese");
    printf("Sala\n");
    retangulo(22,12);
    printf("Cozinha\n");
    retangulo(16,16);
    fflush(stdin);
    pause();
    
    return 0;
}
/*retangulo()*/
/*desenha um retangulo na tela*/

void retangulo(int largura ,int altura){
    int j,k;
    largura /=2;
    altura /=4;

    for ( j = 1; j< altura;j++)
    {
        printf("\t\t");
        for(k=1;k<= largura;k++) printf("\xDB");
        printf("\n");
    }
    



}