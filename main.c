#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Admin {
	char user[20];
	char password[20];
};

struct Aluno {
	int rgm;
	char nome[50];
	int n1;
	int n2;
	int af;
	int notaTotal;
	char situacao[20];
};

void adicionarAluno(struct Aluno alunos[], int *contadorAlunos);
void listarAlunos(struct Aluno alunos[], int contadorAlunos);
void removerAluno(struct Aluno alunos[], int *contadorAlunos);
void procurarAluno(struct Aluno alunos[], int *contadorAlunos);
void atualizarNota(struct Aluno alunos[], int contadorAlunos);
void exportarArquivo(struct Aluno alunos[], FILE *arquivo);
void editarAcesso(struct Admin *admin);
void cabecalho();
void carregando();


int main(int argc, char *argv[]) {
	
	struct Admin admin = { "admin", "senha" };
	
	FILE *arquivo;
	struct Aluno alunos[100];
	int contadorAlunos = 0;
	
	char usuario[20];
	char senha[20];
	
	int logado = 0;
	int rodando = 1; 
	int op;
	
	do{
			system("cls");
			cabecalho();
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
				
				cabecalho();
				printf("****Bem-Vindo****\n");
				printf("Usuario logado: %s\n\n", admin.user);
			
				printf("O que voce quer fazer?\n\n");
		
				printf("[1] Adicionar alunos.\n");
				printf("[2] Remover aluno.\n");
				printf("[3] Adicionar nota AF do Aluno.\n");
				printf("[4] Listar aluno.\n");
				printf("[5] Procurar aluno.\n");
				printf("[6] Exportar arquivo para .txt.\n\n");
				printf("[7] Sair do sistema.\n");
				printf("[8] Editar Credenciais.\n");
				printf("[9] Deslogar.\n\n");
		
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
						atualizarNota(alunos, contadorAlunos);
						break;
					
					case 4:
						listarAlunos(alunos, contadorAlunos);
						break;
					
					case 5:
						procurarAluno(alunos, &contadorAlunos);
						break;
					
					case 6:
						exportarArquivo(alunos, arquivo);
						break;
					
					case 7:
						logado = 0;
						rodando = 0;
						break;
						
					case 8:
						editarAcesso(&admin);
						break;
						
					case 9:
						logado = 0;
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
	
	printf("Digite quantos alunos voce deseja adicionar no momento => ");
	scanf("%d", &quantidade);
	
	
	for( i = *contadorAlunos ; i < *contadorAlunos + quantidade ; i++ ){
		system("cls");
		
		do {
    		printf("Digite o RGM do Aluno %d: ", i);
    		scanf("%d", &alunos[i].rgm);
    		while (getchar() != '\n');

    		if(alunos[i].rgm > 99999999){
        		printf("O RGM deve ter no máximo 8 dígitos.\n");
        		system("pause");
        		system("cls");
    		}
		} while(alunos[i].rgm > 99999999);

		
		printf("\nDigite o NOME do Aluno %d:", i);
		scanf(" %[^\n]", alunos[i].nome);
		
		do{
			system("cls");
			printf("Digite a nota 1 do Aluno %d: ", i);
			scanf("%d", &alunos[i].n1);
			
		}while(alunos[i].n1 < 0 || alunos[i].n1 > 5);
		
		do{
			system("cls");
			printf("Digite a nota 2 do Aluno %d: ", i);
			scanf("%d", &alunos[i].n2);
				
		}while(alunos[i].n2 < 0 || alunos[i].n2 > 5);

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
			carregando();
			system("cls");
			
			printf("%d/100\n\n", contadorAlunos);
			
			for( i = 0 ; i < contadorAlunos ; i++ ){
				printf("*****************************************************\n");
				printf("Aluno %d\n\n", i);
		
				printf("RGM: %d\n", alunos[i].rgm);
				printf("Nome: %s\n", alunos[i].nome);
				printf("Nota 1: %d\n", alunos[i].n1);
				printf("Nota 2: %d\n", alunos[i].n2);
				printf("Nota Final: %d\n", alunos[i].notaTotal);
				printf("Situacao: %s\n\n", alunos[i].situacao);
			}
	
			system("pause");
			break;
		
		case 2:
			carregando();
			system("cls");
			printf("Carregando Dados...");
			sleep(3);
			system("cls");
			
			for( i = 0 ; i < contadorAlunos ; i++ ){
				
				if(strcmp(alunos[i].situacao, "APROVADO") == 0){
					printf("*****************************************************\n");
					printf("Aluno %d\n\n", i);
		
					printf("Nome: %s\n", alunos[i].nome);
					printf("RGM: %d\n", alunos[i].rgm);
					printf("Nota 1: %d\n", alunos[i].n1);
					printf("Nota 2: %d\n", alunos[i].n2);
					printf("Nota Final: %d\n", alunos[i].notaTotal);
					printf("Situacao: %s\n\n", alunos[i].situacao);
				}	
			}
			system("pause");
			break;
		
		case 3:
			carregando();
			
			system("cls");
			printf("Carregando Dados...");
			sleep(3);
			system("cls");
			
			for( i = 0 ; i < contadorAlunos ; i++ ){
				
				if(strcmp(alunos[i].situacao, "AF") == 0){
					printf("*****************************************************\n");
					printf("Aluno %d\n\n", i);
		
					printf("Nome: %s\n", alunos[i].nome);
					printf("RGM: %d\n", alunos[i].rgm);
					printf("Nota 1: %d\n", alunos[i].n1);
					printf("Nota 2: %d\n", alunos[i].n2);
					printf("Nota Final: %d\n", alunos[i].notaTotal);
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
	
	printf("Digite o nome do Aluno cujo a intencao seja excluir ou Digite 'voltar' para retornar ao MENU: ");
	scanf("%s", alunoExcluir);
	
	if(strcmp(alunoExcluir, "voltar") == 0){
		return;
	}
	
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

void atualizarNota(struct Aluno alunos[], int contadorAlunos){
	system("cls");
	
	char atualizarAluno[50];
	int encontrado = 0;
	
	printf("\n\nDigite o nome do Aluno para Adicionar nota AF: ");
	scanf("%s", atualizarAluno);
	
	int i;
	for(i = 0 ; i < contadorAlunos ; i++){
		
		if(strcmp(alunos[i].nome, atualizarAluno) ==0){
			encontrado = 1;
		    int notaAf;
		    
		    system("cls");
		    printf("Digite a nota AF de %s: ", alunos[i].nome);
		    scanf("%d", &notaAf);
		    
		    if(alunos[i].n1 >= alunos[i].n2){
		    	system("cls");
		    	printf("A nota A2 foi alterada pois era a menor.\n\n");
		    	alunos[i].n2 = notaAf;	
		    	system("pause");
		    	
			} else{
				system("cls");
		    	printf("A nota A1 foi alterada pois era a menor.\n\n");
				alunos[i].n1 = notaAf;
				system("pause");
			}
			
			alunos[i].notaTotal = alunos[i].n1 + alunos[i].n2;
			
			if(alunos[i].notaTotal <= 5){
				system("cls");
				printf("Aluno Nao alcancou a nota esperada e por isso foi REPROVADO.\n\n");
				strcpy(alunos[i].situacao, "REPROVADO");
				system("pause");
				
			} else{
				system("cls");
				printf("Aluno Aprovado por AF.\n\n");
				strcpy(alunos[i].situacao, "APROVADO");
				system("pause");
				
			}
		    
		    break;
		    
		}
		
	}
	
	if(encontrado ==0){
		printf("*****Aluno não encontrado*****\n\n");
		system("pause");
	}
	
}

void exportarArquivo(struct Aluno alunos[], FILE *arquivo){
	carregando();
	system("cls");
	
	arquivo = fopen("AlunosBrazCubas.txt", "w");
	
	if(arquivo == NULL){
		system("cls");
		printf("Erro ao abrir Arquivo!\n\n");
		system("pause");
		return;
	}
	
	int i;
	for ( i = 0; i < 100; i++) {
		if (strlen(alunos[i].nome) > 0) {
			fprintf(arquivo, "Aluno %d\n", i);
			fprintf(arquivo, "Nome: %s\n", alunos[i].nome);
			fprintf(arquivo, "RGM: %d\n", alunos[i].rgm);
			fprintf(arquivo, "Nota 1: %d\n", alunos[i].n1);
			fprintf(arquivo, "Nota 2: %d\n", alunos[i].n2);
			fprintf(arquivo, "Nota Total: %d\n", alunos[i].notaTotal);
			fprintf(arquivo, "Situacao: %s\n\n", alunos[i].situacao);
			fprintf(arquivo, "************************************************");
		}
	}
	
	fclose(arquivo);
	
	printf("Arquivo Exportado com sucesso!\n\n");
	system("pause");
	
}

void editarAcesso(struct Admin *admin){
	system("cls");
	
	char senhaAtual[50];
	
	printf("Digite a senha atual: ");
	scanf("%s", senhaAtual);
	
	if(strcmp(senhaAtual, admin->password) == 0 ){
		system("cls");
		
		printf("Digite o novo usuario: ");
		scanf("%s", admin->user);
		
		printf("Digite a nova senha: ");
		scanf("%s", admin->password);
		
		system("cls");
		printf("***Credenciais alteradas com sucesso***\n\n");
		system("pause");
	} else{
		printf("A senha está incorreta\n\n");
		system("pause");
	}
}



void cabecalho(){
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("+++++                 BRAZ CUBAS EDUCACAO                     +++++\n");
	printf("+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n\n\n");
}

void carregando(){

system("cls");
printf("Carregando...\n");
printf("||||||||||||||||");
Sleep(1500);
printf("||||||||||||||||||||");
Sleep(900);
printf("||||||||");
Sleep(2000);
printf("||||||||||||||||||||");
Sleep(500);
printf("||||||||");
Sleep(400);
}


