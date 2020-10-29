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


bool inserirListaInicio(Lista *ptrLista, int id_medicamento, string nome_medicamento, 
                            string nome_laboratorio, string principio_ativo,
                            float preco_compra, float preco_venda, int mes_vencimento, int ano_vencimento);



void exibirLista(Lista *ptrLista);
void pesqPrincipioAtivo(Lista* ptrLista, string principioAtivo);
void maiorMenorPreco(Lista* ptrLista);
void pesquisaMesVencimento(Lista* ptrLista, int mesVencimento);


int main() {

    setlocale(LC_ALL, "Portuguese");

    Lista *pLista;
    pLista = criarLista();

    // inserir no inicio

    inserirListaInicio(pLista, 1, "Medicamento 01", "Laboratório 1", "Princípio ativo 1", 10.1, 10.2, 1, 2021);
    inserirListaInicio(pLista, 2, "Medicamento 02", "Laboratório 2", "Princípio ativo 2", 11.1, 11.2, 2, 2021);
    inserirListaInicio(pLista, 3, "Medicamento 03", "Laboratório 3", "Princípio ativo 3", 12.1, 12.2, 11, 2020);
    inserirListaInicio(pLista, 4, "Medicamento 04", "Laboratório 4", "Princípio ativo 4", 13.1, 13.2, 4, 2021);
    inserirListaInicio(pLista, 5, "Medicamento 05", "Laboratório 5", "Princípio ativo 5", 14.1, 14.2, 5, 2021);
    inserirListaInicio(pLista, 6, "Medicamento 06", "Laboratório 6", "Princípio ativo 6", 15.1, 15.2, 12, 2020);
    inserirListaInicio(pLista, 7, "Medicamento 07", "Laboratório 7", "Princípio ativo 7", 16.1, 16.2, 7, 2021);
    inserirListaInicio(pLista, 8, "Medicamento 08", "Laboratório 8", "Princípio ativo 8", 17.1, 17.2, 8, 2021);
    inserirListaInicio(pLista, 9, "Medicamento 09", "Laboratório 9", "Princípio ativo 9", 18.1, 18.2, 9, 2021);
    inserirListaInicio(pLista, 10, "Medicamento 10", "Laboratório 10", "Princípio ativo 10", 19.1, 19.2, 10, 2021);




    // exibirLista(pLista);

    // Primeira Função
    pesqPrincipioAtivo(pLista, "Princípio ativo 1");
    
    // Segunda Função
    maiorMenorPreco(pLista);


    // Terceira Função
    pesquisaMesVencimento(pLista, 12);


    liberarLista(pLista);

    return 0;
}

