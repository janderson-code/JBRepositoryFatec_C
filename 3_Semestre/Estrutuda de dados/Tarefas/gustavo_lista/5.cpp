#include <iostream>
#include <locale.h> // setlocale
#include <stdlib.h> // system
#include <string> // Textos em geral

using namespace std;

int somaValores(int *ponteiro) {
    int soma = 0;

    for (int i = 0; i < 5; i++) {
        soma += *(ponteiro + i);
    }
    return soma;
}

int menorValor(int *ponteiro) {
    int menor = *(ponteiro + 0);

    for (int i = 1; i < 5; i++) {
        if (*(ponteiro + i) < menor) {
            menor = *(ponteiro + i);
        }
    }

    return menor;

}


int maiorValor(int *ponteiro) {
    int maior = *(ponteiro + 0);

    for (int i = 1; i < 5; i++) {
        if (*(ponteiro + i) > maior) {
            maior = *(ponteiro + i);
        }
    }

    return maior;
}


float media(int *ponteiro) {
    float soma = 0;
    float media;

    for (int i = 0; i < 5; i++) {
        soma += *(ponteiro + i);
    }

    return (soma/5);
}


int main() {
	setlocale(LC_ALL, "Portuguese");
    int *ponteiro;

    ponteiro = new int;

    *(ponteiro + 0) = 10;
    *(ponteiro + 1) = 20;
    *(ponteiro + 2) = 30;
    *(ponteiro + 3) = 40;
    *(ponteiro + 4) = 50;


    cout << "Soma: " << somaValores(ponteiro) << "\n";

    cout << "Menor: " << menorValor(ponteiro) << "\n";

    cout << "Maior: " << maiorValor(ponteiro) << "\n"; 

    cout << "Média: " << media(ponteiro) << "\n"; 


    return 0;
}