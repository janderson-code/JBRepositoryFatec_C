#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;

struct Produto{
    string descricao;
    int codigo;
    float preco;
};

Produto * obterdados();

int main()
{
   Produto *Vpont;
   Vpont = obterdados();

   cout << "Código " << Vpont->codigo<< endl;
   cout << "Descricao " << Vpont->descricao<< endl;
   cout << "Preco " << Vpont->preco<< endl;
    
    system("pause");
    return 0;
}

Produto * obterdados(){

 static Produto prod;
 cout << "descricao:";
 cin >> prod.descricao;

 cout << "codigo:";
 cin >> prod.codigo;

 cout << "preco:";
 cin >> prod.preco;

    return &prod;
}