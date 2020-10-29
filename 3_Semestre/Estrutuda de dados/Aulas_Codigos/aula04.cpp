#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;


int main()
{
    float temp[3];
    float *vt;

    vt = temp;

    cout << "Digite a primeira temperatura" << endl;
    cin >> *(vt +0);

    cout << "Digite a segunda temperatura" << endl;
    cin >> *(vt +1);

    cout << "Digite a terceira temperatura" << endl;
    cin >> *(vt +2);

    cout << *(vt+0) << endl;
    cout << *(vt+1) << endl;
    cout << *(vt+2) << endl;

   return 0;
   
   }
