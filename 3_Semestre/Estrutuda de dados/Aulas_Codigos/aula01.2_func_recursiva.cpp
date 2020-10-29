#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <stdio.h>

using namespace std;

void exibir(int vlrx);

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    int x = 3;
    exibir(x);
    system("pause");
    return 0;
}
void exibir(int vlrx)
{

    if (vlrx > 0)
    {
        cout << "Valor de x antes da função " << vlrx << endl;
        vlrx--;
        exibir(vlrx);
        cout << "Valor de x depois da função " << vlrx << endl;
    }
}
