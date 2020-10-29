// Por Janderson Barbosa Gonçalves , Aluno da Fatec Ribeirão Preto
// como o programa foi feito em ambiente Linux, segue link de compilador online com base no linux
// https://repl.it/languages/c

#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <unistd.h>// função sleep()
#include <stdio.h>
#include <iomanip> // casas decimais
#include <string.h>
#include <string>
#include <float.h>
#include <cfloat> // funções FLT_MIN_EXP   FLT_MAX_EXP


using namespace std;

// Dados sobre o ALUNO
struct Dados {
	int codigo;
	string nome_medic;
    string nome_lab;
    string pr_ativo;
    float prec_compra;
	float prec_venda;
    int ano_validade;
    string mes_validade;
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

//--------------------------------------------------------
// PROTÓTIPOS
//--------------------------------------------------------
Lista* criarLista();
void liberarLista(Lista* ptrLista);
void exibirLista(Lista* ptrLista);
void imprimi_ativo(Lista* ptrLista, string pr_ativo);
void exibir_caro_barato(Lista * ptrLista);
void pesquisaMesVencimento(Lista* ptrLista, string mesVencimento);
void concatenarLista(Lista* MedControlado, Lista* MedGenerico ,Lista* MedEmEstoque);
void somarPrecos(Lista *MedEmEstoque);



// Insere
bool inserirListaOrdenada(Lista *ptrLista, int codigo, string nome_medic,string nome_lab,string pr_ativo, float prec_compra,float prec_venda,int ano_validade, string mes_validade);

// Remove
bool removerListaOrdenada(Lista *ptrLista, string nome_medic);



int main() {
	setlocale(LC_ALL, "Portuguese");
    cout << fixed <<setprecision(2);

    Lista *Plista, *MedControlado,*MedGenerico,*MedEmEstoque;

    Plista = criarLista();
    MedControlado = criarLista();
    MedGenerico = criarLista();
    MedEmEstoque = criarLista();
    

    // INSERINDO DADOS ORDENADO PELO NOME DO MEDICAMENTO
    inserirListaOrdenada(Plista,1000,"Azorgan","FABBOTT","Não informado",50.00,100.00,2020,"Janeiro");
    inserirListaOrdenada(Plista,1001,"Benzilpenicilina","ACCORD","Não informado",80.00,150.00,2020,"Fevereiro");
    inserirListaOrdenada(Plista,1002,"Amoxicilina ","BAYER","80mg",200.00,300.00,2020," Março");
    inserirListaOrdenada(Plista,1003,"Cloxacilina","BEKER","80mg",500.00,800.00,2020,"Abril");
    inserirListaOrdenada(Plista,1004,"Flucloxacilina","CIFARMA","80mg",20.00,80.00,2021,"Junho");
    inserirListaOrdenada(Plista,1005,"Cefotaxima","COSMED","80mg",600.00,1000.00,2021,"Julho");
    inserirListaOrdenada(Plista,1006,"Vancomicina ","DROXTER","80mg",50.00,150.00,2021,"Agosto");
    inserirListaOrdenada(Plista,1007,"Rivotril","EUROFARMA","Não informado",20.00,70.00,2021,"Setembro");
    inserirListaOrdenada(Plista,1008,"Citalopram.","GEOLAB","80mg",300.00,500.00,2021,"Novembro");
    inserirListaOrdenada(Plista,1009,"Citalopram.","GEOLAB","80mg",24.00,10.00,2021,"Dezembro");
	
    // Inserido dados Ordenado na lista MedControlado
    inserirListaOrdenada(MedControlado,1010,"Azorgan","FABBOTT","Não informado",50.00,100.00,2020,"Janeiro");
    inserirListaOrdenada(MedControlado,1011,"Benzilpenicilina","ACCORD","Não informado",80.00,150.00,2020,"Fevereiro");
    inserirListaOrdenada(MedControlado,1012,"Amoxicilina ","BAYER","80mg",200.00,300.00,2020," Março");
    inserirListaOrdenada(MedControlado,1013,"Cloxacilina","BEKER","80mg",500.00,800.00,2020,"Abril");
    inserirListaOrdenada(MedControlado,1014,"Flucloxacilina","CIFARMA","80mg",20.00,80.00,2021,"Junho");

    // Inserido dados Ordenado na lista MedGenerico
    inserirListaOrdenada(MedGenerico,1020,"Azorgan","FABBOTT","Não informado",50.00,100.00,2020,"Janeiro");
    inserirListaOrdenada(MedGenerico,1021,"Benzilpenicilina","ACCORD","Não informado",80.00,150.00,2020,"Fevereiro");
    inserirListaOrdenada(MedGenerico,1022,"Amoxicilina ","BAYER","80mg",200.00,300.00,2020," Março");
    inserirListaOrdenada(MedGenerico,1023,"Cloxacilina","BEKER","80mg",500.00,800.00,2020,"Abril");
    inserirListaOrdenada(MedGenerico,1024,"Flucloxacilina","CIFARMA","80mg",20.00,80.00,2021,"Junho");




//    exibirLista(Plista);

//  VERIFICA SE POSSUI NO CAMPO DE PRINCIPIO ATIVO DESCRITO "NÃO INFORMADO" CASO SIM NÃO IMPRIME MEDICAMENTO
//    imprimi_ativo(Plista,"Não informado");

//    exibir_caro_barato(Plista);
   pesquisaMesVencimento(Plista,"Janeiro");
    

    sleep(3);// função sleep no lugar de system(pause);




	//-------------------------------------------------
	// Desalocar memória
	//-------------------------------------------------

    liberarLista(Plista);
    liberarLista(MedControlado);
    liberarLista(MedGenerico);
    liberarLista(MedEmEstoque);


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

        cout << "Código: " << ptrNoAtual->dados.codigo << endl;
		cout << "Nome Medicamento: " << ptrNoAtual->dados.nome_medic << endl;
		cout << "laboratório: " << ptrNoAtual->dados.nome_lab << endl;
		cout << "Principio Ativo: " << ptrNoAtual->dados.pr_ativo << endl ;
        cout << "Preço de compra: " <<ptrNoAtual->dados.prec_compra << endl; 
        cout << "Preço de venda: " <<ptrNoAtual->dados.prec_venda << endl ;
        cout << "Ano de validade: " <<ptrNoAtual->dados.ano_validade<< endl ;
        cout << "Mês de validade: " <<ptrNoAtual->dados.mes_validade << endl ;
        cout << endl;

		ptrNoAtual = ptrNoAtual->proxNo;
	}

