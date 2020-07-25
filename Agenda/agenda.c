// Por Janderson Barbosa Gonçalves Aluno da Fatec Ribeirão Preto

// Como o programa foi feito em ambiente Linux, segue link de compilador online com base no linux
// https://repl.it/languages/c

// Site de referência para estudo 
//https://www.cprogressivo.net/2013/10/A-funcao-realloc-realocando-memoria-dinamicamente-e-a-calloc.html

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <unistd.h> // Biblioteca usada neste projeto para a função sleep()
#include<locale.h>//Biblioteca usada neste projeto para aparecer caracteres especiais da lingua Portuguesa
#define MAX 100
//----------Estrutura de Dados---------
struct Pessoa{
    char* nome;
    int idade;
    char telefone[17];
    char* endereco;
    int numero;
    char* cidade;
    char estado[2];
}pessoa[MAX];

//----------Funções--------------------
void exibirMenu(){
    setlocale(LC_ALL,"Portuguese");//Para aparecer caracteres especiais da lingua Portuguesa conforme biblioteca locale.h
    printf("\n\tSelecione umas das opções a seguir:\n");
    printf("\t01 - Inserir contato\n"
           "\t02 - Listar contatos\n"
           "\t03 - Pesquisar contato\n"
           "\t04 - Alterar contato\n"
           "\t05 - Excluir contato\n"
           "\t99 - Sair\n\n");
}

char* alocarMemoria(int tamanho){
    char* info = NULL;
    info = (char*) malloc(sizeof(tamanho) * sizeof(char));

    if(info == NULL){
        printf("ERRO: impossível alocar a quantidade de memória requisitada!");
        exit(1);
    }
    return info;
}

