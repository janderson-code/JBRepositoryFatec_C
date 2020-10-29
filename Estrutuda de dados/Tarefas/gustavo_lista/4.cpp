#include <iostream>
#include <locale.h> // setlocale
#include <stdlib.h> // system
#include <string> // Textos em geral

using namespace std;

void valoresPonteiro(int *ponteiro) {
    cout << "Digite o primeiro valor: ";
    cin >> *(ponteiro + 0);

    cout << "Digite o segundo valor: ";
    cin >> *(ponteiro + 1);

    cout << "Digite o terceiro valor: ";
    cin >> *(ponteiro + 2);

}

int main() {
	setlocale(LC_ALL, "Portuguese");
    int *ponteiro;
    ponteiro = new int;

    valoresPonteiro(ponteiro);

    cout << "1º valor: " << *(ponteiro + 0) << "\n";
    cout << "2º valor: " << *(ponteiro + 1) << "\n";
    cout << "3º valor: " << *(ponteiro + 2) << "\n";


    return 0;
}