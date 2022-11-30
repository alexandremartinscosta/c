#include <stdio.h>

void main () 
{
  int numero, *ptr_numero, **pptr_numero;

  // Inicializando numero com zero
  numero = 0;
  printf("\nO valor de numero é: %d\n", numero);
  printf("\nO endereço de numero é: %x\n", &numero);

  // Inicializando os ponteiros
  ptr_numero = &numero;
  pptr_numero = &ptr_numero;
  printf("-----------------------------------------------------------------------");
  *ptr_numero = *ptr_numero + 10;
  printf("\nO valor de numero é: %d\n", numero);
  printf("\nO endereço apontado por ptr_numero é: %x\n", ptr_numero);
  printf("\nO valor da variável numero que está sendo apontada por ptr_numero é: %d\n", *ptr_numero);
  printf("\nO endereço de memória da variável ptr_numero é: %x\n", &ptr_numero);
  printf("-----------------------------------------------------------------------");
  **pptr_numero = **pptr_numero + 10;
  printf("\nO valor de numero é: %d\n", numero);
  printf("\nO endereço apontado por pptr_numero é: %x\n", pptr_numero);
  printf("\nO valor da variável numero que está sendo apontada por pptr_numero é: %d\n", **pptr_numero);
  printf("\nO endereço de memória da variável pptr_numero é: %x\n", &pptr_numero);
}