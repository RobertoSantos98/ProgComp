#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Admin {
	char user[20];
	char password[20];
};

struct Aluno {
	char nome[50];
	int n1;
	int n2;
	int af;
	int notaTotal;
	char situacao[20];
};

struct Admin admin = { "admin", "senha" };

void adicionarAluno(struct Aluno alunos[], int *contadorAlunos);
void listarAlunos(struct Aluno alunos[], int contadorAlunos);
void removerAluno(struct Aluno alunos[], int *contadorAlunos);
void procurarAluno(struct Aluno alunos[], int *contadorAlunos);


int main(int argc, char *argv[]) {
	
	struct Aluno alunos[100];
	int contadorAlunos = 0;
	
	char usuario[20];
	char senha[20];
	
	int logado = 0;
	int rodando = 1; 
	int op;
	
	do{

			system("cls");
			
			printf("**********Bem-Vindo**********\n\n");
			printf("Insira seu usuario: ");
			scanf("%s", usuario);
			printf("Insira sua senha: ");
			scanf("%s", senha);
		
			if(strcmp(usuario, admin.user) == 0 && strcmp(senha, admin.password) == 0){
				logado = 1;
			} else{
				printf("\n\n**********Usuario ou senha invalida.**********\n\n");
				system("pause");
			}
			
			while(logado == 1 ){
				system("cls");
				
				printf("****Bem-Vindo****\n\n");
				printf("Usuario logado: %s\n\n", admin.user);
			
				printf("O que você quer fazer?\n\n");
		
				printf("[1] Adicionar alunos.\n");
				printf("[2] Remover aluno.\n");
				printf("[3] Atualize notas do Aluno [AF].\n");
				printf("[4] Listar aluno.\n");
				printf("[5] Procurar aluno.\n");
				printf("[6] Deslogar.\n\n");
				printf("[7] Sair do sistema.\n\n");
		
				printf("Digite o numero da opcao desejada: ");
				scanf("%d", &op);
		
				switch(op){
					case 1:
						adicionarAluno(alunos, &contadorAlunos);
						break;
				
					case 2:
						removerAluno(alunos, &contadorAlunos);
						break;
				
					case 3:
						break;
					
					case 4:
						listarAlunos(alunos, contadorAlunos);
						break;
					
					case 5:
						procurarAluno(alunos, &contadorAlunos);
						break;
					
					case 6:
						logado = 0;
						break;
					
					case 7:
						logado = 0;
						rodando = 0;
						break;
						
					default:
						printf("Opcao invalida\n");
						break;
				
				}
			}
			
	}while(rodando == 1);
		
	
	printf("\nObrigado por usar o sistema!\n");
	
	return 0;
}


void adicionarAluno(struct Aluno alunos[], int *contadorAlunos){
	system("cls");
	
	if(*contadorAlunos >= 100){
		printf("*****Quantidade maxima de alunos atingida.*****\n\n");
		system("pause");
		return;
	}
	
	int quantidade;
	int i;
	
	printf("Quantos alunos voce deseja adicionar no momento? => ");
	scanf("%d", &quantidade);
	
	for( i = *contadorAlunos ; i < *contadorAlunos + quantidade ; i++ ){
		system("cls");
		
		printf("Digite o nome do Aluno %d:", i);
		scanf("%s", alunos[i].nome);
		
		printf("Digite a nota 1 do Aluno %d: ", i);
		scanf("%d", &alunos[i].n1);
		
		printf("Digite a nota 2 do Aluno %d: ", i);
		scanf("%d", &alunos[i].n2);
		
		alunos[i].notaTotal = alunos[i].n1 + alunos[i].n2;
		
		if(alunos[i].notaTotal <= 5){
			strcpy(alunos[i].situacao, "AF");
		} else{
			
			strcpy(alunos[i].situacao, "APROVADO");
		}
		
	}
	
	*contadorAlunos += quantidade;
	
	system("cls");
	printf("+++++Alunos Adicionados+++++\n\n");
	system("pause");
}

