#include <iostream>
#include <locale.h> // setlocale
#include <stdlib.h> // system
#include <string> // Textos em geral

using namespace std;

int somaValores(int *ponteiro) {
    int soma = 0;

    for (int i = 2; i <= 8; i++) {
        soma += *(ponteiro + i);
    }
    return soma;
}

int subtracao(int *ponteiro) {

    return *(ponteiro + 1) - *(ponteiro + 4);
}


int multiplicacao(int *ponteiro) {

    return *(ponteiro + 0) * *(ponteiro + 9);
}


float divisao(int *ponteiro) {
    float resDivisao;
    // resDivisao = 0;
    resDivisao = *(ponteiro + 3) / *(ponteiro + 6);
    return resDivisao;
}


bool multiplo(int *ponteiro) {
    if (*(ponteiro + 5) % 5 == 0) {
        return true;
    } else {
        return false;
    }
}


int main() {
	setlocale(LC_ALL, "Portuguese");
    int *ponteiro;

    ponteiro = new int;

    *(ponteiro + 0) = 10;
    *(ponteiro + 1) = 20;
    *(ponteiro + 2) = 30;
    *(ponteiro + 3) = 110;
    *(ponteiro + 4) = 50;
    *(ponteiro + 5) = 61;
    *(ponteiro + 6) = 5;
    *(ponteiro + 7) = 80;
    *(ponteiro + 8) = 90;
    *(ponteiro + 9) = 100;


    cout << "Soma: " << somaValores(ponteiro) << "\n";

    cout << "Subtração: " << subtracao(ponteiro) << "\n";

    cout << "Multiplicação: " << multiplicacao(ponteiro) << "\n";

    cout << "Divisão: " << divisao(ponteiro) << "\n";
    
    cout << "É múltiplo de 5: " << multiplo(ponteiro) << endl;



    return 0;
}