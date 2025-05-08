#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Admin {
	char user[20];
	char password[20];
};

struct Admin admin = { "admin", "senha" };


int main(int argc, char *argv[]) {
	
	char usuario[20];
	char senha[20];
	
	int logado = 0;
	int rodando = 1; 
	int op;
	
	do{

			system("cls");
			
			printf("****Bem-Vindo****\n\n");
			printf("Insira seu usuario: ");
			scanf("%s", usuario);
			printf("Insira sua senha: ");
			scanf("%s", senha);
		
			if(strcmp(usuario, admin.user) == 0 && strcmp(senha, admin.password) == 0){
				logado = 1;
			} else{
				printf("Usuario ou senha invalida.");
			}
			
			while(logado == 1 ){
				system("cls");
				
				printf("****Bem-Vindo****\n\n");
				printf("Usuario logado: %s\n\n", admin.user);
			
				printf("O que você quer fazer?\n\n");
		
				printf("[1] Adicionar alunos.\n");
				printf("[2] Remover aluno.\n");
				printf("[3] Atualizar aluno.\n");
				printf("[4] Listar aluno.\n");
				printf("[5] Procurar aluno.\n");
				printf("[6] Deslogar.\n\n");
				printf("[7] Sair do sistema.\n\n");
		
				printf("Digite o numero da opcao desejada: ");
				scanf("%d", &op);
		
				switch(op){
					case 1:
						break;
				
					case 2:
						break;
				
					case 3:
						break;
					
					case 4:
						break;
					
					case 5:
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
		
	
	
	
	return 0;
}
