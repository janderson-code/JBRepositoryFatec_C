#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <unistd.h>// função sleep()
#include <stdio.h>
#include <iomanip> // casas decimais
#include <string.h>
#include <string>
#include <float.h>
#include <cfloat> // funções FLT_MIN_EXP   FLT_MAX_EXP

using namespace std;

// Protótipos
int soma(int *ptrX, int *ptrY);
int maiorValor(int *ptrX, int *ptrY);
void trocaValor(int *ptrX, int *ptrY);
void novoValor(int *ptrX, int *ptrY);


int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);

    int *ptrX, *ptrY;

    // alocando memoria
    ptrX = new int;
    ptrY = new int;

    *ptrX = 200;
    *ptrY = 300;

     //2.1
    cout << "Soma dos ponteiros: " << soma(ptrX, ptrY) << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";


    // 2.2
    cout << "Maior valor: " << maiorValor(ptrX, ptrY) << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";


    // 2.3
    cout << "Ponteiros antes da troca:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n";
    trocaValor(ptrX, ptrY);
    cout << "Ponteiros depois da troca:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";
    
    // 2.4  
    novoValor(ptrX, ptrY);
    cout << "\nValores novos:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n\n";
   
    return 0;
}

int soma(int *ptrX, int *ptrY){
        return *ptrX + *ptrY;
}
int maiorValor(int *ptrX, int *ptrY) {
    if (*ptrX > *ptrY) {
        return *ptrX;
    } else {
        return *ptrY;
    }
}
void trocaValor(int *ptrX, int *ptrY) {
    int *ptrFlag;

    *ptrFlag = *ptrX;
    *ptrX = *ptrY;
    *ptrY = *ptrFlag;
}


void novoValor(int *ptrX, int *ptrY) {
    cout << "Digite o novo valor de ptrX: ";
    cin >> *ptrX;
    cout << "Digite o novo valor de ptrY: ";
    cin >> *ptrY;
    
}