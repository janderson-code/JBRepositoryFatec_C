#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>
#include <unistd.h>

using namespace std;

// Dados sobre o ALUNO
struct Dados {
int Cod_filme;
string nome;
string genero;
int ano;
};

// Estrutura do Nó
struct No {
Dados dados; // estrutura guardada dentro da lista
No* proxNo; // aponta para o próximo Nó da lista
};

// Nó início da lista
struct Lista {
int qtdNo;

 No *inicio;
};

// prototipos
Lista* criarLista();
void liberarLista(Lista* ptrLista);
bool inserirListaInicio(Lista* ptrLista, int Cod_filme, string nome, string genero,int ano);
bool inserirListaFim(Lista* ptrLista, int Cod_filme, string nome, string genero,int ano);
void exibirLista(Lista * ptrLista);
void exibirFilmeAno(Lista * ptrLista, int ano);



int main() {
setlocale(LC_ALL, "Portuguese");

//bool operacaoOk;



 Lista* pLista;
pLista = criarLista();


// verificando se esta tudo ok para inserir


//----------inserindo no fim
inserirListaFim(pLista,10,"star wars","Ficcão",2020);
inserirListaFim(pLista,10,"star wars","Ficcão",2010);
inserirListaFim(pLista,10,"star wars","Ficcão",2016);

exibirLista(pLista);

exibirFilmeAno(pLista,2016);

liberarLista(pLista);

 //system("pause");
 sleep(3);
return 0;
}

//--------------------------------------------------------
// CRIAR LISTA
//--------------------------------------------------------
Lista* criarLista() {
Lista *ptrLista;

 ptrLista = new Lista;

 // Se a lista NÃO pode ser criada
if (ptrLista == NULL) {
cout << "Não foi possível criar a lista!" << endl;
return NULL;
}

 // Como a lista está vazia o INÍCIO aponta para NULL
ptrLista->qtdNo = 0;
ptrLista->inicio = NULL;

 return ptrLista;
}

//--------------------------------------------------------
// LIBERAR LISTA
//--------------------------------------------------------
void liberarLista(Lista *ptrLista) {
No *ptrNoAtual;

 //Se a lista NÃO foi criada
if (ptrLista == NULL) {
cout << "A lista não está criada!" << endl;
return;
}

 // Exclui cada Nó da lista
while (ptrLista->inicio != NULL)
{
ptrNoAtual = ptrLista->inicio;
ptrLista->inicio = ptrNoAtual->proxNo;

 delete ptrNoAtual;
}

 delete ptrLista;
}

//--------------------------------------------------------
// INSERIR NO INÍCIO DA LISTA
//--------------------------------------------------------
bool inserirListaInicio(Lista* ptrLista, int Cod_filme, string nome, string genero,int ano) {

 No* ptrNoNovo;

 //Se a lista NÃO foi criada
if (ptrLista == NULL) {
cout << "A lista não está criada!" << endl;
return false;
}


// Criar novo Nó

ptrNoNovo = new No;

if (ptrNoNovo == NULL){
    cout << "/Memoria insuficiente!" << endl;
    return false;
}

ptrNoNovo->dados.Cod_filme = Cod_filme;
ptrNoNovo->dados.nome = nome;
ptrNoNovo->dados.genero = genero;
ptrNoNovo->dados.ano= ano;


/*Apontando para o inicio ou primeiro elemento da lista*/
ptrNoNovo->proxNo = ptrLista->inicio;

/*guardando o ptrnovo no inicio atribuindo o ptrNovo como primeiro ponteiro/elemento da lista*/
ptrLista->inicio = ptrNoNovo;

//Incrementa a quantidade de nós
ptrLista->qtdNo++;

return true;
}

//Função exibindo nós

void exibirLista(Lista * ptrLista){

    No* ptrNoAtual;

    // se a lista não foi criada

    if (ptrLista == NULL)
    {
        cout << "/Lista não esta criada" << endl;
        return;
    }
    
    //se nao tiver nenhum nó na lista

    if (ptrLista->inicio == NULL)

    {
        cout << "/Lista vazia"<< endl;
        return;
    }
    
    ptrNoAtual = ptrLista->inicio;

// loop para navegar por todos os nós
    while (ptrNoAtual != NULL)
    {
        cout << "Codigo do filme: " << ptrNoAtual->dados.Cod_filme << endl;
        cout << "Nome: " << ptrNoAtual->dados.nome << endl;
        cout << "Genero: " << ptrNoAtual->dados.genero << endl;
        cout << "ano: " << ptrNoAtual->dados.ano << endl;
    // Aqui
        ptrNoAtual = ptrNoAtual->proxNo;

    }
    
    cout << endl;


}

bool inserirListaFim(Lista* ptrLista, int Cod_filme, string nome, string genero,int ano){
    
    No *ptrNoAtual;
    No* ptrNoNovo;

 //Se a lista NÃO foi criada
if (ptrLista == NULL) {
cout << "A lista não está criada!" << endl;
return false;
}

//---------------------------------
// Criar novo Nó
//---------------------------------
ptrNoNovo = new No;

if (ptrNoNovo == NULL){
    cout << "/Memoria insuficiente!" << endl;
    return false;
}

ptrNoNovo->dados.Cod_filme = Cod_filme;
ptrNoNovo->dados.nome = nome;
ptrNoNovo->dados.genero = genero;
ptrNoNovo->dados.ano = ano;
ptrNoNovo->proxNo = NULL;

//---------------------------------
//Posiciona o nó no final da lista
//---------------------------------
ptrNoAtual = ptrLista->inicio; // aponta para o inicio(primeiro nó) na primeira vez é null

// se nao houver nenhum no na Lista

if (ptrNoAtual == NULL)
{   
    // coloca o ponteiro novo como primeiro elemento
    ptrLista->inicio = ptrNoNovo;
}
else
{
    //localiza  o ultimo nó
    while (ptrNoAtual->proxNo != NULL)
    {
        ptrNoAtual = ptrNoAtual->proxNo;
    }
    // quando achar o ultimo nó no while, é inserido o novoPonteiro no fim
    ptrNoAtual->proxNo = ptrNoNovo;
    
}

// incrementa a quantidade de nós

ptrLista->qtdNo++;

return true;

}

void exibirFilmeAno(Lista * ptrLista, int ano){

    No* ptrNoAtual;
    ptrNoAtual = ptrLista->inicio;

// loop para navegar por todos os nós
    while (ptrNoAtual != NULL)
    {
        if (ptrNoAtual->dados.ano >= ano)
        {   
            cout << "Exibindo por Ano" << endl;
            cout << "Codigo do filme: " << ptrNoAtual->dados.Cod_filme << endl;
            cout << "Nome: " << ptrNoAtual->dados.nome << endl;
            cout << "Genero: " << ptrNoAtual->dados.genero << endl;
            cout << "ano: " << ptrNoAtual->dados.ano << endl;
        }
        
    // Aqui
        ptrNoAtual = ptrNoAtual->proxNo;

    }



}