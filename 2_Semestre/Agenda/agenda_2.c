#include <stdio.h>
#include <stdlib.h>

#define RETORNA_MENU 0
#define MAX_X 100
#define MAX_NOME 100
#define MAX_TELEFONE 10

int  qtdContatos = 0;
char Contatos_Totais[MAX_X][MAX_NOME];
char Telefones_Totais[MAX_X][MAX_TELEFONE];
//Protótipos das Funções
void MostraMenu       ();
void MostraMenu       ();
void Listagem_Contatos();
void Listagem_Contatos();
void cadastrar        ();
void Remover_Contato  ();
void Buscar_Contato   ();
int main(){
    char **ptrNomes,op='s';
    char **ptrTelefones;
    ptrNomes = &Contatos_Totais;
    ptrTelefones = &Telefones_Totais;
    int opcao;
    while(opcao != 6){
        MostraMenu();
        scanf("%d",&opcao);
        switch(opcao){
        case 1: /*// ADICIONA CONTATO A LISTA.*/
            cadastrar();
            break;
        case 2: /*// REMOVE CONTATO DA LISTA.*/
            Remover_Contato();
            break;
        case 3: /*// FAZ A LISTAGEM DE TODOS OS CONTATOS CADASTRADOS.*/
            Listagem_Contatos();
            break;
        case 4: /*// BUSCA informações INDIVIDUAIS DE UM CONTATO.*/
            Buscar_Contato();
            break;
        /*case 5: // EDITA informações DE UM CONTATO.
            Editar_Contato();
            break;*/
        case 6:
            printf("Saindo Da Agenda . . . !\n\n");
            return 0;
        default:
            printf("Opcao incorreta.\n\n");
        }
    }
}
void MostraMenu(){
    system("cls");
    printf("\n====== AGENDA TELEFONICA ======\n\n");
    printf("\n============ MENU =============\n"  );
    printf("Informe a opcao desejada:\n"          );
    printf("1) Adicionar um contato a  agenda.\n" );
    printf("2) Remover   um contato da agenda.\n" );
    printf("3) Lista de contatos cadastrados da agenda.\n");
    printf("4) Buscar contato na agenda.\n");
    printf("5) Editar contato da agenda.\n");
    printf("6) Sair.\n\n");
    }
void Remover_Contato(){
    char flag='p',nome[20];
    int j,w;
    printf("Digite o nome para remover ");
    fflush(stdin);
    gets(nome);
    for(j=0;j<qtdContatos;j++){
        if(strcmp(nome,Contatos_Totais[j])==0){
            for(w=j;w<qtdContatos;w++){
                strcpy(Contatos_Totais [w],Contatos_Totais [w+1]);
                strcpy(Telefones_Totais[w],Telefones_Totais[w+1]);
                flag='w';
                qtdContatos--;
            }
        }
    }
    if(flag=='p')printf("Contato Inexistente !\n");
    else printf("Contato Removido Com Sucesso !\n");
    system("pause");
}
void cadastrar(){
    char op;
    do{
        printf("\n-- Cadastro de novo contato --\n");
        printf("Nome do contato: ");
        fflush(stdin);
        gets(Contatos_Totais[qtdContatos]);
        printf("Telefone do contato: ");
        fflush(stdin);
        gets(Telefones_Totais[qtdContatos]);
        printf("Contato Cadastrado!\n\n");
        qtdContatos++;
        printf("Quer Cadastra Outro S/N");
        fflush(stdin);
        scanf("%c",&op);
    }while(op!='n');
}
void Listagem_Contatos(){
    int i = 0;
    int j = 0;
    printf("\n======= LISTA DE CONTATOS CADASTRADOS =======\n");
    if(qtdContatos==0)printf("Não Tem Nenhum Cadastro\n");
    for(j=0;j<qtdContatos;++j){
        printf("*** Contato %d ***\n",j+1);
        printf("Nome: ----- %s\n",Contatos_Totais[ j]);
        printf("Telefone: - %s\n",Telefones_Totais[j]);
        printf("\n");
    }
    system("pause");
}
void Buscar_Contato(){
    char nom[20];
    int i,j,flag=0;
    system("cls");
    printf("\n   Digite O Nome ");
    fflush(stdin);
    gets(nom);
    for(i=0;i<qtdContatos;i++){
        if(strcmp(nom,Contatos_Totais[i])==0){
            flag=1;
            printf("Encontrado O Cadastro %d\n",i+1);
            printf("Nome: ----- %s\n",Contatos_Totais[i]);
            printf("Telefone: - %s\n",Telefones_Totais[i]);
            printf("\n");
        }
    }
    if(flag==0)printf("Cadastro Não Encontrado !\n");
    system("pause");
}