void cadastrarContato(int registro){
    setlocale(LC_ALL,"Portuguese");//Para aparecer caracteres especiais da lingua Portuguesa conforme biblioteca locale.h
    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);/* setbuf Limpa Buffer da memoria de entrada padrão*/
    //Alocação e cópia de dados
    pessoa[registro].nome = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].nome, dados);

    printf("\t\tIdade: ");
    scanf("%d", &pessoa[registro].idade);
    setbuf(stdin, NULL);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", pessoa[registro].telefone);
    setbuf(stdin, NULL);

    printf("\t\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].endereco = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].endereco, dados);
    
    printf("\t\tNumero: ");
    scanf("%d", &pessoa[registro].numero);
    setbuf(stdin, NULL);

    printf("\t\tCidade: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    pessoa[registro].cidade = alocarMemoria(strlen(dados));
    strcpy(pessoa[registro].cidade, dados);

    printf("\t\tEstado: ");
    scanf("%[^\n]s", pessoa[registro].estado);
    setbuf(stdin, NULL);
}

void listarContatos(int qtdeContatos){
    int i;
    int contagem = 1;
    for(i = 0; i < qtdeContatos; i++){
        printf("\n\tContato nº: %d\n", contagem++);
        printf("\tNome: %s\n", pessoa[i].nome);
        printf("\tIdade: %d\n", pessoa[i].idade);
        printf("\tTelefone: %s\n", pessoa[i].telefone);
        printf("\tEndereço: %s\n", pessoa[i].endereco);
        printf("\tNumero: %d\n", pessoa[i].numero);
        printf("\tCidade: %s-%s\n", pessoa[i].cidade, pessoa[i].estado);
    }
    sleep(3);
    printf("\n\n");
}

void exibirContato(int indice){
    setlocale(LC_ALL,"Portuguese");//Para aparecer caracteres especiais da lingua Portuguesa conforme biblioteca locale.h
    printf("\n\tNome: %s\n", pessoa[indice].nome);
    printf("\tIdade: %d\n", pessoa[indice].idade);
    printf("\tTelefone: %s\n", pessoa[indice].telefone);
    printf("\tEndereço: %s\n", pessoa[indice].endereco);
    printf("\tNumero: %d\n", pessoa[indice].numero);
    printf("\tCidade: %s-%s\n\n", pessoa[indice].cidade, pessoa[indice].estado);
}

int pesquisarContato(int qtdeContatos, char* nomeBuscado){
    int i;

    for(i = 0; i < qtdeContatos; i++){
        if(strcmp(nomeBuscado, pessoa[i].nome) == 0)
            return i;
    }
    return -1;
}

void deletarContato(int registro)/*Falhou*/{
    
    char *nomeBuscado;
    char flag='p';
    int j,w;
    printf("Digite o nome para remover:\n");
    scanf("%[^\n]s",nomeBuscado);
    setbuf(stdin, NULL);
    for(j=0;j<=registro;j++){
            if(strcmp(nomeBuscado,pessoa[j].nome)==0){
                for(w=j;w<=registro;w++){
                    strcpy(pessoa[w].nome, pessoa[w+1].nome);
                    pessoa[w].idade =pessoa[w+1].idade;
                    strcpy(pessoa[w].endereco, pessoa[w+1].endereco);
                    strcpy(pessoa[w].telefone,pessoa[w+1].telefone);
                    strcpy(pessoa[w].cidade, pessoa[w+1].cidade);
                    strcpy(pessoa[w].estado, pessoa[w+1].estado);
                    flag='w';
                    registro--;
                }
            }
        }

    if(flag=='p')
            printf("Contato Inexistente !\n");
        else 
            printf("Contato Removido Com Sucesso !\n");
        
   sleep(3);

}

void atualizarContato(int indice){
    setlocale(LC_ALL,"Portuguese");//Para aparecer caracteres especiais da lingua Portuguesa conforme biblioteca locale.h
    char* nome;
    int idade;
    char fone[17];
    char* endereco;
    int numero;
    char* cidade;
    char uf[2];

    char dados[MAX];
    printf("\n\t\tNome: ");
    scanf("%[^\n]s",dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    nome = alocarMemoria(strlen(dados));
    strcpy(nome, dados);

    printf("\t\tIdade: ");
    scanf("%d", &idade);
    setbuf(stdin, NULL);

    printf("\t\tTelefone: ");
    scanf("%[^\n]s", fone);
    setbuf(stdin, NULL);

    printf("\t\tEndereço: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    endereco = alocarMemoria(strlen(dados));
    strcpy(endereco, dados);

    printf("\t\tNumero: ");
    scanf("%d", &numero);
    setbuf(stdin, NULL);

    printf("\t\tCidade: ");
    scanf("%[^\n]s", dados);
    setbuf(stdin, NULL);
    //Alocação e cópia de dados
    cidade = alocarMemoria(strlen(dados));
    strcpy(cidade, dados);

    printf("\t\tEstado: ");
    scanf("%[^\n]s", uf);
    setbuf(stdin, NULL);

    pessoa[indice].nome = nome;
    pessoa[indice].idade = idade;
    strcpy(pessoa[indice].telefone, fone);
    pessoa[indice].endereco = endereco;
    pessoa[indice].numero = numero;
    pessoa[indice].cidade = cidade;
    strcpy(pessoa[indice].estado, uf);
}

int leitor()/*Função para leitura da opção no switch case na função main*/{
    int opcao;

    printf("\n\tOpção escolhida: ");
    scanf("%d", &opcao);
    setbuf(stdin, NULL);

    return opcao;
}

//---------Função Main-------------------
int main(){
    setlocale(LC_ALL,"Portuguese");//Para aparecer caracteres especiais da lingua Portuguesa conforme biblioteca locale.h
    char nome[MAX];
    int numeroRegistro = 0;
    int opcaoEscolhida;
    int indice;

    do{ 
        system("clear");
        exibirMenu();
        opcaoEscolhida = leitor();

        switch(opcaoEscolhida){
            case 1:
                cadastrarContato(numeroRegistro++);
                break;
            case 2:
                listarContatos(numeroRegistro);
                break;
            case 3:
                printf("\n\tDigite o Nome Cadastrado: ");
                scanf("%[^\n]s", nome);
                indice = pesquisarContato(numeroRegistro, nome);

                if(indice >= 0 && indice <= 99)
                {
                    exibirContato(indice);
                    sleep(3);
                }
                else
                    printf("\n\tContato não cadastrado!");
                break;
            case 4:
                printf("\n\tContato número [1 - 99]: ");
                scanf("%d", &indice);
                indice -= 1;
                if(indice >= 0 && indice <= 99)
                    atualizarContato(indice);
                else
                    printf("\n\tContato inválido!");
                break;
            case 5:
               deletarContato(numeroRegistro);
            break;
            case 99:
                printf("\n\tSaindo...");
                break;
            default:
                printf("Opção inválida!");
                exibirMenu();
                opcaoEscolhida = leitor();
     }

    }while(opcaoEscolhida != 99);
}