#include <iostream>
#include <locale.h> 
#include <stdlib.h> 
#include <string>

using namespace std;

// Dados sobre o ALUNO
struct Dados {
	int codProduto;
	string descricao;
	float preco;
	string fabricante;
};

// Estrutura do Nó
struct No {
	Dados dados;	// estrutura guardada dentro da lista	
	No* proxNo;		// aponta para o próximo Nó da lista
};

// Nó início da lista
struct Lista {
	int qtdNo;

	No* inicio;
};

Lista* criarLista();
void liberarLista(Lista* ptrLista);
void exibirLista(Lista* ptrLista);
void pesqMaior50(Lista* ptrLista);
void Preco_menor(Lista* ptrLista,float preco);

// Insere
//bool inserirListaInicio(Lista* ptrLista, int matricula, string nome, float media);
//bool inserirListaFim(Lista* ptrLista, int matricula, string nome, float media);
bool inserirListaOrdenada(Lista* ptrLista, int codProduto, string descricao, float preco, string fabricante);

// Remove
//bool removerListaInicio(Lista* ptrLista);
//bool removerListaFim(Lista* ptrLista);
bool removerListaOrdenada(Lista* ptrLista, int codProduto);

// Pesquisa/Altera
No* pesquisarProduto(Lista* ptrLista, int codProduto);


int main() {
	setlocale(LC_ALL, "Portuguese");
	bool operacaoOK;

	Lista* pLista;
	pLista = criarLista();
		

	//-------------------------------------------------
	// Inserir Ordenado
	//-------------------------------------------------
	inserirListaOrdenada(pLista, 30, "Omo", 7.5, "Fab Detergente");
	inserirListaOrdenada(pLista, 10, "Pão", 3.0, "Fab Padeiro");
	inserirListaOrdenada(pLista, 20, "Leite", 5.5, "Fab Vaca");
	

	exibirLista(pLista);

    float prec;
    std::cout << "/* message */" << std::endl;
//    Preco_menor(pLista,50);

	

	//-------------------------------------------------
	// Desaloca memória
	//-------------------------------------------------
	liberarLista(pLista);

	system("pause");
	return 0;
}

//--------------------------------------------------------
// CRIAR LISTA
//--------------------------------------------------------
Lista* criarLista() {
	Lista* ptrLista;

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
void liberarLista(Lista* ptrLista) {
	No* ptrNoAtual;

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

		cout << "Código Produto: " << ptrNoAtual->dados.codProduto << endl;
		cout << "Descrição: " << ptrNoAtual->dados.descricao << endl;
		cout << "Preço: " << ptrNoAtual->dados.preco << endl ;
		cout << "Fabricante: " << ptrNoAtual->dados.fabricante << endl << endl << endl;

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

	ptrNoNovo->dados.codProduto = matricula;
	ptrNoNovo->dados.descricao = nome;
	ptrNoNovo->dados.preco = media;
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
	No* ptrNoNovo;
	No* ptrNoAtual;

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

	ptrNoNovo->dados.codProduto = matricula;
	ptrNoNovo->dados.descricao = nome;
	ptrNoNovo->dados.preco = media;
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
bool inserirListaOrdenada(Lista* ptrLista, int codProduto, string descricao, float preco, string fabricante) {
	No* ptrNoNovo;
	No* ptrNoAnterior;
	No* ptrNoAtual;

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

	ptrNoNovo->dados.codProduto = codProduto;
	ptrNoNovo->dados.descricao = descricao;
	ptrNoNovo->dados.preco = preco;
	ptrNoNovo->dados.fabricante = fabricante;
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
		while (ptrNoAtual != NULL && ptrNoAtual->dados.codProduto < codProduto) {
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
bool removerListaInicio(Lista* ptrLista) {
	No* ptrNoAtual;

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
bool removerListaFim(Lista* ptrLista) {
	No* ptrNoAnterior;
	No* ptrNoAtual;

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
bool removerListaOrdenada(Lista* ptrLista, int codProduto) {
	No* ptrNoAnterior;
	No* ptrNoAtual;

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
	while (ptrNoAtual != NULL && ptrNoAtual->dados.codProduto != codProduto) {
		ptrNoAnterior = ptrNoAtual;
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	if (ptrNoAtual == NULL) {
		cout << "O código do produto " << codProduto << " não foi encontrado!" << endl;
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
No* pesquisarProduto(Lista* ptrLista, int codProduto) {
	No* ptrNoAtual;

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
	while (ptrNoAtual != NULL && ptrNoAtual->dados.codProduto != codProduto) {
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	if (ptrNoAtual == NULL) {
		cout << "O código do produto " << codProduto << " não foi encontrado!" << endl;
		return NULL;
	}

	return ptrNoAtual;
}

//--------------------------------------------------------
// 
//--------------------------------------------------------
void pesqMaior5(Lista* ptrLista) {
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

		

		ptrNoAtual = ptrNoAtual->proxNo;
	}	
}


void pesqMaior50(Lista* ptrLista) {
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

		if (ptrNoAtual->dados.preco > 50) {
			cout << "Código Produto: " << ptrNoAtual->dados.codProduto << endl;
			cout << "Descrição: " << ptrNoAtual->dados.descricao << endl;
			cout << "Preço: " << ptrNoAtual->dados.preco << endl;
			cout << "Fabricante: " << ptrNoAtual->dados.fabricante << endl << endl << endl;
		}

		ptrNoAtual = ptrNoAtual->proxNo;
	}	
}
void Preco_menor(Lista* ptrLista,float preco){
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

		if (ptrNoAtual->dados.preco < preco) {
			cout << "Código Produto: " << ptrNoAtual->dados.codProduto << endl;
			cout << "Descrição: " << ptrNoAtual->dados.descricao << endl;
			cout << "Preço: " << ptrNoAtual->dados.preco << endl;
			cout << "Fabricante: " << ptrNoAtual->dados.fabricante << endl << endl << endl;
		}

		ptrNoAtual = ptrNoAtual->proxNo;
	}	
}

