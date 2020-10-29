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

Veiculos *alocarMemoria();
void desalocarMemoria(Veiculos *ptr);
void imprimirDados(Veiculos *ptr);
void EntradaDados(Veiculos *ptr);

int main()
{
    setlocale(LC_ALL, "Portuguese");

    Veiculos *pVeiculo;

    pVeiculo = alocarMemoria();

    EntradaDados(pVeiculo);

    imprimirDados(pVeiculo);

    desalocarMemoria(pVeiculo);

    system("pause");
    return 0;
}

/*Funções*/

Veiculos *alocarMemoria()
{
    Veiculos *ptr;

    ptr = new Veiculos();

    return ptr;
}
void desalocarMemoria(Veiculos *ptr)
{
    delete ptr;
}
void EntradaDados(Veiculos *ptr)
{
    cout << "Digite a marca\n";
    cin >> ptr->marca;

    cout << "Digite Ano de fabricação\n";
    cin >> ptr->ano_fab;

    cout << "Digite qtd portas\n";
    cin >> ptr->qtd_portas;
}
void imprimirDados(Veiculos *ptr)
{

    cout << "Marca: " << ptr->marca << endl;
    cout << "Ano: " << ptr->ano_fab << endl;
    cout << "Portas: " << ptr->qtd_portas << endl;
}