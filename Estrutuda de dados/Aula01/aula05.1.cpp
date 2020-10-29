#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

#define Max 3
using namespace std;

int *alocar_memoria();
void desalocar_memoria();

int main() {
    
    int *ptx, *pty,*ptz;

    
    /*alocando memoria*/

    ptx = alocar_memoria();
    pty = alocar_memoria();
    ptz = alocar_memoria();

    /*desalocando memoria*/

    desalocar_memoria(ptx);
    desalocar_memoria(pty);
    desalocar_memoria(ptz);


}

/*Funções*/

int* alocar_memoria({
    int *Ptr;

    ptr = new int[Max];
     return ptr;
}
void desalocar_memoria(int *ptx){
    delete[] ptx;
}
void impressao_dados(int *ptr){

    for (int i = 0; i < Max; i++)
    {
        cout << *(Ptr + i) <<"\t"<< endl;
    }
}