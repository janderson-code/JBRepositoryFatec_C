#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;

void calculo(int num01, int num02, int*soma ,int*sub);
void media(float *n1,float *n2, float *n3, float *n4, float *media);
int main()
{
    int num01, num02,soma ,sub;
    float nota01 = 10;
    float n2 =10;
    float n3 =10; 
    float n4 =10; 
    float m;

    num01 = 30, num02 =20;


    media(&nota01,&n2,&n3,&n4,&m);
    calculo(num01,num02,&soma,&sub);
     cout << "Soma" << soma<< endl;
     cout << "Sub" << sub << endl;
     cout << "media" << m <<endl;
    
    return 0;
}

void calculo(int num01, int num02, int*soma ,int*sub){
    *soma = num01 + num02;
    *sub = num01 - num02;
}

void media(float *n1,float *n2, float *n3, float *n4, float *media){
    *media = (*n1+*n2+*n3+*n4) / 4;
}