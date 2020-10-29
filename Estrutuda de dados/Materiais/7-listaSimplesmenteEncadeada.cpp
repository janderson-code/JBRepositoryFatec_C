/*
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");


    return 0;
} 
*/

/* 
#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

// Dados sobre o ALUNO
struct Dados {
    int matricula;
    string nome;
    float media;
};

// Estrutura do Nó
struct No {
    Dados dados;    // estrutura guardada dentro da lista
    No *proximoNo;  // aponta para o próximo Nó da lista
};



int main() {
    setlocale(LC_ALL, "Portuguese");

    No *pMaria;
    No *pJose;
    No *pJesus;

    No *pAtual;

    pMaria = new No;
    
    pMaria->dados.matricula = 100;
    pMaria->dados.nome = "Maria";
    pMaria->dados.media = 9.5;
    pMaria->proximoNo = NULL;


    pJose  = new No;
    pJose->dados.nome = "José";
    pJose->dados.media = 9.5;
    pJose->proximoNo = NULL;

    
    
    pJesus = new No;
    pJesus->dados.nome = "Jesus";
    pJesus->dados.media = 9.5;
    pJesus->proximoNo = NULL;





    delete pMaria;
    delete pJose;
    delete pJesus;


    return 0;
} */

#include <iostream>
#include <locale.h>
#include <stdlib.h>
#include <string>

using namespace std;

// Dados sobre o ALUNO
struct Dados
{
    int matricula;
    string nome;
    float media;
};

// Estrutura do Nó
struct No
{
    Dados dados; // estrutura guardada dentro da lista
    No *proxNo;  // aponta para o próximo Nó da lista
};

// Nó início da lista
struct Lista
{
    int qtdNo;

    No *inicio;
};

Lista *criarLista();
void liberarLista(Lista *ptrLista);
bool inserirListaInicio(Lista *ptrLista, int matricula,
                        string nome, float media);
void exibirLista (Lista *ptrLista);

bool inserirListaFim(Lista *ptrLista, int matricula,
                        string nome, float media);

bool inserirListaOrdenada(Lista *ptrLista, int matricula, string nome, float media);

bool removerListaInicio(Lista *ptrLista);

bool removerListaOrdenada(Lista *ptrLista, int matricula);


int main() {

    setlocale(LC_ALL, "Portuguese");
    bool operacaoOK;

    Lista *pLista;
    pLista = criarLista();

    // inserir no inicio
    operacaoOK = inserirListaInicio(pLista, 100, "Maria", 9.5);

    if (operacaoOK == true)
    {
        cout << "Inserção efetuada com sucesso!" << endl;
    }
    else
    {
        cout << "Falha na execução da inserção!" << endl;
    }

    cout << "\n\n";

    inserirListaInicio(pLista, 200, "José", 9.0);
    inserirListaInicio(pLista, 300, "Jesus", 10.0);

    exibirLista(pLista);



    inserirListaFim(pLista, 200, "José", 9.0);
    // inserirListaFim(pLista, 200, "José", 9.0);
    // inserirListaFim(pLista, 200, "José", 9.0);

    inserirListaOrdenada(pLista, 30, "Jesus", 10.0);
    inserirListaOrdenada(pLista, 30, "Maria", 12.0);
    inserirListaOrdenada(pLista, 30, "Paula", 13.0);
    inserirListaOrdenada(pLista, 30, "José", 90.0);

    




    liberarLista(pLista);

    return 0;
}