void listarAlunos(struct Aluno alunos[],int contadorAlunos){
	system("cls");
	
	int opListar;
	int i;
	
	printf("Quais Alunos deseja Listar?\n\n");
	printf("[1]Todos\n");
	printf("[2]Apenas aprovados\n");
	printf("[3]Apenas de AF\n\n");
	
	printf("Digite o numero desejado: ");
	scanf("%d", &opListar);
	
	switch(opListar){
		case 1:
			system("cls");
			
			printf("%d/100\n\n", contadorAlunos);
			
			for( i = 0 ; i < contadorAlunos ; i++ ){
				printf("*****************************************************\n");
				printf("Aluno %d\n\n", i);
		
				printf("Nome: %s\n", alunos[i].nome);
				printf("Nota 1: %d\n", alunos[i].n1);
				printf("Nota 2: %d\n", alunos[i].n2);
				printf("Situacao: %s\n\n", alunos[i].situacao);
			}
	
			system("pause");
			break;
		
		case 2:
			system("cls");
			for( i = 0 ; i < contadorAlunos ; i++ ){
				
				if(strcmp(alunos[i].situacao, "APROVADO") == 0){
					printf("*****************************************************\n");
					printf("Aluno %d\n\n", i);
		
					printf("Nome: %s\n", alunos[i].nome);
					printf("Nota 1: %d\n", alunos[i].n1);
					printf("Nota 2: %d\n", alunos[i].n2);
					printf("Situacao: %s\n\n", alunos[i].situacao);
				}	
			}
			system("pause");
			break;
		
		case 3:
			system("cls");
			for( i = 0 ; i < contadorAlunos ; i++ ){
				
				if(strcmp(alunos[i].situacao, "AF") == 0){
					printf("*****************************************************\n");
					printf("Aluno %d\n\n", i);
		
					printf("Nome: %s\n", alunos[i].nome);
					printf("Nota 1: %d\n", alunos[i].n1);
					printf("Nota 2: %d\n", alunos[i].n2);
					printf("Situacao: %s\n\n", alunos[i].situacao);
				}	
			}
			system("pause");
			break;
			
		default:
			break;
		
		
	}
	
}

void removerAluno(struct Aluno alunos[], int *contadorAlunos){
	system("cls");
	
	char alunoExcluir[50];
	int encontrado = 0;
	
	printf("Digite o nome do Aluno cujo a intencao seja excluir: ");
	scanf("%s", alunoExcluir);
	
	int i;
	for( i = 0 ; i < *contadorAlunos ; i++ ){
		
		if(strcmp(alunoExcluir, alunos[i].nome) == 0){
			
			encontrado = 1;
			int j;
			for( j = i ; j < *contadorAlunos - 1 ; j++){
				alunos[j] = alunos[j + 1];
			}
			
			*contadorAlunos -= 1;
			
			printf("*****Aluno Removido com sucesso*****\n");
			system("pause");
		}
	}
	
	if(encontrado == 0){
		printf("*****Aluno não encontrado*****\n\n");
		system("pause");
	}
}

void procurarAluno(struct Aluno alunos[], int *contadorAlunos){
	system("cls");
	
	char encontrarAluno[50];
	
	printf("Digite o nome do Aluno que queira encontrar: ");
	scanf("%s", encontrarAluno);
	
	int i;
	for(i = 0 ; i < *contadorAlunos ; i++){
		
		if(strcmp(alunos[i].nome, encontrarAluno) == 0){
			printf("Nome: %s\n", alunos[i].nome);
			printf("Nota 1: %d\n", alunos[i].n1);
			printf("Nota 2: %d\n\n", alunos[i].n2);
			printf("Situacao: %s\n", alunos[i].situacao);
			
			system("pause");
			
		}	
	}
}


