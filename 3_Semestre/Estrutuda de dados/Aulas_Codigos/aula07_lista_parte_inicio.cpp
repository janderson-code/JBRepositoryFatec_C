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
Dados dados; // estrutura guardada dentro da lista
No* proxNo; // aponta para o próximo Nó da lista
};

// Nó início da lista
struct Lista {
int qtdNo;

 No *inicio;
};

Lista* criarLista();
void liberarLista(Lista* ptrLista);

int main() {
setlocale(LC_ALL, "Portuguese");
bool operacaoOK;

 Lista* pLista;
pLista = criarLista();

 operacaoOK = inserirListaInicio(pLista, 100, "Maria", 9.5);
if (operacaoOK == true) {
cout << "Inserção efetuada com sucesso!" << endl;
}
else {
cout << "Falha na execução da inserção!" << endl;
}



 liberarLista(pLista);

 system("pause");
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
bool inserirListaInicio(Lista* ptrLista, int matricula,
string nome, float media) {

 No* ptrNoNovo;

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

 ptrNoNovo->proxNo = ptrLista->inicio;

 ptrLista->inicio = ptrNoNovo;

 // Incrementa o quantidade de Nós
ptrLista->qtdNo++;

 return true;
}