//--------------------------------------------------------
// CRIAR LISTA
//--------------------------------------------------------
Lista *criarLista() {

    Lista *ptrLista;

    ptrLista = new Lista;

    // Se a lista NÃO pode ser criada
    if (ptrLista == NULL)
    {
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
    while (ptrLista->inicio != NULL) {

        ptrNoAtual = ptrLista->inicio;
        ptrLista->inicio = ptrNoAtual->proxNo;

        delete ptrNoAtual;
    }

    delete ptrLista;
}

//--------------------------------------------------------
// INSERIR NO INÍCIO DA LISTA
//--------------------------------------------------------
bool inserirListaInicio(Lista *ptrLista, int matricula,
                        string nome, float media) {


    No *ptrNoNovo;

    //Se a lista NÃO foi criada
    if (ptrLista == NULL)
    {
        cout << "A lista não está criada!" << endl;
        return false;
    }

    //-------------------------------
    // Cria o novo nó
    //-------------------------------
    ptrNoNovo = new No;

    if (ptrNoNovo == NULL) {
        cout << "Memória insulficiente!" << endl;
        return false;
    }

    ptrNoNovo->dados.matricula = matricula;
    ptrNoNovo->dados.nome = nome;
    ptrNoNovo->dados.media = media;

    ptrNoNovo->proxNo = ptrLista->inicio;

    ptrLista->inicio = ptrNoNovo;

    // Incrementa o quantidade de Nós
    ptrLista->qtdNo++;

    return true;
}

void exibirLista (Lista *ptrLista) {
    No *ptrNoAtual;

    // Se a lista não foi criada
    if (ptrLista == NULL) {
        cout << "A lista não está criada!" << endl;
        return;
    }

    // Se não tiver nenhum Nó na lista

    if (ptrLista->inicio == NULL) {
        cout << "A lista está vazia!" << endl;

        return;
    }

    ptrNoAtual = ptrLista->inicio;

    while (ptrNoAtual != NULL) {
        cout << "Matrícula: " << ptrNoAtual->dados.matricula << endl;
        cout << "Nome: " << ptrNoAtual->dados.nome << endl;
        cout << "Média: " << ptrNoAtual->dados.media << endl << endl << endl;

        ptrNoAtual = ptrNoAtual->proxNo;
    }
    cout << endl;
}


bool inserirListaFim(Lista *ptrLista, int matricula, string nome, float media) {


    No *ptrNoNovo;
    No *ptrNoAtual;

    //Se a lista NÃO foi criada
    if (ptrLista == NULL) {
        cout << "A lista não está criada!" << endl;
        return false;
    }

    //-------------------------------
    // Cria o novo nó
    //-------------------------------
    ptrNoNovo = new No;

    if (ptrNoNovo == NULL) {
        cout << "Memória insulficiente!" << endl;
        return false;
    }

    ptrNoNovo->dados.matricula = matricula;
    ptrNoNovo->dados.nome = nome;
    ptrNoNovo->dados.media = media;
    ptrNoNovo->proxNo = NULL;


    ptrNoAtual = ptrLista->inicio;

    // Se não houver nenhum nó na lista

    if (ptrNoAtual == NULL) {
        ptrLista->inicio = ptrNoNovo;
    }
    else {
        // Localiza o último nó
        while (ptrNoAtual->proxNo != NULL) {
            ptrNoAtual = ptrNoAtual->proxNo;
        }
        ptrNoAtual->proxNo = ptrNoNovo;
    }
    // Incrementa a quantidade de Nós

    ptrLista->qtdNo++;

    return true;
}



bool inserirListaOrdenada(Lista *ptrLista, int matricula, string nome, float media) {
    No *ptrNoNovo;
    No *ptrNoAnterior;
    No *ptrNoAtual;

    if (ptrLista == NULL) {
        cout << "A lista não está criada" << endl;
        return false;
    }


    // Cria o novo nó

    ptrNoNovo = new No;

    if (ptrNoNovo == NULL) {
        cout << "Memória insulficiente!" << endl;
        return false;
    }

    ptrNoNovo->dados.matricula = matricula;    ptrNoNovo = new No;

    if (ptrNoNovo == NULL) {
        cout << "Memória insulficiente!" << endl;
        return false;
    }

    ptrNoNovo->dados.nome = nome;
    ptrNoNovo->dados.media = media;
    ptrNoNovo->proxNo = NULL;

    // Se a lista estiver vazia

    if (ptrLista->inicio == NULL) {
        ptrLista->inicio = ptrNoNovo;
    }
    else {
        ptrNoAnterior = NULL;
        ptrNoAtual = ptrLista->inicio;

while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula < matricula) {
    ptrNoAnterior = ptrNoAtual;
    ptrNoAtual = ptrNoAtual->proxNo;
}

if (ptrNoAtual == ptrLista->inicio) {
    ptrNoNovo->proxNo = ptrLista->inicio;
    ptrLista->inicio = ptrNoNovo;
}
else {
    ptrNoNovo->proxNo = ptrNoAtual;
    ptrNoAnterior->proxNo = ptrNoNovo;
}

ptrLista->qtdNo++;

return true;
}
return true;
}

