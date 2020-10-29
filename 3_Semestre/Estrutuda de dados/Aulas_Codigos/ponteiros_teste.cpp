#include<iostream>
#include<stdlib.h>
#include<locale.h>
#include<unistd.h>

using namespace std;

/*prototipos */
void somar(int *x);
void obter(int *x, int*y, int *z);
void calculadora(int n1,int n2, int *soma, int *sub);
int main()
{

//---------------------------------------------
// Ponteiro parte 1 passagem por referencia através de funções
//--------------------------------------------

    setlocale(LC_ALL,"Portuguese");
//--------------------------------------
//     int i, j,*p;

//     i=99;
//     p = &i;
//     j = *p + 100;

//  resultado = 199;
//     cout << j<< endl;
//--------------------------------------

    // float x, *pa,*pb;
    
    // x=300;

    // pa = &x;
    // pb = pa;

    // cout << "Endereço de x " << &x<< endl;  endereço x 001
    // cout << "Conteudo de pa " << pa<< endl; endereço 001
    // cout << " conteudo de pb " << pb<< endl; endereço 001
    // cout << " valor de *pb " << *pb<< endl; valor 300
    // cout << "valor de pa"<< *pa << endl; valor 300

    int x =200, y =200, z =0, soma, sub;

    // somar(&x);
    // obter(&x,&y,&z);
    
    // cout << "Valor de x "<< x << endl;
    // cout << "Valor de y "<< y << endl;
    // cout << "Valor de z "<< z << endl;

    calculadora(x,y,&soma,&sub);

    cout << "soma "<< soma << endl;
    cout << "sub "<< sub << endl;

    

    sleep(3);
    return 0;
}
void somar(int *x){
    *x+=400;
}
void obter(int *x, int*y, int *z){
    *x = 100;
    *y = 200;
    *z = 300;
}
void calculadora(int n1,int n2, int *soma, int *sub){

    *soma = n1 + n2;
    *sub = n1 - n2;
}