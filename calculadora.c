#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main() {

    char primeiro_numero[1024], segundo_numero[1024], opcao_menu[1024], opcao_sair[1024], *endptr;
    int operacao, valido, continuar;
    float a, b;

    // setlocale(LC_ALL, "Portuguese");

    wprintf(L"\nBem-vindo à calculadora escrita em C!\n");

    // Solicita o primeiro número ao usuário
    inicio:
    do {
        wprintf(L"\nDigite o primeiro número: ");
        
        if (!fgets(primeiro_numero, 1024, stdin)) {
            return 1;
        };

        a = strtof(primeiro_numero, &endptr);

        if (endptr == primeiro_numero) {
            wprintf(L"\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);
        
    // Solicita ao usuário qual a operação desejada
    do {
        wprintf(L"\nQue operação deseja realizar?\n\n1 - Soma\n2 - Subtração\n3 - Multiplicação\n4 - Divisão\n5 - Porcentagem\n6 - Potenciação\n\nOpção: ");
        
        if (!fgets(opcao_menu, 1024, stdin)) {
            return 1;
        };

        operacao = strtol(opcao_menu, &endptr,  10);

        if (endptr == opcao_menu || operacao < 1 || operacao > 6) {
            wprintf(L"\nOpção inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else {
            valido = 1;
        }
    } while (!valido);

    // Solicita o segundo número ao usuário
    meio:
    do {
        wprintf(L"\nDigite o segundo número: ");
        
        if (!fgets(segundo_numero, 1024, stdin)) {
            return 1;
        };

        b = strtof(segundo_numero, &endptr);

        if (endptr == segundo_numero) {
            wprintf(L"\nValor inválido. Por favor, digite um número inteiro ou decimal.\n");
            valido = 0;
        } else {
            valido = 1;
        }
    } while (!valido);

    // Mostra o resultado ao usuário
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

    // Pergunta ao usuário se deseja realizar outra operação
    do {
        wprintf(L"\nDeseja realizar outra operação?\n\n1 - Sim\n2 - Não\n\nOpção: ");
        
        if (!fgets(opcao_sair, 1024, stdin)) {
            return 1;
        };

        continuar = strtol(opcao_sair, &endptr,  10);

        if (endptr == opcao_sair || continuar < 1 || continuar > 2) {
            wprintf(L"\nOpcao inválida. Por favor, digite um número do menu.\n");
            valido = 0;    
        } else if (continuar == 1) {
            goto inicio;
        } else if (continuar == 2) {
            valido = 1;
        }
    } while (!valido);
}