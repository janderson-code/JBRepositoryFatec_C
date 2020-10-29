#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais
#include<unistd.h> // função sleep

using namespace std;
struct Pessoa{
    string nome;
    int idade;
    float salario;

};

void exibirDados(Pessoa novoaluno);
Pessoa inserirDados();

int main()
{   
    setlocale(LC_ALL,"portuguese");
    cout << fixed <<setprecision(2); //define o numero de casas decimais biblioteca <iomanip>

    Pessoa aluno;

    aluno = inserirDados();
    exibirDados(aluno);
    
    sleep(3);
    return 0;
}
void exibirDados(Pessoa novoaluno){
    cout << "Nome" << novoaluno.nome << endl;
    cout << "Idade " << novoaluno.idade << endl;
    cout << "Salario " << novoaluno.salario << endl;

}
Pessoa inserirDados(){
    Pessoa novoaluno;

    novoaluno.nome ="Maria jose";
    novoaluno.idade =25;
    novoaluno.salario=3000.00;

    return novoaluno;

}