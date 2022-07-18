#include<stdio.h>

// Na linguagem C, é preciso definir os tipos de variáveis

// Nomes de variáveis não podem conter cedilha, acento ou espaços
// e também não podem começar com um número.

int main(void)
{
    // Declaração das variáveis
    int n = 10; // variável numérica de tipo inteiro 
    float n2 = 6.79; // variável numérica de tipo decimal. Armazena 4 bytes de informação
    char letra = 'a'; // variável do tipo caracter unitário
    char nome[11] = "Alexandre"; //quando o valor é uma string, se usa aspas duplas e o número de caracteres da variável ao lado do nome atribuído
    double n3 = 1.23456; // o tipo double suporte 15 casas decimais, armazenando 8 bytes de informação

    int valor1, valor2, soma, sub, mult, di;

    // O comando printf exibe um texto na tela
    printf("Exibindo o número inteiro %d\n",n); //o %d indica que ali será colocada uma variável de tipo inteiro decimal. Logo após, indica-se o nome da variável que corresponde ao tipo indicado.
    printf("Exibindo um número real %f\n",n2);
    printf("Exibindo o caracter %c\n",letra);
    printf("Meu nome é %s\n",nome);
    printf("Exibindo variável do tipo double %f\n",n3);
    printf("Valores: %d %f %c %s %f\n",n,n2,letra,nome,n3); // para retornar mais de uma variável, é preciso colocar os valores em ordem

    // Utilização do scanf
    printf("Digite um número inteiro: ");
    scanf("%d",&valor1); // o & indica que o endereço do valor inteiro digitado pelo usuário será a variável valor1

    printf("Digite outro número inteiro: ");
    scanf("%d",&valor2);

    // Operadores aritméticos
    soma = valor1 + valor2;
    sub = valor1 - valor2;
    mult = valor1 * valor2;
    di = valor1 / valor2;

    printf("O valor da soma de %d + %d = %d\n",valor1,valor2,soma);
    printf("O valor da subtração de %d - %d = %d\n",valor1,valor2,sub);
    printf("O valor da multiplicação de %d * %d = %d\n",valor1,valor2,mult);
    printf("O valor da divisão de %d / %d = %d\n",valor1,valor2,di);
  
    return 0;
}