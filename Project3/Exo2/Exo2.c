#include <stdlib.h>
#include <stdio.h>

main() {
	unsigned long a = 2868838400;	
	int i = 0;	
	printf("le nombre d'octets necessaire pour coder le nombre %u est 4 octets soit 32 bits", a);
	while (i < 32) {	//le nombre max sur un unsigned int peut être codé sur 32 bits
		if (a & 1) {
			if (i < 10) {	// on utilise ceci par soucis d'esthétiqueprintf("\nbit  %d : ON", i);
			}
			else
				printf("\nbit %d : ON", i);	//affiche si le bit est sur 0 ou 1
		}
		else {
			if (i < 10) {	
				printf("\nbit  %d : OFF", i);
			}
			else
				printf("\nbit %d : OFF", i);
		}
		i++; a = a >> 1;
	}
	printf("\nBye !");
}