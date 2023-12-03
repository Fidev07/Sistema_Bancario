
// NOME: FIDEL MIGUEL BATISTA DA SILVA / ADS  - ALGORITMO E LOGICA DE PROGRAMAÇÃO



#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente {
    int codigo;
    char nome[50];
    int agencia;
    char conta_corrente[20];
    float saldo;
};

void depositar(struct Cliente *cliente, float valor) {
    if (valor > 0) {
        cliente->saldo += valor;
        printf("Deposito de R$%.2f realizado com sucesso. Novo saldo: R$%.2f\n", valor, cliente->saldo);
    } else {
        printf("Valor de deposito invalido.\n");
    }
}

void sacar(struct Cliente *cliente, float valor) {
    if (valor > 0 && valor <= cliente->saldo) {
        cliente->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso. Novo saldo: R$%.2f\n", valor, cliente->saldo);
    } else {
        printf("Valor de saque invalido ou saldo insuficiente.\n");
    }
}

void cadastrarCliente(struct Cliente *clientes, int *num_clientes) {
    if (*num_clientes < MAX_CLIENTES) {
        struct Cliente novoCliente;

        printf("Digite o codigo do cliente: \n");
        scanf("%d", &novoCliente.codigo);

        printf("Digite o nome do cliente: \n");
        scanf("%s", novoCliente.nome);

        printf("Digite o numero da agencia: \n");
        scanf("%d", &novoCliente.agencia);

        printf("Digite o numero da conta corrente: \n");
        scanf("%s", novoCliente.conta_corrente);

        printf("Digite o saldo atual: \n");
        scanf("%f", &novoCliente.saldo);

        clientes[*num_clientes] = novoCliente;
        (*num_clientes)++;

        printf("Cliente cadastrado com sucesso!\n");
    } else {
        printf("Limite maximo de clientes atingido. Não eh possivel cadastrar mais clientes.\n");
    }
}

void modificarCliente(struct Cliente *cliente) {
    printf("Digite o novo nome do cliente: \n");
    scanf("%s", cliente->nome);

    printf("Digite o novo numero da agencia: \n");
    scanf("%d", &cliente->agencia);

    printf("Digite o novo numero da conta corrente: \n");
    scanf("%s", cliente->conta_corrente);

    printf("Digite o novo saldo atual: ");
    scanf("%f", &cliente->saldo);

    printf("Informacoes do cliente modificadas com sucesso!\n");
}

int main() {
    struct Cliente clientes[MAX_CLIENTES];
    int num_clientes = 0;

    int opcao;
    do {
        printf("\n===== Menu =====\n");
        printf("1 - Cadastrar Cliente\n");
        printf("2 - Modificar Cliente\n");
        printf("3 - Realizar Operacao (Deposito/Saque)\n");
        printf("4 - Exibir Informacoes dos Clientes\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarCliente(clientes, &num_clientes);
                break;
            case 2: {
                int codigo_cliente_modificar;
                printf("Digite o codigo do cliente que deseja modificar: ");
                scanf("%d", &codigo_cliente_modificar);

                struct Cliente *cliente_modificar = NULL;
                for (int i = 0; i < num_clientes; i++) {
                    if (clientes[i].codigo == codigo_cliente_modificar) {
                        cliente_modificar = &clientes[i];
                        modificarCliente(cliente_modificar);
                        break;
                    }
                }

                if (cliente_modificar == NULL) {
                    printf("Cliente nao encontrado.\n");
                }
                break;
            }
            case 3: {
                int codigo_cliente_modificar;
                printf("Digite o codigo do cliente que deseja realizar uma operacao: ");
                scanf("%d", &codigo_cliente_modificar);

                struct Cliente *cliente_modificar = NULL;
                for (int i = 0; i < num_clientes; i++) {
                    if (clientes[i].codigo == codigo_cliente_modificar) {
                        cliente_modificar = &clientes[i];

                        char opcao_operacao;
                        printf("Deseja realizar um depósito (D) ou um saque (S)? ");
                        scanf(" %c", &opcao_operacao);

                        float valor;
                        if (opcao_operacao == 'D' || opcao_operacao == 'd') {
                            printf("Digite o valor do deposito: ");
                            scanf("%f", &valor);
                            depositar(cliente_modificar, valor);
                        } else if (opcao_operacao == 'S' || opcao_operacao == 's') {
                            printf("Digite o valor do saque: ");
                            scanf("%f", &valor);
                            sacar(cliente_modificar, valor);
                        } else {
                            printf("Opçao invalida.\n");
                        }
                        break;
                    }
                }

                if (cliente_modificar == NULL) {
                    printf("Cliente nao encontrado.\n");
                }
                break;
            }
            case 4:
                // Exibindo informações dos clientes
                for (int i = 0; i < num_clientes; i++) {
                    printf("Codigo: %d, Nome: %s, Saldo: R$%.2f\n", clientes[i].codigo, clientes[i].nome, clientes[i].saldo);
                }
                break;
            case 0:
                printf("Encerrando o programa. Obrigado!\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}