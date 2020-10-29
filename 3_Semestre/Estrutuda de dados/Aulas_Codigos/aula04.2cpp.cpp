#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;



struct Pessoa
{
    int idade;
    string nome;
    float salario;

};

void dados(pessoa * pes);
int main() {

    setlocale(LC_ALL,"portuguese");

    Pessoa pessoa1;
    Pessoa pessoa2;

    dados(&pessoa2);
 
  /* // pPes = &pessoa2;
    // pPes ->nome ="Jose";
   // pPes ->idade = 45;
   // pPes->salario=3000.00; 

     cout << "Nome:" << pPes->nome << endl;
    cout << "idade:" << pPes->idade << endl;
    cout << "salario:" << pPes->salario << endl; */

    cout << "Nome:" << pessoa2.Nome << endl;
    cout << "idade:" << pessoa2.idade << endl;
    cout << "salario:" << pessoa2.salario << endl; 

    
    system("pause");
    return 0;
}

void dados(Pessoa *pes){
 cout << "Nome:"<<;
 cin >> pes->nome;

 cout << "Idade:"<<;
 cin >> pes->idade;

 cout << "Salario:"<< ;
 cin >> pes->salario;

}