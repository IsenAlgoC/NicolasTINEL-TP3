#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

#define carre(x) (x)*(x) //on rajoute des () aux x pour que n+1 soit prioritaire par rapport à la multiplication
// si on ne mettait pas les parenthèses on obtiendrait 11 pour carre(Nb+1)
main() {
	int Nb = 0;
	printf("\nEntrer une valeur pour en faire le carre : ");
	scanf_s("%d", &Nb);

	printf("%d, %d", carre(Nb), carre(Nb +1));
}
