#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <locale.h>

int main() {
    
    char primeiro_numero[1024], segundo_numero[1024], opcao_menu[1024], opcao_sair[1024], *endptr;
    int operacao, valido, continuar;
    float a, b;

    setlocale(LC_CTYPE, "Portuguese");
    wprintf(L"\nBem-vindo à calculadora escrita em C!\n");

    inicio:
    do { 
        wprintf(L"\nDigite o primeiro número: ");
        fgets(primeiro_numero, 1024, stdin);
        a = strtof(primeiro_numero, &endptr);

        if (primeiro_numero == endptr) {
            wprintf(L"\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else if (strchr(primeiro_numero, ',') != NULL) {
            wprintf(L"\nPor favor, separe a casa decimal com o ponto.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);
        
    do {
        wprintf(L"\nQue operação deseja realizar?\n\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Porcentagem\n6 - Potenciação\n\nOpção: ");
        fgets(opcao_menu, 1024, stdin);
        operacao = strtol(opcao_menu, &endptr,  10);

        if (opcao_menu == endptr || operacao < 1 || operacao > 6) {
            wprintf(L"\nOpção inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else {
            valido = 1;
        }
    } while (!valido);

    meio:
    do {
        wprintf(L"\nDigite o segundo número: ");
        fgets(segundo_numero, 1024, stdin);
        b = strtof(segundo_numero, &endptr);

        if (segundo_numero == endptr) {
            wprintf(L"\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else if (strchr(segundo_numero, ',') != NULL) {
            wprintf(L"\nPor favor, separe a casa decimal com o ponto.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);

    switch(operacao) {
        case 1:
            wprintf(L"\n%f mais %f é igual a: %f\n", a, b, a + b);
            break;
        case 2:
            wprintf(L"\n%f menos %f é igual a: %f\n", a, b, a - b);
            break;
        case 3:
            wprintf(L"\n%f vezes %f é igual a: %f\n", a, b, a * b);
            break;
        case 4:
            if (b == 0) {
                wprintf(L"\nNão é possível dividir por zero. Por favor, escolha um divisor válido.\n");
                goto meio;
            } else {
                wprintf(L"\n%f dividido por %f é igual a: %f\n", a, b, a / b);
                break;
            }
        case 5:
            wprintf(L"\nA porcentagem de %f em %f é igual a: %f%%\n", a, b, a / b * 100);
            break;
        case 6:
            wprintf(L"\n%f elevado à potência %f é igual a: %f\n", a, b, pow(a,b));
            break;
        default:
            return 0;
    }

    do {
        wprintf(L"\nDeseja realizar outra operação?\n\n1 - Sim\n2 - Não\n\nOpção: ");
        fgets(opcao_sair, 1024, stdin);
        continuar = strtol(opcao_sair, &endptr,  10);

        if (opcao_sair == endptr || continuar < 1 || continuar > 2) {
            wprintf(L"\nOpcao inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else if (continuar == 1) {
            goto inicio;
        } else if (continuar == 2) {
            valido = 1;
        }
    } while (!valido);
}