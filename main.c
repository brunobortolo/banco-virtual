// Programa que simula o investimento em um banco virtual 
// Com funcionalidade de consultar o extrato e fazer tranferência de valores 

#include <stdio.h>
#include <string.h>
// Definindo o número máximo de Cadastro de Usuários para o programa encerrar
#define MAX_USUARIOS 100

    typedef struct {
        char nome [100];
    	int data_nascimento;
    } Usuario;
    
    int main() {
    
    int tecla_saida = 9999;
    Usuario usuarios[MAX_USUARIOS]; // Array para armazenar informações do usuário
    int n_usuarios = 0; // Contador do número de usuarios
	char escolha;
	float saldo;

    while (1) {
        printf("-----------------------------\n");
        printf("| Ola bem vindo ao Banco C! |\n");
        printf("-----------------------------\n\n\n\n");
        
    	printf("Aqui esta as listas de operacoes disponiveis no nosso banco: \n\n");
    	printf("1- Para Cadastro de Usuario\n");
    	printf("2- Para Consulta de Saldo\n");
    	printf("3- Para Consulta de Extrato\n");
    	printf("4- Para Tranferências\n");
    	printf("5- Para Investimento\n");
    	printf("Para sair do aplicativo digite '5414' \n\n");	
    	scanf(" %c", &escolha);
    	
        	switch (escolha) {
        		case '1':
            		if (n_usuarios < MAX_USUARIOS) {
            		    printf("Nome completo: ");
                		scanf(" %[^\n]", usuarios[n_usuarios].nome);
                		printf("Data de nascimento (formato DD/MM/AA): ");
                		scanf("%d", &usuarios[n_usuarios].data_nascimento);
                		
                		n_usuarios++;
                		
                		printf("Insira o valor do deposito: R$");
                		scanf("%f", &saldo);
                		printf("\nCadastro realizado com sucesso!\n\n");
                		printf("**  Confira suas informacoes: **\n");
                		printf("** -> Nome: %s  **\n", usuarios[n_usuarios - 1].nome); // Lendo o valor armazendo nessa string
                		printf("** -> Data de Nascimento: %d  **\n", usuarios[n_usuarios - 1].data_nascimento);
                		printf("** -> Valor depositado: %.2f **\n", saldo);
                		} else {
            		    printf("Cadastro nao realizado!\n");
            		    printf("Motivo: Banco de dados lotado no momento =c\n\n");
            		}
            		break;
            		
            	case '2': 
            	
                printf("Qual seu nome?");
                scanf(" %[^\n]", usuarios[n_usuarios].nome);
                printf("O saldo disponivel é: R$%.2f", saldo);
        	}
    }
	
	return 0;
}
