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
int soma(int *ptr);
int sub(int *ptr);
int mult(int *ptr);
float div(int *ptr);
bool multiplo(int *ptr);




int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);

    int *ptr;

    ptr = new int;

    *(ptr + 0) = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;
    *(ptr + 3) = 110;
    *(ptr + 4) = 50;
    *(ptr + 5) = 61;
    *(ptr + 6) = 5;
    *(ptr + 7) = 80;
    *(ptr + 8) = 90;
    *(ptr + 9) = 100;


    cout << "Soma: " << soma(ptr) << "\n";

    cout << "Subtração: " << sub(ptr) << "\n";

    cout << "Multiplicação: " << mult(ptr) << "\n";

    cout << "Divisão: " << div(ptr) << "\n";
    
    cout << "É múltiplo de 5: " << multiplo(ptr) << endl;

    sleep(3);
   
    return 0;
}

int soma(int *ptr) {
    int soma = 0;

    for (int i = 2; i <= 8; i++) {
        soma += *(ptr + i);
    }
    return soma;
}

int sub(int *ptr) {

    return *(ptr + 1) - *(ptr + 4);
}

// multiplicação
int mult(int *ptr) {

    return *(ptr + 0) * *(ptr + 9);
}


float div(int *ptr) {
    float restoDivisao;
    // restoDivisao = 0;
    restoDivisao = *(ptr + 3) / *(ptr + 6);
    return restoDivisao;
}


bool multiplo(int *ptr) {
    if (*(ptr + 5) % 5 == 0) {
        return true;
    } else {
        return false;
    }
}

