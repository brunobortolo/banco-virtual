// Programa que simula o investimento em um banco virtual 
// Com funcionalidade de consultar o extrato e fazer tranferência de valores 

#include <stdio.h>
#include <string.h>
#include <locale.h>
// Definindo o número máximo de Cadastro de Usuários para o programa encerrar
#define MAX_USUARIOS 100
#define MAX_SENHAS 10

    typedef struct {
        char nome [100];
    	char data_nascimento[10];
		char senha[10];
    } Usuario;
    
    int main() {
    
    int tecla_saida = 9999;
    Usuario usuarios[MAX_USUARIOS]; // Array para armazenar informações do usuário
    int n_usuarios = 0; // Contador do número de usuarios
	char escolha;
	float saldo, valor_transferencia, novo_saldo, valor_aplicado;
	char escolha2;
	char continuar;
    

	printf("\n\n-----------------------------\n");
        printf("| Ola bem vindo ao Banco C! |\n");
        printf("-----------------------------\n\n\n\n");
		printf("Aqui esta as listas de operacoes disponiveis no nosso banco: \n");

    while (1) {  
    	printf("1- Para Cadastro de Usuario\n");
    	printf("2- Para Consulta de Saldo\n");
    	printf("3- Para Tranferências\n");
    	printf("4- Para Investimento\n");
    	printf("5- Para Sair \n\n");	
    	scanf(" %c", &escolha);
    	
        	switch (escolha) {
        		case '1':
            		if (n_usuarios < MAX_USUARIOS) {
            		    printf("Nome completo: ");
                		scanf(" %[^\n]", usuarios[n_usuarios].nome);
                		printf("Data de nascimento (formato DD/MM/AAAA): ");
                		scanf("%s", usuarios[n_usuarios].data_nascimento);
                		
                		n_usuarios++;
                		
                		printf("Insira o valor do deposito: R$");
                		scanf("%f", &saldo);
                		printf("\nCadastro realizado com sucesso!\n\n");
						printf("+--------------------------------------+\n");
                		printf("**  Confira suas informacoes:   \n");
                		printf("** -> Nome: %s    \n", usuarios[n_usuarios - 1].nome); // Lendo o valor armazendo nessa string
                		printf("** -> Data de Nascimento: %s    \n", usuarios[n_usuarios - 1].data_nascimento);
                		printf("** -> Valor depositado: R$%.2f   \n", saldo);
						printf("+--------------------------------------+\n\n");
                        
                        printf("Deseja continuar?\n");
						printf("1 - Sim / 2 - Não\n");
						scanf("%s", &continuar);
						printf("\n");
						switch (continuar){
							case '1':
							printf("Continue com as seguites opções:\n");
							break;

							case '2':
							printf("Obrigado Por usar nosso banco!");
							return 0;

							default:
							return 0;


						}
                        
                	} else {
            		    printf("Cadastro nao realizado!\n");
            		    printf("Motivo: Banco de dados lotado no momento =c\n\n");
            		}
            		break;
            		
            	case '2': 
            	
                    printf("Qual seu nome?\n");
                    scanf(" %[^\n]", usuarios[n_usuarios].nome);
                    printf("\nSaldo disponivel: R$%.2f \n", saldo);
					printf("\n \n");
                    break;

                case '3': 
                    printf("**** TRANSFERENCIA ****\n");
					printf("Qual o valor que voce gostaria de tranferir?\n");
					 printf("R$");
					 scanf("%f", &valor_transferencia);
                    if (valor_transferencia <= saldo) {
                        printf("Para qual usuário voce gostaria de transferir?\n");
                        scanf(" %s", usuarios[n_usuarios].nome);
                        printf("Transferecia concluida!\n");
						saldo = saldo - valor_transferencia;
                        printf("Seu saldo agora é de: %.2f\n", saldo);
                    } else {
                        printf("Saldo indisponivel para concluir a tranferencia!\n");
                    }
                    break;

					case '4':
					printf("**** INVESTIMENTO ****\n");
					printf("Escolha um tipo de investimento: \n");
					printf("1- Poupança \n");
					printf("2- Criptomoedas \n");
					printf("3- Moedas internacionais \n");
					scanf(" %c", &escolha2);

						switch (escolha2) {
							case '1': 
							printf("Insira o valor de aplicacao na poupanca\n");	
							printf("R$:"); scanf("%f", &valor_aplicado);
								if (valor_aplicado <= saldo) {
									float rentabilidade;
									rentabilidade = 0.4;
									printf("A rentabilidade da poupança por mes = %.2f %%\n", rentabilidade);
								}
							break;

							case '2':
							printf("Por enquanto estamos apenas com Dogecoin Ɖ disponivel\n\n");
							printf("1 DOGE = 0,38 BRL\n\n");
							printf("Por favor insira o valor que deseja investir!\n");
							printf("R$:"); scanf("%f", &valor_aplicado);
								if (valor_aplicado <= saldo) {
									saldo = saldo - valor_aplicado;
									printf("\nInvestimento aplicado com sucesso!\n");
								} else {
									printf("\nValor insuficiente na conta!\n");
								}

							break;	

							case '3':
							printf("No momento estamos apenas comercializando para Marco Conversível Bósnio (BAM)\n\n");
							printf("1 BRL = 0,36 BAM\n\n");
							printf("Por favor insira o valor que deseja investir!\n");
							printf("R$:"); scanf("%f", &valor_aplicado);
								if (valor_aplicado <= saldo) {
									saldo = saldo - valor_aplicado;
									printf("\nInvestimento aplicado com sucesso!\n");
								} else {
									printf("\nValor insuficiente na conta!\n");
								}



							break;
						} break;

						case '5':
						return 0;
        	}
    }
	
	return 0;
}
