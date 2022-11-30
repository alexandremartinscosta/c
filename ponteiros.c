#include <stdio.h>

void main ()
{
  int numero = 15;

  // O ponteiro é sempre declarado com um asterisco na frente.
  // Neste caso, estamos dizendo que o valor do ponteiro será o endereço de numero
  int *ponteiro;
  ponteiro = &numero;

  printf("O valor da variável é: %d\n", numero);
  printf("O endereço da variável é: %d\n", &numero);
  printf("O endereço apontado pelo ponteiro em números inteiros é: %d\n", ponteiro);
  printf("O endereço apontado pelo ponteiro em hexadecimal é: %x\n", ponteiro);

  if (ponteiro == &numero) {
    printf("O ponteiro aponta para o endereço correto da variável.\n");
  } else {
    printf("O ponteiro aponta para o endereço incorreto da variável.\n");
  }
}