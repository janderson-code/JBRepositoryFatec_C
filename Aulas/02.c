#include <stdio.h>
#include <locale.h>
#include<stdlib.h>
#include<math.h>
#include <unistd.h>


/*protótipos*/
float sqr(float);
float somasqr(float,float);
float soma(float,float);


int main()
{
    
    return 0;
}
/*Somasqr()*/
/*Calcula a soma dos quadrados de dois numeros*/

float somasqr(float m, float n){

    return soma(sqr(m),sqr(n));
}

/* sqr()*/
/*Calcula o quadrado de um numero*/

float sqr(float z){
    return z*z;
}

/*soma()*/
/*Calcula a soma de dois numeros*/

float soma(float m, float n){
    return m+n;
}