	cout << endl;
}


//--------------------------------------------------------
// INSERIR EM LISTA ORDENADA
//--------------------------------------------------------
bool inserirListaOrdenada(Lista *ptrLista, int codigo, string nome_medic,string nome_lab,string pr_ativo, float prec_compra,float prec_venda,int ano_validade, string mes_validade) {
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
    ptrNoNovo->dados.codigo = codigo;
	ptrNoNovo->dados.nome_medic = nome_medic;
	ptrNoNovo->dados.nome_lab = nome_lab;
	ptrNoNovo->dados.pr_ativo = pr_ativo;
    ptrNoNovo->dados.prec_compra = prec_compra;
    ptrNoNovo->dados.prec_venda = prec_venda;
    ptrNoNovo->dados.ano_validade = ano_validade;
    ptrNoNovo->dados.mes_validade = mes_validade;	
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
		while (ptrNoAtual != NULL && ptrNoAtual->dados.nome_medic < nome_medic) {
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
// REMOVER ORDENADO DA LISTA
//--------------------------------------------------------
bool removerListaOrdenada(Lista *ptrLista, string nome_medic) {
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
	while (ptrNoAtual != NULL && ptrNoAtual->dados.nome_medic != nome_medic) {
		ptrNoAnterior = ptrNoAtual;
		ptrNoAtual = ptrNoAtual->proxNo;
	}

	if (ptrNoAtual == NULL) {
		cout << "A matrícula " << nome_medic << " não foi encontrada!" << endl;
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
// FUNCAO IMPRIMIR PRINCIPIO ATIVO
//--------------------------------------------------------

void imprimi_ativo(Lista* ptrLista, string pr_ativo){
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

        // VERIFICA SE POSSUI NO CAMPO DE PRINCIPIO ATIVO DESCRITO "NÃO INFORMADO" CASO SIM NÃO IMPRIME MEDICAMENTO
		if (ptrNoAtual->dados.pr_ativo != pr_ativo){
			cout << "Código: " << ptrNoAtual->dados.codigo << endl;
            cout << "Nome Medicamento: " << ptrNoAtual->dados.nome_medic << endl;
            cout << "laboratório: " << ptrNoAtual->dados.nome_lab << endl;
            cout << "Principio Ativo: " << ptrNoAtual->dados.pr_ativo << endl ;
            cout << "Preço de compra: " <<ptrNoAtual->dados.prec_compra << endl; 
            cout << "Preço de venda: " <<ptrNoAtual->dados.prec_venda << endl ;
            cout << "Ano de validade: " <<ptrNoAtual->dados.ano_validade<< endl ;
            cout << "Mês de validade: " <<ptrNoAtual->dados.mes_validade << endl ;
            cout << endl;
		}

		ptrNoAtual = ptrNoAtual->proxNo;
	}	





    
}

//--------------------------------------------------------
// FUNCAO PESQUISAR MES DE VENCIMENTO
//--------------------------------------------------------
void pesquisaMesVencimento(Lista* ptrLista, string mesVencimento) {
	No* ptrNoAtual;
    string mes1;
    string mes2;
    string mes3;

         if(mesVencimento == "Janeiro"){
            mes1 = "Novembro";
            mes2 = "Dezembro";
            mes3 = "Janeiro";

        }
        else if (mesVencimento == "Fevereiro") {
            mes1 = "Dezembro";
            mes2 = "Janeiro";
            mes3 = "Fevereiro";

        }
        
        else if (mesVencimento == "Março") {
            mes1 = "Janeiro";
            mes2 = "Fevereiro";
            mes3 = "Março";

        } 
        else if(mesVencimento == "Abril"){
            mes1 = "Fevereiro";
            mes2 = "Março";
            mes3 = "Abril";

        }
        else if(mesVencimento == "Maio"){
            mes1 = "Março";
            mes2 = "Abril";
            mes3 = "Maio";

        }
        else if(mesVencimento == "Junho"){
            mes1 = "Abril";
            mes2 = "Maio";
            mes3 = "Junho";

        }
        else if(mesVencimento == "Julho"){
            mes1 = "Maio";
            mes2 = "Junho";
            mes3 = "Julho";

        }
        else if(mesVencimento == "Agosto"){
            mes1 = "Junho";
            mes2 = "Julho";
            mes3 = "Agosto";

        }
        else if(mesVencimento == "Setembro"){
            mes1 = "Julho";
            mes2 = "Agosto";
            mes3 = "Setembro";

        }
        else if(mesVencimento == "Outubro"){
            mes1 = "Agosto";
            mes2 = "Setembro";
            mes3 = "Outubro";

        }
        else if(mesVencimento == "Novembro"){
            mes1 = "Setembro";
            mes2 = "Outubro";
            mes3 = "Novembro";
	
        }
        else if(mesVencimento == "Dezembro"){
            mes1 = "Outubro";
            mes2 = "Novembro";
            mes3 = "Dezembro";

	
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
        if (ptrNoAtual->dados.mes_validade == mes1) {

            cout << "O medicamento a seguir irá Vencer em 3 meses!!!\n\n";


            cout << "Código: " << ptrNoAtual->dados.codigo << endl;
            cout << "Nome Medicamento: " << ptrNoAtual->dados.nome_medic << endl;
            cout << "laboratório: " << ptrNoAtual->dados.nome_lab << endl;
            cout << "Principio Ativo: " << ptrNoAtual->dados.pr_ativo << endl ;
            cout << "Preço de compra: " <<ptrNoAtual->dados.prec_compra << endl; 
            cout << "Preço de venda: " <<ptrNoAtual->dados.prec_venda << endl ;
            cout << "Ano de validade: " <<ptrNoAtual->dados.ano_validade<< endl ;
            cout << "Mês de validade: " <<ptrNoAtual->dados.mes_validade << endl ;
            cout << endl;      
            
            }
		

		ptrNoAtual = ptrNoAtual->proxNo;
	}
}


//--------------------------------------------------------
// FUNCAO IMPRIMIR PRODUTO MAIS BARATO E MAIS CARO
//--------------------------------------------------------

void exibir_caro_barato(Lista * ptrLista){
    No* ptrNoAtual;
    float caro, barato;

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

    // Variaveis Para receber medicamentos caros e baratos
    caro = FLT_MIN_EXP;
    barato = FLT_MAX_EXP;

   // Estrutura para percorre os nós para capturar o maior valor
	while (ptrNoAtual != NULL) {

		if (ptrNoAtual->dados.prec_venda > caro) {
            
            caro = ptrNoAtual->dados.prec_venda;
                           
		}
        ptrNoAtual = ptrNoAtual->proxNo;
	}	
    ptrNoAtual = ptrLista->inicio;


   // Estrutura para percorre os nós para apresentar se o valor encontrado anteriormente corresponde ao da variavel
    while (ptrNoAtual != NULL) {

        if (ptrNoAtual->dados.prec_venda == caro)
        {
            cout << "Medicamento Mais caro da lista\n\n"<< endl ;
            cout << "Código: " << ptrNoAtual->dados.codigo << endl;
            cout << "Nome Medicamento: " << ptrNoAtual->dados.nome_medic << endl;
            cout << "laboratório: " << ptrNoAtual->dados.nome_lab << endl;
            cout << "Principio Ativo: " << ptrNoAtual->dados.pr_ativo << endl ;
            cout << "Preço de compra: " <<ptrNoAtual->dados.prec_compra << endl; 
            cout << "Preço de venda: " <<ptrNoAtual->dados.prec_venda << endl ;
            cout << "Ano de validade: " <<ptrNoAtual->dados.ano_validade<< endl ;
            cout << "Mês de validade: " <<ptrNoAtual->dados.mes_validade << endl ;
            cout << endl;
         }
        
        ptrNoAtual = ptrNoAtual->proxNo;


    }
    cout << endl;

// ------------------------------------------------------------------------------- Menor Valor
    ptrNoAtual = ptrLista->inicio;

    // Estrutura para percorre os nós para capturar o menor valor
	while (ptrNoAtual != NULL) {
        if (ptrNoAtual->dados.prec_venda < barato){
            barato= ptrNoAtual->dados.prec_venda;
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}

    ptrNoAtual = ptrLista->inicio;

    // Estrutura para percorre os nós mostrar menor valor
	while (ptrNoAtual != NULL) {

        if (ptrNoAtual->dados.prec_venda == barato) {
            cout << "Medicamento mais Barato da lista \n\n";

            cout << "Código: " << ptrNoAtual->dados.codigo << endl;
            cout << "Nome Medicamento: " << ptrNoAtual->dados.nome_medic << endl;
            cout << "laboratório: " << ptrNoAtual->dados.nome_lab << endl;
            cout << "Principio Ativo: " << ptrNoAtual->dados.pr_ativo << endl ;
            cout << "Preço de compra: " <<ptrNoAtual->dados.prec_compra << endl; 
            cout << "Preço de venda: " <<ptrNoAtual->dados.prec_venda << endl ;
            cout << "Ano de validade: " <<ptrNoAtual->dados.ano_validade<< endl ;
            cout << "Mês de validade: " <<ptrNoAtual->dados.mes_validade << endl ;
            cout << endl;       
        }

		ptrNoAtual = ptrNoAtual->proxNo;
	}


	cout << endl;

}

//--------------------------------------------------------
// FUNCAO CONCATENAR LISTAS
//--------------------------------------------------------
void concatenarLista(Lista* MedControlado, Lista* MedGenerico ,Lista* MedEmEstoque) {
	No* ptrNoAtual;	
	
	int codigo;
	string nome_medic;
    string nome_lab;
    string pr_ativo;
    float prec_compra;
	float prec_venda;
    int ano_validade;
    string mes_validade;

     // Prepara o No para inserção
	ptrNoAtual = MedControlado->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

		inserirListaOrdenada(MedEmEstoque,ptrNoAtual->dados.codigo,ptrNoAtual->dados.nome_medic,ptrNoAtual->dados.nome_lab,ptrNoAtual->dados.pr_ativo,ptrNoAtual->dados.prec_compra,ptrNoAtual->dados.prec_venda,ptrNoAtual->dados.ano_validade,ptrNoAtual->dados.mes_validade);

		ptrNoAtual = ptrNoAtual->proxNo;
	}

    // Prepara o No para inserção
	ptrNoAtual = MedGenerico->inicio;

	// Localiza a posição de inserção
	while (ptrNoAtual != NULL) {

        inserirListaOrdenada(MedEmEstoque,ptrNoAtual->dados.codigo,ptrNoAtual->dados.nome_medic,ptrNoAtual->dados.nome_lab,ptrNoAtual->dados.pr_ativo,ptrNoAtual->dados.prec_compra,ptrNoAtual->dados.prec_venda,ptrNoAtual->dados.ano_validade,ptrNoAtual->dados.mes_validade);

		ptrNoAtual = ptrNoAtual->proxNo;
	}
}


//--------------------------------------------------------
// FUNCAO SOMAR PRECOS DE VENDA E COMPRA
//--------------------------------------------------------
void somarPrecos(Lista *MedEmEstoque){

No* ptrNoAtual;

    float precoCompra;
    float precoVenda;
    precoCompra = 0;
    precoVenda = 0;


	//Se a lista NÃO foi criada
	if (MedEmEstoque == NULL) {
		cout << "A lista não está criada!" << endl;
		return;
	}

	//Se não tiver nenhum Nó na lista
	if (MedEmEstoque->inicio == NULL) {
		cout << "A lista esta vazia!" << endl;
		return;
	}

	ptrNoAtual = MedEmEstoque->inicio;

	while (ptrNoAtual != NULL) {
        precoCompra += ptrNoAtual->dados.prec_compra;

		ptrNoAtual = ptrNoAtual->proxNo;
	}



    ptrNoAtual = MedEmEstoque->inicio;

	while (ptrNoAtual != NULL) {
        precoVenda += ptrNoAtual->dados.prec_venda;

		ptrNoAtual = ptrNoAtual->proxNo;
	}


    cout << "Preço total de compra: " << precoCompra << "\n\n";
    cout << "Preço total de venda: " << precoVenda << "\n\n";
    

	cout << endl;


}
   