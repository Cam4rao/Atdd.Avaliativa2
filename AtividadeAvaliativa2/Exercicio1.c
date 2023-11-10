#include <stdio.h>

int validaQuantidade();
float calculaSalario(int quantidade);

int main() {
    int quantidade;
    char continuar;

    do {
        quantidade = validaQuantidade();
        printf("Salario: R$ %.2f\n", calculaSalario(quantidade));
        printf("Deseja calcular o salario de outro funcionario? (S/N): ");
        scanf(" %c", &continuar);
    } while (continuar == 'S' || continuar == 's');

    return 0;
}

int validaQuantidade() {
    int quantidade;
    do {
        printf("Digite a quantidade de pecas fabricadas: ");
        scanf("%d", &quantidade);

        if (quantidade < 0) {
            printf("Quantidade invalida. Por favor, digite um valor nao negativo.\n");
        }

    } while (quantidade < 0);

    return quantidade;
}

float calculaSalario(int quantidade) {
    const float salarioBase = 600.00;
    const int limite1 = 50;
    const int limite2 = 80;
    const float adicional1 = 0.50;
    const float adicional2 = 0.75;
    float salarioTotal = salarioBase;

    if (quantidade > limite1) {
        salarioTotal += (quantidade - limite1) * adicional1;

        if (quantidade > limite2) {
            salarioTotal += (quantidade - limite2) * (adicional2 - adicional1);
        }
    }

    return salarioTotal;
}