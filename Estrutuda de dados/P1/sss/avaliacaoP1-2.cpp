#include <iostream>
#include <locale.h> 
#include <stdlib.h> 
#include <string>

using namespace std;

// Dados sobre o ALUNO
struct Dados {
    int id_medicamento;
    string nome_medicamento;
    string nome_laboratorio;
    string princio_ativo;
    float preco_compra;
    float preco_venda;
    int mes_vencimento;
    int ano_vencimento;
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

// Insere
bool inserirListaFim(Lista *ptrLista, int id_medicamento, string nome_medicamento, 
                            string nome_laboratorio, string principio_ativo,
                            float preco_compra, float preco_venda, int mes_vencimento, int ano_vencimento);


// Pesquisa/Altera
No* pesquisarAluno(Lista* ptrLista, int matricula);

void calcularMediaVersao01(Lista *ptrDiscBD, Lista *ptrDiscED, Lista *ptrMediaGeral);
void concatenarListas(Lista *medGenerico, Lista *medControlado, Lista *medEmEstoque);
void somaPrecos(Lista* medEmEstoque);


int main() {
	setlocale(LC_ALL, "Portuguese");

    Lista *medControlado, *medGenerico, *medEmEstoque;
	

    medControlado = criarLista();
    medGenerico = criarLista();
    medEmEstoque = criarLista();


	//-------------------------------------------------
	// Inserir Ordenado
	//-------------------------------------------------
    inserirListaFim(medControlado, 1, "Medicamento Controlado 01", "Laboratório 1", "Princípio ativo 1", 10.1, 10.2, 1, 2021);
    inserirListaFim(medControlado, 2, "Medicamento Controlado 02", "Laboratório 2", "Princípio ativo 2", 11.1, 11.2, 2, 2021);
    inserirListaFim(medControlado, 3, "Medicamento Controlado 03", "Laboratório 3", "Princípio ativo 3", 12.1, 12.2, 11, 2020);
    inserirListaFim(medControlado, 4, "Medicamento Controlado 04", "Laboratório 4", "Princípio ativo 4", 13.1, 13.2, 4, 2021);
    inserirListaFim(medControlado, 5, "Medicamento Controlado 05", "Laboratório 5", "Princípio ativo 5", 14.1, 14.2, 5, 2021);
    inserirListaFim(medControlado, 6, "Medicamento Controlado 06", "Laboratório 6", "Princípio ativo 6", 15.1, 15.2, 12, 2020);
    inserirListaFim(medControlado, 7, "Medicamento Controlado 07", "Laboratório 7", "Princípio ativo 7", 16.1, 16.2, 7, 2021);
    inserirListaFim(medControlado, 8, "Medicamento Controlado 08", "Laboratório 8", "Princípio ativo 8", 17.1, 17.2, 8, 2021);
    inserirListaFim(medControlado, 9, "Medicamento Controlado 09", "Laboratório 9", "Princípio ativo 9", 18.1, 18.2, 9, 2021);
    inserirListaFim(medControlado, 10, "Medicamento Controlado 10", "Laboratório 10", "Princípio ativo 10", 19.1, 19.2, 10, 2021);


    inserirListaFim(medGenerico, 1, "Medicamento Genérico 01", "Laboratório 1", "Princípio ativo 1", 10.1, 10.2, 1, 2021);
    inserirListaFim(medGenerico, 2, "Medicamento Genérico 02", "Laboratório 2", "Princípio ativo 2", 11.1, 11.2, 2, 2021);
    inserirListaFim(medGenerico, 3, "Medicamento Genérico 03", "Laboratório 3", "Princípio ativo 3", 12.1, 12.2, 11, 2020);
    inserirListaFim(medGenerico, 4, "Medicamento Genérico 04", "Laboratório 4", "Princípio ativo 4", 13.1, 13.2, 4, 2021);
    inserirListaFim(medGenerico, 5, "Medicamento Genérico 05", "Laboratório 5", "Princípio ativo 5", 14.1, 14.2, 5, 2021);
    inserirListaFim(medGenerico, 6, "Medicamento Genérico 06", "Laboratório 6", "Princípio ativo 6", 15.1, 15.2, 12, 2020);
    inserirListaFim(medGenerico, 7, "Medicamento Genérico 07", "Laboratório 7", "Princípio ativo 7", 16.1, 16.2, 7, 2021);
    inserirListaFim(medGenerico, 8, "Medicamento Genérico 08", "Laboratório 8", "Princípio ativo 8", 17.1, 17.2, 8, 2021);
    inserirListaFim(medGenerico, 9, "Medicamento Genérico 09", "Laboratório 9", "Princípio ativo 9", 18.1, 18.2, 9, 2021);
    inserirListaFim(medGenerico, 10, "Medicamento Genérico 10", "Laboratório 10", "Princípio ativo 10", 19.1, 19.2, 10, 2021);



    concatenarListas(medControlado, medGenerico, medEmEstoque);
    exibirLista(medEmEstoque);

	somaPrecos(medEmEstoque);

	//-------------------------------------------------
	// Desaloca memória
	//-------------------------------------------------
	liberarLista(medControlado);
	liberarLista(medGenerico);
	liberarLista(medEmEstoque);

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

        cout << "Id: " << ptrNoAtual->dados.id_medicamento << endl;
        cout << "Medicamento: " << ptrNoAtual->dados.nome_medicamento << endl;
        cout << "Laboratório: " << ptrNoAtual->dados.nome_laboratorio << endl;
        cout << "Princípio Ativo: " << ptrNoAtual->dados.princio_ativo << endl;
        cout << "Preço de Compra: " << ptrNoAtual->dados.preco_compra << endl;
        cout << "Preço de Venda: " << ptrNoAtual->dados.preco_venda << endl;
        cout << "Mês de Vencimento: " << ptrNoAtual->dados.mes_vencimento << endl;
        cout << "Ano de Vencimento: " << ptrNoAtual->dados.ano_vencimento << "\n\n\n";

		ptrNoAtual = ptrNoAtual->proxNo;
	}

