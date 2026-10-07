#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char titular[50];
    float saldo;
} Contabancaria;

void depositar(Contabancaria *conta) {
    float valor;
    printf("\ndigite o valor do deposito: R$ ");
    scanf("%f", &valor);

    if (valor > 0) {
        conta->saldo += valor;
        printf("[SUCESSO] deposito de R$ %.2f realizado!\n", valor);
    } else {
        printf("[ERRO] valor invalido para deposito.\n");
    }
}

void sacar(Contabancaria *conta) {
    float valor;
    printf("\ndigite o valor do saque: R$ ");
    scanf("%f", &valor);

    if (valor <= 0) {
        printf("[ERRO] valor invalido para saque.\n");
    } else if (valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("[SUCESSO] saque de R$ %.2f realizado!\n", valor);
    } else {
        printf("[ALERTA] saldo insuficiente! seu saldo atual e: R$ %.2f\n", conta->saldo);
    }
}

void salvaSaldo(float saldo) {
    FILE *arquivo = fopen("saldo.txt", "w");

    if (arquivo == NULL) {
        printf("[ERRO] nao foi possivel salvar o saldo em disco.\n");
        return;
    }
    fprintf(arquivo, "%.2f", saldo);

    fclose(arquivo);

    printf("[SISTEMA] saldo de R$ %.2f salvo com sucesso em 'saldo.txt'!\n", saldo);
}

void carregarSaldo(Contabancaria *conta) {
    FILE *arquivo = fopen("saldo.txt", "r");

    if (arquivo != NULL) {
        fscanf(arquivo, "%f", &conta->saldo);
        fclose(arquivo);
        printf("[SISTEMA] saldo carregado com sucesso do disco!\n");
    } else {
        printf("[SISTEMA] nenhum historico encontrado. iniciando com saldo zerado.\n");
    }
}

int main(void) {
    Contabancaria minhaconta = {"Cliente Teste", 0.0f};
    int opcao = 0;

    carregarSaldo(&minhaconta);

    while (opcao != 4) {
    printf("==================================\n");
    printf("   SISTEMA BANCARIO INICIALIZADO  \n");
    printf("==================================\n");
    printf("cliente: %s\n", minhaconta.titular);
    printf("----------------------------------\n");
    printf("1. ver saldo\n");
    printf("2. realizar deposito\n");
    printf("3. realizar saque\n");
    printf("4. sair\n");
    printf("----------------------------------\n");
    printf("escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1: 
          printf("\n---> saldo atual: R$ %.2f <---\n", minhaconta.saldo);
          break;
        case 2:
          depositar(&minhaconta);
          break;
        case 3:
          sacar(&minhaconta);
          break;
        case 4:
          salvaSaldo(minhaconta.saldo);
          printf("\nencerrando o caixa eletronico... ate logo!\n");
          break;
        default:
          printf("\n[erro] opcao invalida! digite um numero de 1 a 4.\n");
    }
}
    
    return 0;
}