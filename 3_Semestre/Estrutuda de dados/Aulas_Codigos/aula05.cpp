#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

#define Max 3
using namespace std;

struct Aluno
{
    string nome;
    int idade;
    float media;
};

Aluno* alocarMemoria();
void desalocarMemoria(Aluno *ptr);
void imprimirDados(Aluno *ptr);
void EntradaDados(Aluno *ptr);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    Aluno stcAluno;
    Aluno *pAluno;

  //   pAluno = new Aluno;
    pAluno = alocarMemoria();


    /*stcAluno.nome = "Joao";
    stcAluno.idade = 45;
    stcAluno.media = 8.5;

    pAluno->nome="Luficer";
    pAluno->idade = 6000;
    pAluno->media = 10; */

    EntradaDados(pAluno);

    imprimirDados(pAluno);

    desalocarMemoria(pAluno);

    system("pause");
    return 0;
}

/*Funções*/

Aluno* alocarMemoria(){
    Aluno* ptr;

    ptr = new Aluno();

    return ptr;
}
void desalocarMemoria(Aluno *ptr){
    delete ptr;
}
void EntradaDados(Aluno *ptr){
    cout << "Digite o nome";
    cin >> ptr->nome;

    cout << "Digite Idade";
    cin >> ptr->idade;

    cout << "Digite media";
    cin >> ptr->media;


}
void imprimirDados(Aluno *ptr){

    cout << "/* Nome\t */" << ptr->nome <<endl;
    cout << "/* Nome\t */" << ptr->idade <<endl;
    cout << "/* Nome\t */" << ptr->media <<endl;
}