//#include <iostream>
//#include <locale.h> 
//#include <stdlib.h> 
//#include <string>
//
//using namespace std;
//
//// Dados sobre o ALUNO
//struct Dados {
//	int matricula;
//	string nome;
//	float media;
//	
//};
//
//
//
//// Estrutura do Nó
//struct No {
//	No* antNo;			// NOVO aponta para o Nó anterior da lista
//	Dados dados;	// estrutura guardada dentro da lista	
//	No* proxNo;			// aponta para o próximo Nó da lista
//};
//
//// Nó início da lista
//struct Lista {
//	int qtdNo;
//	No* inicio;
//};
//
//Lista* criarLista();
//void liberarLista(Lista* ptrLista);
//void exibirLista(Lista* ptrLista);
//bool inserirListaInicio(Lista* ptrLista, int matricula, string nome, float media);
//bool inserirListaFim(Lista* ptrLista, int matricula, string nome, float media);
//bool inserirListaOrdenada(Lista* ptrLista, int matricula, string nome, float media);
//bool removerListaInicio(Lista* ptrLista);
//bool removerListaFim(Lista* ptrLista);
//bool removerListaOrdenada(Lista* ptrLista, int matricula);
//No* pesquisarDado(Lista* ptrLista, int matricula);
//void exibirListaEmOrdemReversa(Lista* ptrLista);
//void concatenarLista(Lista* pListaA, Lista* pListaB, Lista* pListaC);
//
//
//int main() {
//	setlocale(LC_ALL, "Portuguese");
//	Lista* pListaA;
//	Lista* pListaB;
//	Lista* pListaC;
//	pListaA = criarLista();
//	pListaB = criarLista();
//	pListaC = criarLista();
//	
//	//--------------------------------------
//	// Insere ORDENADO na lista
//	//--------------------------------------
//	inserirListaOrdenada(pListaA, 30, "Maria", 9.5);
//	inserirListaOrdenada(pListaA, 10, "Jesus", 10.0);
//	inserirListaOrdenada(pListaA, 20, "José", 9.0);
//    
//	cout << "Lista A"<< endl;
//	exibirLista(pListaA);
//	cout << "\n\n";
//	
//
//	inserirListaOrdenada(pListaB, 50, "Paulo", 7.5);
//	inserirListaOrdenada(pListaB, 40, "Pedro", 8.0);
//	inserirListaOrdenada(pListaB, 60, "Dora", 8.0);
//	
//	cout << "Lista B" << endl;
//	exibirLista(pListaB);
//	cout << "\n\n";
//	//exibirListaEmOrdemReversa(pLista);
//
//	concatenarLista(pListaA, pListaB, pListaC);
//
//	cout << "Lista C" << endl;
//	exibirLista(pListaC);
//
//	liberarLista(pListaA);
//	liberarLista(pListaB);
//	liberarLista(pListaC);
//
//	system("pause");
//	return 0;
//}
//
////--------------------------------------------------------
//// CONCATENAR A LISTA
////--------------------------------------------------------
//
//void concatenarLista(Lista* pListaA, Lista* pListaB, Lista* pListaC) {
//
//	No* ptrNoAtual;
//	int matricula;
//	string nome;
//	float media;
//
//	ptrNoAtual = pListaA->inicio;
//
//	while (ptrNoAtual != NULL){
//
//		matricula = ptrNoAtual->dados.matricula;
//		nome = ptrNoAtual->dados.nome;
//		media = ptrNoAtual->dados.media;
//		inserirListaFim(pListaC, matricula, nome, media);
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//	ptrNoAtual = pListaB->inicio;
//
//	while (ptrNoAtual != NULL) {
//
//		matricula = ptrNoAtual->dados.matricula;
//		nome = ptrNoAtual->dados.nome;
//		media = ptrNoAtual->dados.media;
//		inserirListaFim(pListaC, matricula, nome, media);
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//}
//
////--------------------------------------------------------
//// EXIBIR A LISTA
////--------------------------------------------------------
//void exibirListaEmOrdemReversa(Lista* ptrLista) {
//	No* ptrNoAtual;
//
//	//Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return;
//	}
//
//
//	//Se não tiver nenhum Nó na lista
//	if (ptrLista->inicio == NULL) {
//		cout << "A lista esta vazia!" << endl;
//		return;
//	}
//
//	ptrNoAtual = ptrLista->inicio;
//
//	// Encontra o último nó da lista
//	while (ptrNoAtual->proxNo != NULL) {
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//	while (ptrNoAtual != NULL) {
//		cout << "Matrícula: " << ptrNoAtual->dados.matricula << endl;
//		cout << "Nome: " << ptrNoAtual->dados.nome << endl;
//		cout << "Média: " << ptrNoAtual->dados.media << endl << endl;
//
//		ptrNoAtual = ptrNoAtual->antNo;
//	}
//}
//
//
////--------------------------------------------------------
//// CRIAR LISTA
////--------------------------------------------------------
//Lista* criarLista() {
//	Lista* ptrLista;
//
//	ptrLista = new Lista;
//
//	// Se a lista NÃO pode ser criada
//	if (ptrLista == NULL) {
//		cout << "Não foi possível criar a lista!" << endl;
//		return NULL;
//	}
//
//	// Como a lista está vazia o INÍCIO aponta para NULL	
//	ptrLista->qtdNo = 0;
//	ptrLista->inicio = NULL;
//
//	return ptrLista;
//}
//
////--------------------------------------------------------
//// LIBERAR LISTA
////--------------------------------------------------------
//void liberarLista(Lista* ptrLista) {
//	No* ptrNoAtual;
//
//	//Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return;
//	}
//
//	// Exclui cada Nó da lista
//	while (ptrLista->inicio != NULL)
//	{
//		ptrNoAtual = ptrLista->inicio;
//
//		ptrLista->inicio = ptrLista->inicio->proxNo;
//
//		delete  ptrNoAtual;
//	}
//
//	delete ptrLista;
//}
//
////--------------------------------------------------------
//// EXIBIR A LISTA
////--------------------------------------------------------
//void exibirLista(Lista* ptrLista) {
//	No* ptrNoAtual;
//
//	//Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return;
//	}
//
//
//	//Se não tiver nenhum Nó na lista
//	if (ptrLista->inicio == NULL) {
//		cout << "A lista esta vazia!" << endl;
//		return;
//	}
//
//	ptrNoAtual = ptrLista->inicio;
//
//	while (ptrNoAtual != NULL) {
//		cout << "Matrícula: " << ptrNoAtual->dados.matricula << endl;
//		cout << "Nome: " << ptrNoAtual->dados.nome << endl;
//		cout << "Média: " << ptrNoAtual->dados.media << endl << endl;
//
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//}
//
////--------------------------------------------------------
//// INSERIR NO INÍCIO DA LISTA
////--------------------------------------------------------
//bool inserirListaInicio(Lista* ptrLista, int matricula, string nome, float media) {
//	No* ptrNoNovo;
//	No* ptrNoAtual;
//
//	//Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return false;
//	}
//
//	//---------------------------------------------------------------
//	//	Cria o novo nó
//	//---------------------------------------------------------------
//	ptrNoNovo = new No;
//
//	if (ptrNoNovo == NULL) {
//		cout << "Memória insulficiente!" << endl;
//		return false;
//	}
//
//	ptrNoNovo->dados.matricula = matricula;
//	ptrNoNovo->dados.nome = nome;
//	ptrNoNovo->dados.media = media;
//
//	ptrNoNovo->antNo = NULL;
//	ptrNoNovo->proxNo = ptrLista->inicio;
//
//	ptrNoAtual = ptrLista->inicio;
//
//	// Se a lista não estiver vazia
//	if (ptrLista->inicio != NULL) {
//		ptrNoAtual->antNo = ptrNoNovo;
//	}
//
//	ptrLista->inicio = ptrNoNovo;
//
//	// Incrementa o quantidade de Nós
//	ptrLista->qtdNo++;
//
//	return true;
//}
//
////--------------------------------------------------------
//// INSERIR NO FINAL DA LISTA
////--------------------------------------------------------
//bool inserirListaFim(Lista* ptrLista, int matricula, string nome, float media) {
//	No* ptrNoNovo;
//	No* ptrNoAtual;
//
//	//Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return false;
//	}
//
//	//---------------------------------------------------------------
//	//	Cria o novo nó
//	//---------------------------------------------------------------
//	ptrNoNovo = new No;
//
//	if (ptrNoNovo == NULL) {
//		cout << "Memória insulficiente!" << endl;
//		return false;
//	}
//
//	ptrNoNovo->dados.matricula = matricula;
//	ptrNoNovo->dados.nome = nome;
//	ptrNoNovo->dados.media = media;
//
//	ptrNoNovo->antNo = NULL;
//	ptrNoNovo->proxNo = NULL;
//
//	ptrNoAtual = ptrLista->inicio;
//
//	// Se não houver nenhum nó na lista
//	if (ptrNoAtual == NULL) {
//
//		ptrLista->inicio = ptrNoNovo;
//	}
//	else {
//
//		// Localiza o último nó
//		while (ptrNoAtual->proxNo != NULL) {
//			ptrNoAtual = ptrNoAtual->proxNo;
//		}
//		ptrNoAtual->proxNo = ptrNoNovo;
//		ptrNoNovo->antNo = ptrNoAtual;
//	}
//
//	// Incrementa o quantidade de Nós
//	ptrLista->qtdNo++;
//
//	return true;
//}
//
////--------------------------------------------------------
//// INSERIR EM LISTA ORDENADA
////--------------------------------------------------------
//bool inserirListaOrdenada(Lista* ptrLista, int matricula, string nome, float media) {
//	No* ptrNoNovo;
//	No* ptrNoAnterior;
//	No* ptrNoAtual;
//
//	//---------------------------------------------------------------
//	//	Cria o novo nó
//	//---------------------------------------------------------------
//	ptrNoNovo = new No;
//
//	if (ptrNoNovo == NULL) {
//		cout << "Memória insulficiente!" << endl;
//		return false;
//	}
//
//	ptrNoNovo->dados.matricula = matricula;
//	ptrNoNovo->dados.nome = nome;
//	ptrNoNovo->dados.media = media;
//
//	ptrNoNovo->antNo = NULL;
//	ptrNoNovo->proxNo = NULL;
//
//	//Se a lista estiver vazia
//	if (ptrLista->inicio == NULL) {
//		ptrLista->inicio = ptrNoNovo;
//	}
//	else
//	{
//		ptrNoAnterior = NULL;
//		ptrNoAtual = ptrLista->inicio;
//
//		// Localiza a posição de inserção
//		while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula < matricula) {
//			ptrNoAnterior = ptrNoAtual;
//			ptrNoAtual = ptrNoAtual->proxNo;
//		}
//
//		// Insere no INÍCIO da lista
//		if (ptrNoAtual == ptrLista->inicio) {
//			ptrNoNovo->proxNo = ptrLista->inicio;
//			ptrLista->inicio->antNo = ptrNoNovo;
//			ptrLista->inicio = ptrNoNovo;
//		}
//		else { // Insere no MEIO ou FIM da lista
//
//			ptrNoNovo->proxNo = ptrNoAtual;
//			ptrNoNovo->antNo = ptrNoAnterior;
//
//			ptrNoAnterior->proxNo = ptrNoNovo;
//
//			// Se for o meio da lista
//			if (ptrNoAtual != NULL) {
//				ptrNoAtual->antNo = ptrNoNovo;
//			}
//		}
//	}
//
//	// Incrementa o quantidade de Nós
//	ptrLista->qtdNo++;
//
//	return true;
//}
//
////--------------------------------------------------------
//// REMOVER DO INÍCIO DA LISTA
////--------------------------------------------------------
//bool removerListaInicio(Lista* ptrLista) {
//	No* ptrNoAtual;
//
//	// Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return false;
//	}
//
//
//	// Ajusta o INÍCIO
//	ptrNoAtual = ptrLista->inicio;
//
//	ptrLista->inicio = ptrNoAtual->proxNo;
//
//	// Se houver mais que um nó na lista
//	if (ptrNoAtual->proxNo != NULL) {
//		ptrNoAtual->proxNo->antNo = NULL;
//	}
//
//	// Exclui o primeiro nó
//	delete ptrNoAtual;
//
//	// Decrementa o quantidade de Nós
//	ptrLista->qtdNo--;
//
//	return true;
//}
//
////--------------------------------------------------------
//// REMOVER DO FIM DA LISTA
////--------------------------------------------------------
//bool removerListaFim(Lista* ptrLista) {
//	No* ptrNoAnterior;
//	No* ptrNoAtual;
//
//	// Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return false;
//	}
//
//	ptrNoAnterior = NULL;
//	ptrNoAtual = ptrLista->inicio;
//
//	// Localiza o nó final da lista
//	while (ptrNoAtual->proxNo != NULL) {
//		ptrNoAnterior = ptrNoAtual;
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//
//	// Se for o primeiro nó da lista
//	if (ptrNoAtual == ptrLista->inicio) {
//		ptrLista->inicio = NULL;
//	}
//	else {
//		ptrNoAnterior->proxNo = NULL;
//	}
//
//	// Exclui o primeiro nó
//	delete ptrNoAtual;
//
//	// Decrementa o quantidade de Nós
//	ptrLista->qtdNo--;
//
//	return true;
//}
//
////--------------------------------------------------------
//// REMOVER DO MEIO DA LISTA
////--------------------------------------------------------
//bool removerListaOrdenada(Lista* ptrLista, int matricula) {
//	No* ptrNoAnterior;
//	No* ptrNoAtual;
//
//	// Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return false;
//	}
//
//	ptrNoAnterior = NULL;
//	ptrNoAtual = ptrLista->inicio;
//
//	// Localizao nó que será excluído
//	while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula != matricula) {
//		ptrNoAnterior = ptrNoAtual;
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//	if (ptrNoAtual == NULL) {
//		cout << "A matrícula " << matricula << " não foi encontrada!" << endl;
//		return false;
//	}
//
//	// Se for o primeiro nó da lista
//	if (ptrNoAtual->antNo == NULL) {
//		ptrLista->inicio = ptrNoAtual->proxNo;
//
//		// Se houver mais que um nó na lista
//		if (ptrNoAtual->proxNo != NULL) {
//			ptrNoAtual->proxNo->antNo = NULL;
//		}
//	}
//	else {
//		ptrNoAnterior->proxNo = ptrNoAtual->proxNo;
//
//		// Se houver mais que um nó na lista
//		if (ptrNoAtual->proxNo != NULL) {
//			ptrNoAtual->proxNo->antNo = ptrNoAnterior;
//		}
//	}
//
//	// Exclui o nó atual
//	delete ptrNoAtual;
//
//	// Decrementa o quantidade de Nós
//	ptrLista->qtdNo--;
//
//	return true;
//}
//
////--------------------------------------------------------
//// PESQUISAR MATRÍCULA
////--------------------------------------------------------
//No* pesquisarDado(Lista* ptrLista, int matricula) {
//	No* ptrNoAtual;
//
//	// Se a lista NÃO foi criada
//	if (ptrLista == NULL) {
//		cout << "A lista não está criada!" << endl;
//		return NULL;
//	}
//
//	ptrNoAtual = ptrLista->inicio;
//
//	// Localiza a posição do nó
//	while (ptrNoAtual != NULL && ptrNoAtual->dados.matricula != matricula) {
//		ptrNoAtual = ptrNoAtual->proxNo;
//	}
//
//	if (ptrNoAtual == NULL) {
//		cout << "A matrícula " << matricula << " não foi encontrada!" << endl;
//	}
//
//	return ptrNoAtual;
//}
