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
int menorValor(int *ptr);
int maiorValor(int *ptr);
float media(int *ptr) ;




int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);

    int *ptr;

    ptr = new int;

    *(ptr + 0) = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;
    *(ptr + 3) = 40;
    *(ptr + 4) = 50;


    cout << "Soma: " << soma(ptr) << "\n";

    cout << "Menor: " << menorValor(ptr) << "\n";

    cout << "Maior: " << maiorValor(ptr) << "\n"; 

    cout << "Média: " << media(ptr) << "\n"; 

    sleep(3);
   
    return 0;
}

int soma(int *ptr) {
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        soma += *(ptr + i);
    }
    return soma;
}

int menorValor(int *ptr) {
    int menor = *(ptr + 0);

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) < menor) {
            menor = *(ptr + i);
        }
    }

    return menor;

}


int maiorValor(int *ptr) {
    int maior = *(ptr + 0);

    for (int i = 1; i < 5; i++) {
        if (*(ptr + i) > maior) {
            maior = *(ptr + i);
        }
    }

    return maior;
}


float media(int *ptr) {
    float soma = 0;
    float media;

    for (int i = 0; i < 5; i++) {
        soma += *(ptr + i);
    }

    return (soma/5);
}

