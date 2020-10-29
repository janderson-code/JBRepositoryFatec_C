#include <iostream>
#include <locale.h> // setlocale
#include <stdlib.h> // system
#include <string> // Textos em geral

using namespace std;

int main() {
	setlocale(LC_ALL, "Portuguese");
    int *ponteiro;

    ponteiro = new int;

    *(ponteiro + 0) = 10;
    *(ponteiro + 1) = 20;
    *(ponteiro + 2) = 30;

    cout << "1º número: " << *(ponteiro + 0) << "\n";
    cout << "2º número: " << *(ponteiro + 1) << "\n";
    cout << "3º número: " << *(ponteiro + 2) << "\n";



    return 0;
}