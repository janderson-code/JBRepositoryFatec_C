#include <iostream>
#include <locale.h> // setlocale
#include <stdlib.h> // system
#include <string>   // Textos em geral

using namespace std;
int main()
{

    setlocale(LC_ALL, "Portuguese");
    int codigo;
    cout << "Digite um numero" << endl;
    cin >> codigo;

    if (codigo == 1)
    {
        cout << "Alimento nao perecivel" << endl;
    }

    else if (codigo == 2 || codigo == 3 || codigo == 4)
    {
        cout << "Alimento perecivel" << endl;
    }
    else if (codigo == 5 || codigo == 6)
    {
        cout << "Vestuario" << endl;
    }
    else if (codigo == 7)
    {
        cout << "Higine" << endl;
    }
    else if (codigo >= 8 && codigo <= 15)
    {
        cout << "limpeza" << endl;
    }
    else
    {
        cout << "Invalido" << endl;
    }
    int x = 0;

    while (x <= 20)
    {

        cout << "X: " << x << endl;

        x += 2;
    }

    cout << endl << endl;

    //-------------------------------------------------

    x = 0;

    while (x <= 20)
    {

        if ((x % 4) == 0)
        {

            cout << "Números divisíveis por 4: " << x << endl;
        }

        x++;
    }

    cout << endl
         << endl;

    cout << endl
         << endl;
    system("pause");
    return 0;
}
