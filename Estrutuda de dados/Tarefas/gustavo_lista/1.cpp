#include <iostream>
#include <locale.h> 
#include <stdlib.h> 
#include <string>

using namespace std;


int main() {
	setlocale(LC_ALL, "Portuguese");

    int *ponteiro;

    // Alocar Memória
    ponteiro = new int;
    *ponteiro = 100;

    cout << "Endereço do Ponteiro: " << &ponteiro << "\n";
    cout << "Conteúdo do Ponteiro: " << ponteiro << "\n";
    cout << "Valor apontado: " << *ponteiro << "\n\n";
    

	return 0;
}