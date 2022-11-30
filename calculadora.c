#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

void main() {
    
    char primeiro_numero[1024], segundo_numero[1024], opcao_menu[1024], opcao_sair[1024], *ponteiro_final;
    int operacao, valido, continuar;
    float a, b;

    setlocale(LC_CTYPE, "Portuguese");
    printf("\nBem-vindo à calculadora escrita em C!\n");

    inicio:
    do { 
        printf("\nDigite o primeiro número: ");
        fgets(primeiro_numero, 1024, stdin);
        a = strtof(primeiro_numero, &ponteiro_final);

        if (primeiro_numero == ponteiro_final) {
            printf("\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else if (strchr(primeiro_numero, ',') != NULL) {
            printf("\nPor favor, separe a casa decimal com o ponto.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);
        
    do {
        printf("\nQue operação deseja realizar?\n\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Porcentagem\n6 - Potenciação\n\nOpção: ");
        fgets(opcao_menu, 1024, stdin);
        operacao = atoi(opcao_menu);

        if (strlen(opcao_menu) != 2 || operacao < 1 || operacao > 6) {
            printf("\nOpção inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else {
            valido = 1;
        }
    } while (!valido);

    meio:
    do {
        printf("\nDigite o segundo número: ");
        fgets(segundo_numero, 1024, stdin);
        b = strtof(segundo_numero, &ponteiro_final);

        if (segundo_numero == ponteiro_final) {
            printf("\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else if (strchr(segundo_numero, ',') != NULL) {
            printf("\nPor favor, separe a casa decimal com o ponto.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);

    switch(operacao) {
        case 1:
            printf("\n%f mais %f é igual a: %f\n", a, b, a + b);
            break;
        case 2:
            printf("\n%f menos %f é igual a: %f\n", a, b, a - b);
            break;
        case 3:
            printf("\n%f vezes %f é igual a: %f\n", a, b, a * b);
            break;
        case 4:
            if (b == 0) {
                printf("\nNão é possível dividir por zero. Por favor, escolha um divisor válido.\n");
                goto meio;
            } else {
                printf("\n%f dividido por %f é igual a: %f\n", a, b, a / b);
                break;
            }
        case 5:
            printf("\nA porcentagem de %f em %f é igual a: %f%%\n", a, b, a / b * 100);
            break;
        case 6:
            printf("\n%f elevado à potência %f é igual a: %f\n", a, b, pow(a,b));
            break;
    }

    do {
        printf("\nDeseja realizar outra operação?\n\n1 - Sim\n2 - Não\n\nOpção: ");
        fgets(opcao_sair, 1024, stdin);
        continuar = atoi(opcao_sair);

        if (strlen(opcao_sair) != 2 || continuar < 1 || continuar > 2) {
            printf("\nOpcao inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else if (continuar == 1) {
            goto inicio;
        } else if (continuar == 2) {
            valido = 1;
        }
    } while (!valido);
}