#include <iostream> // funções cout e cin
#include <locale.h> // Idioma Portugues
#include <stdlib.h>
#include <string>
#include <stdio.h>
#include <iomanip>// casas decimais

using namespace std;

/*Estrutura*/
struct CadastroVeiculo{
    string modelo;
    int ano;
    int numero_portas;
};
/*Prototipos*/

int main()
{
    setlocale(LC_ALL,"portuguese");
    cout << fixed << setprecision(2); 


    return 0;
}
void exibirDados(CadastroVeiculo veiculo){
     cout << "Modelo: " << veiculo.modelo << endl;
     cout << "Ano: " << veiculo.ano << endl;
     cout << "Numero de portas: " << veiculo.numero_portas << endl;


}
CadastroVeiculo InserirDados(){
    
    CadastroVeiculo veiculo;
    cout << "Modelo"<< endl;
    getline(cin,veiculo.modelo);

    cout << "Ano" << endl;
    cin >> veiculo.ano;

    cout << "Qtd Portas" << endl;
    cin >> veiculo.numero_portas;


}