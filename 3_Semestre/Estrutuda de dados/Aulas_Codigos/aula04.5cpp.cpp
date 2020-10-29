#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;

int main()
{   
    int *px ,*py,*pz;

    px = new int;
    py = new int;
    pz = new int;

    *px =2;
    *py =3;
    *pz = *px +*py;

    cout << "Valor "<< *pz <<endl;

    delete px,py,pz;
    
    system("pause");
    return 0;
}
