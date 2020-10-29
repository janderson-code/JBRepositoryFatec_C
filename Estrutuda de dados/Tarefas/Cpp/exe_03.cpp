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

    *(ptr + 0) = 10;
    *(ptr + 1) = 20;
    *(ptr + 2) = 30;

    cout << "1º número: " << *(ptr + 0) << "\n";
    cout << "2º número: " << *(ptr + 1) << "\n";
    cout << "3º número: " << *(ptr + 2) << "\n";

    sleep(3);
   
    return 0;
}

