#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <unistd.h>// função sleep()
#include <stdio.h>
#include <iomanip> // casas decimais
#include <string.h>
#include <string>
#include <float.h>
#include <cfloat> // funções FLT_MIN_EXP   FLT_MAX_EXP

using namespace std;

int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);

    int *ptr;

    ptr = new int;

    *ptr = 100;

    cout << "Endereço:" << &ptr << endl;
    cout << "Conteudo:" << ptr << endl;
    cout << "Valor:" << *ptr << endl;
    
    return 0;
}
