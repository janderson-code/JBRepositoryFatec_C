#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip> // casas decimais

#define Max 3
using namespace std;

struct Veiculos
{
    string marca;
    int ano_fab;
    int qtd_portas;
};

Veiculos *alocar_memoria();
void imprimirDados(Veiculos *ptr);
void desalocarMemoria(Veiculos *ptr);
void obterDados(Veiculos *ptr);
void imprimirDados(Veiculos *ptr);

int main()
{

    Veiculos *pVeiculo;

    pVeiculo = new Veiculos[3];

    pVeiculo = alocar_memoria();
    obterDados(pVeiculo);
    imprimirDados(pVeiculo);
    desalocarMemoria(pVeiculo);

    system("pause");
    return 0;
}

Veiculos *alocar_memoria()
{

    Veiculos *ptr;

    ptr = new Veiculos[3];

    return ptr;
}
void desalocarMemoria(Veiculos *ptr)
{
    delete[] ptr;
}
void obterDados(Veiculos *ptr)
{
    (ptr + 0)->marca = "Fiat";
    (ptr + 0)->ano_fab = 2005;
    (ptr + 0)->qtd_portas = 4;

    (ptr + 1)->marca = "Fiat";
    (ptr + 1)->ano_fab = 2006;
    (ptr + 1)->qtd_portas = 4;

    (ptr + 2)->marca = "Fiat";
    (ptr + 2)->ano_fab = 2007;
    (ptr + 2)->qtd_portas = 4;
}
void imprimirDados(Veiculos *ptr)
{
    for (int i = 0; i < Max; i++)
    {
        cout << setfill('-');
        cout << "Marca: " << setw(12) << (ptr + i)->marca << endl;
        cout << "Ano: " << setw(12) << (ptr + i)->ano_fab << endl;
        cout << "Portas: " << setw(12) << (ptr + i)->qtd_portas << endl;
    }
}