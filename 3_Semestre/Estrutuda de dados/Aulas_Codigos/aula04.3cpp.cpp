#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;

struct Veiculos
{
    string Modelo;
    int ano;
    int num_p;
};

void dados(Veiculos *v);
Veiculos* obterdados();

int main()
{
    Veiculos veic;
    Veiculos *ponteiro;

    ponteiro = obterdados();
    dados(&veic);

    cout << "Modelo:" << ponteiro->Modelo << endl;
    cout << "Ano:" << ponteiro->ano << endl;
    cout << "portas:" << ponteiro->num_p << endl; 

   /* cout << "Modelo:" << veic.Modelo << endl;
    cout << "Ano:" << veic.ano << endl;
    cout << "portas:" << veic.num_p << endl;*/ 

    
    system("pause");
    return 0;
}
void dados(Veiculos *v){
 cout << "Modelo:";
 cin >> v->Modelo;

 cout << "Ano:";
 cin >> v->ano;

 cout << "Portas:";
 cin >> v->num_p;
}
Veiculos * obterdados(){
    static Veiculos carro;
    carro.Modelo = "xxx";
    carro.ano = 2000;
    carro.num_p =6;

    return &carro;
}