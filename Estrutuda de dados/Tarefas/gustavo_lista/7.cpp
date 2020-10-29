#include <iostream>
#include <locale.h> 
#include <stdlib.h> 
#include <string>

using namespace std;

// Veiculo sobre o ALUNO
struct Veiculo {
	string modeloVeiculo;
	int anoFabricacao;
	int quilometragem;
    float valorVenda;
};

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
    cout << "***VEÍCULO***";
    cout << "Modelo do veículo: " << (*veiculo).modeloVeiculo << "\n";
    cout << "Ano de Fabricação do veículo: " << (*veiculo).anoFabricacao << "\n";
    cout << "Quilometragem do veículo: " << (*veiculo).quilometragem << "\n";
    cout << "Valor de venda do veículo: " << (*veiculo).valorVenda << "\n";
}

int main() {
	setlocale(LC_ALL, "Portuguese");
    
    Veiculo *veiculo1;
    veiculo1 = new Veiculo;

    inserirDados(veiculo1);
    alterarDados(veiculo1);
    
    system("clear");
    exibirDados(veiculo1);
	


	return 0;
}