#include <iostream>
#include <locale.h> 
#include <stdlib.h> 
#include <string>

using namespace std;


int somaPonteiro(int *ptrX, int *ptrY);
int maiorValor(int *ptrX, int *ptrY);
void trocaValores(int *ptrX, int *ptrY);
void newValues(int *ptrX, int *ptrY);

int main() {
	setlocale(LC_ALL, "Portuguese");

    int *ptrX, *ptrY;

    // Alocar Memória
    ptrX = new int;
    ptrY = new int;

    *ptrX = 100;
    *ptrY = 200;
    

    //2.1
    cout << "Soma dos ponteiros: " << somaPonteiro(ptrX, ptrY) << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";


    // 2.2
    cout << "Maior valor: " << maiorValor(ptrX, ptrY) << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";


    // 2.3
    cout << "Ponteiros antes da troca:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n";
    trocaValores(ptrX, ptrY);
    cout << "Ponteiros depois da troca:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n\n";

    cout << "-----------------------------------------------------------------------------------------\n\n";
    
    // 2.4  
    newValues(ptrX, ptrY);
    cout << "\nValores novos:\nptrX: " << *ptrX << "\nptrY: " << *ptrY << "\n\n";

	return 0;
}

int somaPonteiro(int *ptrX, int *ptrY) {
    return (*ptrX + *ptrY);
}

int maiorValor(int *ptrX, int *ptrY) {
    if (*ptrX > *ptrY) {
        return *ptrX;
    } else {
        return *ptrY;
    }
}


void trocaValores(int *ptrX, int *ptrY) {
    int *ptrFlag;

    *ptrFlag = *ptrX;
    *ptrX = *ptrY;
    *ptrY = *ptrFlag;
}


void newValues(int *ptrX, int *ptrY) {
    cout << "Digite o novo valor de ptrX: ";
    cin >> *ptrX;
    cout << "Digite o novo valor de ptrY: ";
    cin >> *ptrY;
    
}