bool removerListaInicio(Lista *ptrLista) {
    No *ptrNoAtual;

    // Se a lista não foi criada
    if (ptrLista == NULL) {
        cout << "A lista não foi criada\n";
        return false;
    }

    // Se não tiver nenhum nó na lista
    if (ptrLista->inicio == NULL) {
        cout << "A lista está vazia\n";
        return false;
    }

    // Ajusta o início

    ptrNoAtual = ptrLista->inicio;
    ptrLista->inicio = ptrNoAtual->proxNo;


    // Exclui o primeiro nó
    delete ptrNoAtual;

    // Decrementa a quantidade de nós

    ptrLista->qtdNo--;

    return true;


}


bool removerListaFim(Lista *ptrLista) {
    No *ptrNoAnterior;
    No *ptrNoAtual;

    // Se a lista NÃO foi criada
    if (ptrLista == NULL) {
        cout << "A lista não está criada!\n";
        return false;
    }

    // Se não tiver nenhum Nó na lista
    if (ptrLista->inicio == NULL) {
        cout << "A lista está vazia!\n";
        return false;
    }

    ptrNoAnterior = NULL;
    ptrNoAtual = ptrLista->inicio;

    // Localiza o nó final da lista
    while (ptrNoAtual->proxNo != NULL) {
        ptrNoAnterior = ptrNoAtual;
        ptrNoAtual = ptrNoAtual->proxNo;
    }



    // Se for o primeiro nó da lista

    if (ptrNoAtual == ptrLista->inicio) {
        ptrLista->inicio = NULL;
    }
    else {
        ptrNoAnterior->proxNo = NULL;
    }


    // Exclui o nó
    delete ptrNoAtual;


    // Decrementa a quantidade de nós
    ptrLista->qtdNo--;

    return true;
}

//--------------------------------------------------------
// REMOVER ORDENADO DA LISTA
//--------------------------------------------------------
bool removerListaOrdenada(Lista *ptrLista, int matricula) {
No *ptrNoAnterior;
No *ptrNoAtual;

 // Se a lista NÃO foi criada
if (ptrLista == NULL) {
cout << "A lista não está criada!" << endl;
return false;
}

//Se não tiver nenhum Nó na lista
if (ptrLista->inicio == NULL) {
cout << "A lista esta vazia!" << endl;
return false;
}

 ptrNoAnterior = NULL;
ptrNoAtual = ptrLista->inicio;

 // Localizao o nó que será excluído
while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula != matricula) {
ptrNoAnterior = ptrNoAtual;
ptrNoAtual = ptrNoAtual->proxNo;
}

 if (ptrNoAtual == NULL) {
cout << "A matrícula " << matricula << " não foi encontrada!" << endl;
return false;
}

// Se for o primeiro nó da lista
if (ptrNoAtual == ptrLista->inicio) {
ptrLista->inicio = ptrNoAtual->proxNo;
}
else {
ptrNoAnterior->proxNo = ptrNoAtual->proxNo;
}
// Exclui o nó atual
delete ptrNoAtual;

 // Decrementa o quantidade de Nós
ptrLista->qtdNo--;

 return true;
}