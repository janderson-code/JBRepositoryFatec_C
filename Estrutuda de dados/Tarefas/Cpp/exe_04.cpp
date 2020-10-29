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

// Protótipo
void InserirValorponteiro(int *ptr) ;

int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);

    int *ptr;
    ptr = new int;

    InserirValorponteiro(ptr);

    cout << "1º valor: " << *(ptr + 0) << "\n";
    cout << "2º valor: " << *(ptr + 1) << "\n";
    cout << "3º valor: " << *(ptr + 2) << "\n";

    sleep(3);
   
    return 0;
}

void InserirValorponteiro(int *ptr) {
    cout << "Digite o primeiro valor: ";
    cin >> *(ptr + 0);

    cout << "Digite o segundo valor: ";
    cin >> *(ptr + 1);

    cout << "Digite o terceiro valor: ";
    cin >> *(ptr + 2);

}