	cout << endl;
}


//--------------------------------------------------------
// INSERIR NO FINAL DA LISTA
//--------------------------------------------------------
bool inserirListaFim(Lista *ptrLista, int id_medicamento, string nome_medicamento, 
                            string nome_laboratorio, string principio_ativo,
                            float preco_compra, float preco_venda, int mes_vencimento, int ano_vencimento) {
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

    ptrNoNovo->dados.id_medicamento = id_medicamento;
    ptrNoNovo->dados.nome_medicamento = nome_medicamento;
    ptrNoNovo->dados.nome_laboratorio = nome_laboratorio;
    ptrNoNovo->dados.princio_ativo = principio_ativo;
    ptrNoNovo->dados.preco_compra = preco_compra;
    ptrNoNovo->dados.preco_venda = preco_venda;
    ptrNoNovo->dados.mes_vencimento = mes_vencimento;
    ptrNoNovo->dados.ano_vencimento = ano_vencimento;

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
	while (ptrNoAtual != NULL && ptrNoAtual->dados.id_medicamento != matricula) {		
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	if (ptrNoAtual == NULL) {
		cout << "A matrícula " << matricula << " não foi encontrada!" << endl;
		return NULL;
	}
		
	return ptrNoAtual;
}




void concatenarListas(Lista *medGenerico, Lista *medControlado, Lista *medEmEstoque) {

    No *ptrNoAtual;


    // Prepara o No para inserção
    ptrNoAtual = medControlado->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

        inserirListaFim(medEmEstoque, ptrNoAtual->dados.id_medicamento, ptrNoAtual->dados.nome_medicamento, 
                            ptrNoAtual->dados.nome_laboratorio, ptrNoAtual->dados.princio_ativo,
                            ptrNoAtual->dados.preco_compra, ptrNoAtual->dados.preco_venda, 
                            ptrNoAtual->dados.mes_vencimento, ptrNoAtual->dados.ano_vencimento);

		ptrNoAtual = ptrNoAtual->proxNo;
	}



    // Prepara o No para inserção
    ptrNoAtual = medGenerico->inicio;
	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

        inserirListaFim(medEmEstoque, ptrNoAtual->dados.id_medicamento, ptrNoAtual->dados.nome_medicamento, 
                            ptrNoAtual->dados.nome_laboratorio, ptrNoAtual->dados.princio_ativo,
                            ptrNoAtual->dados.preco_compra, ptrNoAtual->dados.preco_venda, 
                            ptrNoAtual->dados.mes_vencimento, ptrNoAtual->dados.ano_vencimento);

		ptrNoAtual = ptrNoAtual->proxNo;
	}

}

void somaPrecos(Lista* medEmEstoque) {
	No* ptrNoAtual;
    float precoCompra;
    float precoVenda;
    precoCompra = 0;
    precoVenda = 0;


	//Se a lista NÃO foi criada
	if (medEmEstoque == NULL) {
		cout << "A lista não está criada!" << endl;
		return;
	}

	//Se não tiver nenhum Nó na lista
	if (medEmEstoque->inicio == NULL) {
		cout << "A lista esta vazia!" << endl;
		return;
	}

	ptrNoAtual = medEmEstoque->inicio;

	while (ptrNoAtual != NULL) {
        precoCompra += ptrNoAtual->dados.preco_compra;

		ptrNoAtual = ptrNoAtual->proxNo;
	}



    ptrNoAtual = medEmEstoque->inicio;

	while (ptrNoAtual != NULL) {
        precoVenda += ptrNoAtual->dados.preco_venda;

		ptrNoAtual = ptrNoAtual->proxNo;
	}


    cout << "Preço total de compra: " << precoCompra << "\n\n";
    cout << "Preço total de venda: " << precoVenda << "\n\n";
    

	cout << endl;
}