//--------------------------------------------------------
// CRIAR LISTA
//--------------------------------------------------------
Lista *criarLista()
{

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
void liberarLista(Lista *ptrLista)
{

    No *ptrNoAtual;

    //Se a lista NÃO foi criada
    if (ptrLista == NULL)
    {

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
bool inserirListaInicio(Lista *ptrLista, int id_medicamento, string nome_medicamento, 
                            string nome_laboratorio, string principio_ativo,
                            float preco_compra, float preco_venda, int mes_vencimento, int ano_vencimento){

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

    if (ptrNoNovo == NULL)
    {
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


    ptrNoNovo->proxNo = ptrLista->inicio;

    ptrLista->inicio = ptrNoNovo;

    // Incrementa o quantidade de Nós
    ptrLista->qtdNo++;

    return true;
}


void exibirLista(Lista *ptrLista) {
    No *ptrNoAtual;

    // Se a lista não foi criada
    if (ptrLista == NULL)
    {
        cout << "A lista não está criada!" << endl;
        return;
    }

    // Se não tiver nenhum Nó na lista

    if (ptrLista->inicio == NULL)
    {
        cout << "A lista está vazia!" << endl;

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


void pesqPrincipioAtivo(Lista* ptrLista, string principioAtivo) {
	No* ptrNoAtual;
    bool found;
    found = false;

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
        if (ptrNoAtual->dados.princio_ativo == principioAtivo) {
            found = true;

            cout << "Princípio Ativo Encontrado!!!\n\n";

            cout << "Id: " << ptrNoAtual->dados.id_medicamento << endl;
            cout << "Medicamento: " << ptrNoAtual->dados.nome_medicamento << endl;
            cout << "Laboratório: " << ptrNoAtual->dados.nome_laboratorio << endl;
            cout << "Princípio Ativo: " << ptrNoAtual->dados.princio_ativo << endl;
            cout << "Preço de Compra: " << ptrNoAtual->dados.preco_compra << endl;
            cout << "Preço de Venda: " << ptrNoAtual->dados.preco_venda << endl;
            cout << "Mês de Vencimento: " << ptrNoAtual->dados.mes_vencimento << endl;
            cout << "Ano de Vencimento: " << ptrNoAtual->dados.ano_vencimento << "\n\n\n";        
            
            }
		

		ptrNoAtual = ptrNoAtual->proxNo;
	}
    if (found == false) {
        cout << "Produto não encontrado!\n\n\n";
    }	
}


void maiorMenorPreco(Lista* ptrLista) {
	No* ptrNoAtual;
    float maior = 0;
    float menor = 999;

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
        if (ptrNoAtual->dados.preco_compra > maior){
            maior = ptrNoAtual->dados.preco_compra;
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}

    ptrNoAtual = ptrLista->inicio;
	while (ptrNoAtual != NULL) {

        if (ptrNoAtual->dados.preco_compra == maior) {
            cout << "Maior preço: \n\n";

            cout << "Id: " << ptrNoAtual->dados.id_medicamento << endl;
            cout << "Medicamento: " << ptrNoAtual->dados.nome_medicamento << endl;
            cout << "Laboratório: " << ptrNoAtual->dados.nome_laboratorio << endl;
            cout << "Princípio Ativo: " << ptrNoAtual->dados.princio_ativo << endl;
            cout << "Preço de Compra: " << ptrNoAtual->dados.preco_compra << endl;
            cout << "Preço de Venda: " << ptrNoAtual->dados.preco_venda << endl;
            cout << "Mês de Vencimento: " << ptrNoAtual->dados.mes_vencimento << endl;
            cout << "Ano de Vencimento: " << ptrNoAtual->dados.ano_vencimento << "\n\n\n";        
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}


	cout << endl;

    // -------------------------------------------------------------------------------
    ptrNoAtual = ptrLista->inicio;

    
	while (ptrNoAtual != NULL) {
        if (ptrNoAtual->dados.preco_compra < menor){
            menor = ptrNoAtual->dados.preco_compra;
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}

    ptrNoAtual = ptrLista->inicio;
	while (ptrNoAtual != NULL) {

        if (ptrNoAtual->dados.preco_compra == menor) {
            cout << "Menor preço: \n\n";

            cout << "Id: " << ptrNoAtual->dados.id_medicamento << endl;
            cout << "Medicamento: " << ptrNoAtual->dados.nome_medicamento << endl;
            cout << "Laboratório: " << ptrNoAtual->dados.nome_laboratorio << endl;
            cout << "Princípio Ativo: " << ptrNoAtual->dados.princio_ativo << endl;
            cout << "Preço de Compra: " << ptrNoAtual->dados.preco_compra << endl;
            cout << "Preço de Venda: " << ptrNoAtual->dados.preco_venda << endl;
            cout << "Mês de Vencimento: " << ptrNoAtual->dados.mes_vencimento << endl;
            cout << "Ano de Vencimento: " << ptrNoAtual->dados.ano_vencimento << "\n\n\n";        
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}


	cout << endl;

}


void pesquisaMesVencimento(Lista* ptrLista, int mesVencimento) {
	No* ptrNoAtual;
    int mes1;
    int mes2;
    int mes3;

    if (mesVencimento > 10) {
        if (mesVencimento == 11) {
            mes1 = 11;
            mes2 = 12;
            mes3 = 1;
        } else if (mesVencimento == 12) {
            mes1 = 12;
            mes2 = 1;
            mes3 = 2;
        } else {
            mes1 = mesVencimento;
            mes2 = mesVencimento+1;
            mes3 = mesVencimento+2;
        }
    }


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
        if (mesVencimento == mes1 || mesVencimento == mes2 || mesVencimento == mes3) {

            cout << "O medicamento a seguir irá vencer no próximo trimestre!!!\n\n";

            cout << "Id: " << ptrNoAtual->dados.id_medicamento << endl;
            cout << "Medicamento: " << ptrNoAtual->dados.nome_medicamento << endl;
            cout << "Laboratório: " << ptrNoAtual->dados.nome_laboratorio << endl;
            cout << "Princípio Ativo: " << ptrNoAtual->dados.princio_ativo << endl;
            cout << "Preço de Compra: " << ptrNoAtual->dados.preco_compra << endl;
            cout << "Preço de Venda: " << ptrNoAtual->dados.preco_venda << endl;
            cout << "Mês de Vencimento: " << ptrNoAtual->dados.mes_vencimento << endl;
            cout << "Ano de Vencimento: " << ptrNoAtual->dados.ano_vencimento << "\n\n\n";        
            
            }
		

		ptrNoAtual = ptrNoAtual->proxNo;
	}
}

