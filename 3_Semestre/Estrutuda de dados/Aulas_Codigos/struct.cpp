#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;
struct Pessoa{
    string nome;
    int idade;
    float salario;

};

int main()
{   
    setlocale(LC_ALL,"portuguese");
    cout << fixed <<setprecision(2); //define o numero de casas decimais biblioteca <iomanip>

    Pessoa aluno;

   /* aluno.nome = "Maria José";
    aluno.idade = 16;
    aluno.salario= 3300.00; */


    cout << "Nome"<< endl;
    getline(cin,aluno.nome);

    cout << "Idade" << endl;
    cin >> aluno.idade;

    cout << "Salário" << endl;
    cin >> aluno.salario;
    
    
    /*cout << "Nome" << aluno.nome << endl;
    cout << "Idade " << aluno.idade << endl;
    cout << "Salario " << aluno.salario << endl;*/
    exibirDados(aluno);

    system("pause");
    return 0;
}
void exibirDados(Pessoa novoaluno){
    cout << "Nome" << novoaluno.nome << endl;
    cout << "Idade " << novoaluno.idade << endl;
    cout << "Salario " << novoaluno.salario << endl;

}