#include <stdio.h>  
#include <stdlib.h>  
#include <time.h>

int main(void)
{
	int i, aleatorio, num;
	time_t t1;

	srand((unsigned) time (&t1));
	aleatorio = ("%d", rand() % 10);

	printf("Tente acertar o número aleatório de 1 a 10:\n");
	scanf("%d", &num);

	if (num == aleatorio)
		printf("Você acertou!\n");
	else
		printf("Você errou...\n");

	return 0;
}
