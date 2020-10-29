#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <iomanip> // casas decimais
#include <string.h>
#include <string>

using namespace std;

struct Aluno
{   
    string nome;
    int idade;
    float media;
    Aluno* prox;
    
};



int main()
{
    setlocale(LC_ALL, "Portuguese");

    Aluno* pMaria;
    Aluno* pJose;
    Aluno* pJesus;

    pMaria = new Aluno;

    pMaria->nome = "Maria";
    pMaria->media = 9.0;
    pMaria->prox = NULL;


    pJose = new Aluno;
    pJose->nome = "Jose";
    pJose->media = 9.0;
    pJose->prox = NULL;

    pJesus = new Aluno;
    pJesus->nome = "Jesus ";
    pJesus->media = 9.0;
    pJesus->prox = NULL;

    pMaria->prox = pJose;
    pJose->prox = pJesus;


    sleep(3);

    cout << "Nome" << pMaria->nome << endl;
    
    return 0;


}
