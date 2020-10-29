#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

int main()
{
    string nome, endereco;
    int idade;

    cout << "Nome" << endl;
    getline(cin, nome);

    cout << "Idade" << endl;
    cin >> idade;
    cout << "Endereço" << endl;
    getline(cin, endereco);

    cout << "Nome" << nome << endl;
    cout << "Nome" << idade << endl;
    cout << "Nome" << endereco << endl;

    system("pause");

    return 0;
}
