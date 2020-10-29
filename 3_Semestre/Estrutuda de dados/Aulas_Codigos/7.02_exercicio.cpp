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
	Dados dados;	// estrutura guardada dentro da lista	
	No* proxNo;		// aponta para o próximo Nó da lista
};

// Nó início da lista
struct Lista {
	int qtdNo;	

	No *inicio;
};

Lista* criarLista();
void liberarLista(Lista* ptrLista);
void exibirLista(Lista* ptrLista);
void concatenarLista(Lista* pDiscBD, Lista* pDiscED, Lista* pCurso);

// Insere
bool inserirListaInicio(Lista* ptrLista, int matricula,string nome, float media);
bool inserirListaFim(Lista* ptrLista, int matricula, string nome, float media);
bool inserirListaOrdenada(Lista* ptrLista, int matricula, string nome, float media);

// Remove
bool removerListaInicio(Lista* ptrLista);
bool removerListaFim(Lista* ptrLista);
bool removerListaOrdenada(Lista* ptrLista, int matricula);

// Pesquisa/Altera
No* pesquisarAluno(Lista* ptrLista, int matricula);

void calcularMediaVersao01(Lista *ptrDiscBD, Lista *ptrDiscED, Lista *ptrMediaGeral);


int main() {
	setlocale(LC_ALL, "Portuguese");
	bool operacaoOK;

    Lista *pDiscBD, *pDiscED, *pMediaGeral, *pCurso;
	

    pDiscBD = criarLista();
    pDiscED = criarLista();
    pCurso = criarLista();
    pMediaGeral = criarLista();
         //-------------------------------------------------
	// Exercício 04
	//-------------------------------------------------	

	cout << "----------------------------" << endl << endl;

	concatenarLista(pDiscBD, pDiscED, pCurso);

	exibirLista(pCurso);

	//-------------------------------------------------
	// Inserir Ordenado
	//-------------------------------------------------
	inserirListaOrdenada(pDiscBD, 30, "Jesus", 8.0);
	inserirListaOrdenada(pDiscBD, 10, "Maria", 8.0);
	inserirListaOrdenada(pDiscBD, 20, "José", 10.0);
	// exibirLista(pDiscBD);

    // cout << "------------------------------------\n\n";

	inserirListaOrdenada(pDiscED, 30, "Jesus", 6.5);
	inserirListaOrdenada(pDiscED, 20, "Maria", 7.5);
	inserirListaOrdenada(pDiscED, 10, "José", 10.0);
	// exibirLista(pDiscED);

	// calcularMediaVersao01(pDiscBD, pDiscED, pMediaGeral);
    // exibirLista(pMediaGeral);
	

	//-------------------------------------------------
	// Desaloca memória
	//-------------------------------------------------
	liberarLista(pDiscBD);
	liberarLista(pDiscED);
	liberarLista(pMediaGeral);

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

		delete  ptrNoAtual;
	}

	delete ptrLista;
}


