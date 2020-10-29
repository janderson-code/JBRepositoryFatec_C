// Por Janderson Barbosa Gonçalves , Aluno da Fatec Ribeirão Preto
// Como o programa foi feito em ambiente Linux, segue link de compilador online com base no linux
// https://repl.it/languages/c
// No caso a diferença na hora da compilação esta na função Limpar tela. Dentro da função tem instruções

#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <unistd.h>// função sleep()
#include <stdio.h>
#include <iomanip> // casas decimais
#include <string.h>
#include <string>

using namespace std;


// Estrutura 
struct Veiculo {
	string modeloVeiculo;
	int anoFabricacao;
	int quilometragem;
    float valorVenda;
};

// Protótipos
void Menu();
void LimparTela();
void inserirDados(Veiculo *veiculo);
void alterarDados(Veiculo *veiculo);
void exibirDados(Veiculo *veiculo);


int main()
{   
    setlocale(LC_ALL,"Portuguese");
    cout << fixed <<setprecision(2);



    Menu();
    sleep(3);
    
    return 0;
}

void inserirDados(Veiculo *veiculo) {
    cout << "Digite o modelo do véiculo: ";
    cin >> (*veiculo).modeloVeiculo;
    cout << "Digite o ano de fabricação: ";
    cin >> (*veiculo).anoFabricacao;
    cout << "Digite a quilometragem: ";
    cin >> (*veiculo).quilometragem;
    cout << "Digite o valor de venda: ";
    cin >> (*veiculo).valorVenda;

}

void alterarDados(Veiculo *veiculo) {
    cout << "Digite o novo valor de quilometragem: ";
    cin >> (*veiculo).quilometragem;
    cout << "Digite o novo valor de venda: ";
    cin >> (*veiculo).valorVenda;
}

void exibirDados(Veiculo *veiculo) {
    cout << "---VEÍCULO---\n\n";
    cout << "Modelo do veículo: " << (*veiculo).modeloVeiculo << "\n";
    cout << "Ano de Fabricação do veículo: " << (*veiculo).anoFabricacao << "\n";
    cout << "Quilometragem do veículo: " << (*veiculo).quilometragem << "\n";
    cout << "Valor de venda do veículo: " << (*veiculo).valorVenda << "\n";
}

// Função para exibir Menu de opções
void Menu(){

    int op;

    Veiculo *veiculo1;
    veiculo1 = new Veiculo;


    inicio:


    LimparTela();
    cout << "-----------------------------------------------------------------------------------------\n\n";
    cout << "\t***PROGRAMA PARA CADASTRO DE VEICULOS***" << endl;
    cout << "-----------------------------------------------------------------------------------------\n\n";
    cout << "Digite sua opção"<< endl;
    cout <<"\n\n 1 - Inserir Veículos\n\n 2 - Alterar Quilometragem e Venda\n\n 3- Exibir Veículos\n\n 4- Sair\n" << endl;
    cin >> op;

    switch (op)
    {
        case 1:
            LimparTela();
            inserirDados(veiculo1);
            goto inicio;
            break;
        case 2:
            LimparTela();
            alterarDados(veiculo1);
            goto inicio;
            break;

        case 3:
            LimparTela();
            exibirDados(veiculo1);
            sleep(4);
            goto inicio;
            break;

        case 4:
            LimparTela();
            cout << "Você pediu para Sair , Fechando o programa....\n" << endl;
            sleep(3);
            exit(0);
            break;

        default:
            LimparTela();
            cout << "voce deve escolher uma opção valida...Voltando a tela inicial..\n"<< endl;
            sleep(4);
            goto inicio;
            break;
    }








}

// Função para Limpar tela
void LimparTela(){

    system("clear");

     //Descomente o de baixo caso esteja usando Windows e comente o de cima
//  system("cls");

}