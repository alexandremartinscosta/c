#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int bufsize = 30;
    char input_buffer[bufsize];
    int opt, continuar;
    float a, b;

    calculadora:
    printf("Digite o primeiro numero: ");
    fgets(input_buffer, bufsize, stdin);
    sscanf(input_buffer, "%f", &a);


}