//--------------------------------------------------------
// EXIBIR A LISTA
//--------------------------------------------------------
void exibirLista(Lista* ptrLista) {
	No* ptrNoAtual;

	//Se a lista NÃO foi criada
	if (ptrLista == NULL) {
		cout << "A lista não está criada!" << endl;
		return;
	}

	//Se não tiver nenhum Nó na lista
	if (ptrLista->inicio == NULL) {
		cout << "A lista esta vazia!" << endl;
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
	//	Cria o novo nó
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


//--------------------------------------------------------
// INSERIR NO FINAL DA LISTA
//--------------------------------------------------------
bool inserirListaFim(Lista* ptrLista, int matricula, string nome, float media) {
	No *ptrNoNovo;
	No *ptrNoAtual;

	//Se a lista NÃO foi criada
	if (ptrLista == NULL) {
		cout << "A lista não está criada!" << endl;
		return false;
	}

	//-------------------------------
	//	Cria o novo nó
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

	//-----------------------------------------
	// Posiciona o Nó no final da lista
	//-----------------------------------------
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
	
	// Incrementa o quantidade de Nós
	ptrLista->qtdNo++;

	return true;
}

//--------------------------------------------------------
// INSERIR EM LISTA ORDENADA
//--------------------------------------------------------
bool inserirListaOrdenada(Lista *ptrLista, int matricula, string nome, float media) {
	No *ptrNoNovo;
	No *ptrNoAnterior;
	No *ptrNoAtual;

	//Se a lista NÃO foi criada
	if (ptrLista == NULL) {
		cout << "A lista não está criada!" << endl;
		return false;
	}

	//---------------------------------------------------------------
	//	Cria o novo nó
	//---------------------------------------------------------------
	ptrNoNovo = new No;

	if (ptrNoNovo == NULL) {
		cout << "Memória insulficiente!" << endl;
		return false;
	}

	ptrNoNovo->dados.matricula = matricula;
	ptrNoNovo->dados.nome = nome;
	ptrNoNovo->dados.media = media;	
	ptrNoNovo->proxNo = NULL;

	//Se a lista estiver vazia
	if (ptrLista->inicio == NULL) {
		ptrLista->inicio = ptrNoNovo;		
	}
	else
	{
		ptrNoAnterior = NULL;
		ptrNoAtual = ptrLista->inicio;

		// Localiza a posição de inserção
		while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula < matricula) {
			ptrNoAnterior = ptrNoAtual;
			ptrNoAtual = ptrNoAtual->proxNo;
		}

		// Insere no INÍCIO da lista
		if (ptrNoAtual == ptrLista->inicio) {
			ptrNoNovo->proxNo = ptrLista->inicio;
			ptrLista->inicio = ptrNoNovo;
		}
		else { // Insere no MEIO ou no FIM da lista

			ptrNoNovo->proxNo = ptrNoAtual;	
			ptrNoAnterior->proxNo = ptrNoNovo;			
		}
	}

	// Incrementa o quantidade de Nós
	ptrLista->qtdNo++;

	return true;
}

//--------------------------------------------------------
// REMOVER DO INÍCIO DA LISTA
//--------------------------------------------------------
bool removerListaInicio(Lista *ptrLista) {
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

	// Ajusta o INÍCIO
	ptrNoAtual = ptrLista->inicio;
	ptrLista->inicio = ptrNoAtual->proxNo;
	
	// Exclui o primeiro nó
	delete ptrNoAtual;

	// Decrementa o quantidade de Nós
	ptrLista->qtdNo--;

	return true;
}

//--------------------------------------------------------
// REMOVER DO FIM DA LISTA
//--------------------------------------------------------
bool removerListaFim(Lista *ptrLista) {
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

	// Decrementa o quantidade de Nós
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

//--------------------------------------------------------
// PESQUISAR MATRÍCULA
//--------------------------------------------------------
No* pesquisarAluno(Lista *ptrLista, int matricula) {	
	No *ptrNoAtual;

	// Se a lista NÃO foi criada
	if (ptrLista == NULL) {
		cout << "A lista não está criada!" << endl;
		return NULL;
	}		

	//Se não tiver nenhum Nó na lista
	if (ptrLista->inicio == NULL) {
		cout << "A lista esta vazia!" << endl;
		return NULL;
	}

	ptrNoAtual = ptrLista->inicio;

	// Localiza o nó a ser alterado
	while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula != matricula) {		
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	if (ptrNoAtual == NULL) {
		cout << "A matrícula " << matricula << " não foi encontrada!" << endl;
		return NULL;
	}
		
	return ptrNoAtual;
}


void calcularMediaVersao01(Lista *ptrDiscBD, Lista *ptrDiscED, Lista *ptrMediaGeral) {

    No *ptrNoAtualBD;
    No *ptrNoAtualED;
    float totalMedia;


    int matricula;
    string nome;
    float mediaGeral;



    ptrNoAtualBD = ptrDiscBD->inicio;
	ptrNoAtualED = ptrDiscED->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtualBD != NULL) {

		// matricula = ptrNoAtualBD->dados.matricula;
        // nome = ptrNoAtualBD->dados.nome;

        totalMedia = ptrNoAtualBD->dados.media;
        totalMedia += ptrNoAtualED->dados.media;

        mediaGeral = (float)totalMedia / 2;

        inserirListaOrdenada(ptrMediaGeral,ptrNoAtualBD->dados.matricula, 
                            ptrNoAtualBD->dados.nome, mediaGeral);

		ptrNoAtualBD = ptrNoAtualBD->proxNo;
		ptrNoAtualED = ptrNoAtualED->proxNo;
	}

}


void calcularMediaVersao02(Lista *ptrDiscBD, Lista *ptrDiscED, 
                            Lista *ptrMediaGeral, Lista *ptrCurso) {

    No *ptrNoAtualBD;
    No *ptrNoAtualED;
    No *ptrNoCurso;

    float totalMedia;


    int matricula;
    string nome;
    float mediaGeral;



    ptrNoAtualBD = ptrDiscBD->inicio;
	ptrNoAtualED = ptrDiscED->inicio;
	ptrNoCurso = ptrCurso->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtualBD != NULL) {

		// matricula = ptrNoAtualBD->dados.matricula;
        // nome = ptrNoAtualBD->dados.nome;

        totalMedia = ptrNoAtualBD->dados.media;
        totalMedia += ptrNoAtualED->dados.media;

        mediaGeral = (float)totalMedia / 2;

        inserirListaOrdenada(ptrMediaGeral,ptrNoAtualBD->dados.matricula, 
                            ptrNoAtualBD->dados.nome, mediaGeral);

		ptrNoAtualBD = ptrNoAtualBD->proxNo;
		ptrNoAtualED = ptrNoAtualED->proxNo;
	}

}
void concatenarLista(Lista* pDiscBD, Lista* pDiscED, Lista* pCurso) {
	No* ptrNoAtual;	
	
	int matricula;
	string nome;
	float media;

	ptrNoAtual = pDiscBD->inicio;	

	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

		matricula = ptrNoAtual->dados.matricula;
		nome = ptrNoAtual->dados.nome;
		media = ptrNoAtual->dados.media;

		inserirListaFim(pCurso, matricula, nome, media);

		ptrNoAtual = ptrNoAtual->proxNo;
	}


	ptrNoAtual = pDiscED->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

		matricula = ptrNoAtual->dados.matricula;
		nome = ptrNoAtual->dados.nome;
		media = ptrNoAtual->dados.media;

		inserirListaFim(pCurso, matricula, nome, media);

		ptrNoAtual = ptrNoAtual->proxNo;
	}
}


   