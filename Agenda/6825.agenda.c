/*
	Criado em 03/05/2018
	Criado para este tópico:
	https://www.vivaolinux.com.br/topico/C-C++/Ajuda-Simples-com-Struct-e-C-Puro/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 1000 //numero máximo de contatos

typedef enum {
	TELA_SAIR=-1,
	TELA_PRINCIPAL,//0
	TELA_CADASTRAR,//1
	TELA_DESCADASTRAR,//2
	TELA_LISTAR_TODOS,//3
} Telas;


typedef struct
{
	char nome[128];//nome completo
	char telefone[64];//não é um numero
} Contato;

typedef struct
{
	Telas menu;
	int totalContatos;
	Contato contatos[MAX_CONTATOS];
} AgendaTelefonica;

int main (void)
{
	AgendaTelefonica agenda;
	//zera todos os bytes de agenda
	memset(&agenda, 0x0, sizeof(agenda));
	
	//menu da agenda
	agenda.menu = TELA_PRINCIPAL;
	
	//abre o contattos.bin para leitura, contatos.bin deve ser criado caso não exista antes de abrir a agenda
	FILE * memoria = fopen("contatos.bin", "rb");
	if (memoria == NULL)
	{
		printf("Erro ao abrir arquivo de memoria de contatos. \nVocê deve criar o arquivo 'contatos.bin' na primeira execução\n");
		return 1;
	}
	
	//lê todos os contatos
	size_t lidos = fread(agenda.contatos, sizeof(Contato), MAX_CONTATOS, memoria);
	printf("Lidos %zd contatos\n", lidos);
	//faz totalContatos conter a quantidade de contatos lidos
	agenda.totalContatos = (int)lidos;
	fclose(memoria);
	
	
	
	while (agenda.menu != TELA_SAIR)
	{
		switch (agenda.menu)
		{
			case TELA_PRINCIPAL:
				{
					printf("-------------------------------------\n");
					printf("\tAGENDA TELEFONICA:\n");
					printf("-------------------------------------\n");
					int opcao = -1;
					do
					{
						printf("Escolha uma opção:\n");
						printf("\tdigite 1 para cadastrar contato\n");
						printf("\tdigite 2 para remover contato\n");
						printf("\tdigite 3 para listar todos os contatos\n");
						printf("\tdigite 0 para sair do programa\n");
						scanf("%d", &opcao);//pode ria ser de A ao C
						//NOTA: eu sei que este código não é adequado mas é que é dificil encontrar 
						//uma boia soluçlão para o problema de lixo no buffer em C
						//Limpa o buffer para evitar problemas
						int c = 0;
						while ((c = getchar()) != '\n' && c != EOF) { }
					} while (opcao < 0 || opcao > 3);//se for menor que zero é invalido e maior que 3 está fora do intervalo
					
					if (opcao == 0)
						agenda.menu = TELA_SAIR;
					
					if (opcao == 1)
					{
						//vai para tela de cadastrar contato
						agenda.menu = TELA_CADASTRAR;
						//verifica se tem muitos contatos
						if (agenda.totalContatos >= MAX_CONTATOS)
						{
							printf("\tAgenda está lotada, nao é possivel adicionar novoso contatos\n");
							//volta para tela principal
							agenda.menu = TELA_PRINCIPAL;
						}
					}
					
					if (opcao == 2)
					{
						agenda.menu = TELA_DESCADASTRAR;
						//se NÃO tem nenhum contato listado
						if (agenda.totalContatos == 0)
						{
							printf("\tNão há nenhum contato cadastrado para remover\n");
							agenda.menu = TELA_PRINCIPAL;
						}
					}
					
					if (opcao == 3)
					{
						agenda.menu = TELA_LISTAR_TODOS;
						if (agenda.totalContatos == 0)
						{
							printf("\tAgenda não tem nenhum contato para listar\n");
							//volta para tela principal
							agenda.menu = TELA_PRINCIPAL;
						}
					}
				}
				break;
			
			case TELA_CADASTRAR:
				{
					printf("-------------------------------------\n");
					printf("\tTELA DE CADASTRO:\n");
					printf("-------------------------------------\n");
					Contato novo;
					char opcao = 's';
					do
					{
						//zera os bytes de novo
						memset(&novo, 0x0, sizeof(novo));
						printf("Digite um novo nome para o contato: \n");
						//lê uma string da entrada padrão
						fgets(novo.nome, 128, stdin);
						//remove o \n do final
						int id = 0;
						while (novo.nome[id] != '\0' && novo.nome[id] != '\n')
							id++;
						
						novo.nome[id] = '\0';
						
						printf("Digite um novo telefone para o contato:\n");
						//lê o novo telefone da entrada padrão
						fgets(novo.telefone, 64, stdin);
						
						//remove o \n do final
						id = 0;
						while (novo.telefone[id] != '\0' && novo.telefone[id] != '\n')
							id++;
						
						novo.telefone[id] = '\0';
						
						printf("Tem certeza que quer adicionar este contato? [s/n]\n");
						opcao = getchar();
						//Limpa o buffer para evitar problemas
						int c = 0;
						while ((c = getchar()) != '\n' && c != EOF) { }
					} while (opcao == 'n' || opcao == 'N');
					
					//agora adiciona no final o contato
					agenda.contatos[agenda.totalContatos] = novo;
					agenda.totalContatos++;

					//abre contatos.bin para escrita
					memoria = fopen("contatos.bin", "w+b");
					if (memoria == NULL)
					{
						printf("erro ao abrir contatos.bin\n");
						return 0;
					}
					
					//salva os contatos
					size_t salvos = fwrite(agenda.contatos, sizeof(Contato), agenda.totalContatos, memoria);
					if (salvos != (size_t)agenda.totalContatos)
					{
						printf("Erro ao salvar contatos na memoria contatos.bin\n");
						return 1;
					}
					fclose(memoria);
					
					//volta para tela principal
					agenda.menu = TELA_PRINCIPAL;
				}
				break;
			
			case TELA_DESCADASTRAR:
				{
					printf("-------------------------------------\n");
					printf("\tTELA DE DESCADASTRAR:\n");
					printf("-------------------------------------\n");
					int i;
					for (i = 0; i < agenda.totalContatos; i++)
					{
						printf("Contato %d\n", i);
						printf("\tNome: %s\n", agenda.contatos[i].nome);
						printf("\tTelefone: %s\n", agenda.contatos[i].telefone);
						printf("----------------------------------------------------\n");
					}
					
					int indice = -1;
					do
					{
						printf("Digite um indice de contato para descadastrar: de 0 até %d\n", agenda.totalContatos-1);
						scanf("%d", &indice);//póde ocorrer de ficar caracteres no buffer e causar alguns erros
						
						//Limpa o buffer para evitar problemas
						int c = 0;
						while ((c = getchar()) != '\n' && c != EOF) { }
					} while (indice < 0 || indice >= agenda.totalContatos);
					
					//copia todos os contatos da frente do contato de indice e remove indice
					for (i = indice; i < agenda.totalContatos - 1; i++)
						agenda.contatos[i] = agenda.contatos[i + 1];
					
					//remove um contato (o de indice foi removido acima)
					agenda.totalContatos--;
					
					//para salvar os contatos que foram modificados (mesmo código dali da outra tela)
					memoria = fopen("contatos.bin", "w+b");
					if (memoria == NULL)
					{
						printf("erro ao abrir contatos.bin\n");
						return 0;
					}
					
					//salva os contatos
					size_t salvos = fwrite(agenda.contatos, sizeof(Contato), agenda.totalContatos, memoria);
					if (salvos != (size_t)agenda.totalContatos)
					{
						printf("Erro ao salvar contatos na memoria contatos.bin\n");
						return 1;
					}
					fclose(memoria);
					
					//volta para tela principal
					agenda.menu = TELA_PRINCIPAL;
				}
				break;
			
			case TELA_LISTAR_TODOS:
				{
					printf("-------------------------------------\n");
					printf("\tLISTANDO CONTATOS:\n");
					printf("-------------------------------------\n");
					int i;
					for (i = 0; i < agenda.totalContatos; i++)
					{
						printf("Contato %d\n", i);
						printf("\tNome: %s\n", agenda.contatos[i].nome);
						printf("\tTelefone: %s\n", agenda.contatos[i].telefone);
						printf("----------------------------------------------------\n");
					}
					
					//volta para tela principal
					agenda.menu = TELA_PRINCIPAL;
				}
				break;
			
			default:
				agenda.menu = TELA_PRINCIPAL;
				break;
		}
	}
	
	return 0;
}


