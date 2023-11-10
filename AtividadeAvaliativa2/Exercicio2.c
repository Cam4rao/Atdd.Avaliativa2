#include <stdio.h>
#include <stdlib.h>

char validaSexo() {
    char sexo;
    while (1) {
        printf("Informe o sexo (M/F): ");
        scanf(" %c", &sexo);
        if (sexo == 'M' || sexo == 'F') {
            return sexo;
        } else {
            printf("Sexo invalido. Por favor, informe M para masculino ou F para feminino.\n");
        }
    }
}

float validaSalario() {
    float salario;
    while (1) {
        printf("Informe o salario: R$ ");
        scanf("%f", &salario);
        if (salario > 1.00) {
            return salario;
        } else {
            printf("Osalario deve ser maior que R$1,00.\n");
        }
    }
}

char* classificaSalario(float salario, float salarioMinimo) {
    if (salario > salarioMinimo) {
        return "Acima do salario minimo";
    } else if (salario == salarioMinimo) {
        return "Igual salario minimo";
    } else {
        return "Abaixo do salario minimo";
    }
}

void mostraClassifica(char sexo, float salario, float salarioMinimo) {
    printf("\nResultado para o assalariado:\n");
    printf("Sexo: %s\n", (sexo == 'M') ? "Masculino" : "Feminino");
    printf("Salario: R$ %.2f\n", salario);
    printf("Classificacao em relacao ao salario minimo: %s\n", classificaSalario(salario, salarioMinimo));
}

int main() {
    float salarioMinimo = 1400.00;
    
    int abaixoSalarioMinimo = 0, acimaSalarioMinimo = 0;

    int numAssalariados;
    printf("Informe o numero de assalariados a serem pesquisados: ");
    scanf("%d", &numAssalariados);

    for (int i = 0; i < numAssalariados; i++) {
        char sexo = validaSexo();
        float salario = validaSalario();

        if (salario > salarioMinimo) {
            acimaSalarioMinimo++;
        } else {
            abaixoSalarioMinimo++;
        }

        mostraClassifica(sexo, salario, salarioMinimo);
    }

    printf("\nQuantidade de assalariados abaixo do salario minimo: %d\n", abaixoSalarioMinimo);
    printf("Quantidade de assalariados acima do salario minimo: %d\n", acimaSalarioMinimo);

    return 0;
}