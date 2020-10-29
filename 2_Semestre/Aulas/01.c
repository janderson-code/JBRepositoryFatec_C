#include<stdio.h>
#include<stdlib.h>

const float PI = 3.14;
float celsius(float); /*Protótipo ou declaração da função global*/
float area(float);    /*Protótipo ou declaração da função global*/

 void oqfac(int*x){
    
     *x = *x*2;
}

 int main()
 {   int a =2;
     float c,f;
     printf("Digite a temperatura em graus Fahrenheit\n");
     scanf("%f",&f);

     c = celsius(f); /*Chamada da Função*/

    printf("celsius = %.2f\n",c);
    oqfac(&a);
    printf("%d",a);

     return 0;
 }
 float celsius(float fahr){

     float c;
     c = (fahr -32.0)*5.0/9.0;
     return c;
 }

float area (float r){

 return (4*PI*r*r);

}

