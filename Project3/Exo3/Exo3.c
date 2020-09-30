#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	int compteur = 0,
		a = 0,
		i = 0,
		nb_min = 0,
		nb_max = 0;

	float
		total = 0,
		note = 0,
		note_max = 0,
		note_min = 0,
		tab[30] = { 0 },
		moyenne = 0;




	while (note >= 0 && note <= 20)
	{
		printf("Entrez la note numero %d \n", i + 1);
		scanf_s("%f", &note);
		compteur = compteur + 1;
		tab[i] = note;
		i++;
	}

	if (note < 0 || note > 20) {
		printf("\nElève absent ? ou voulez-vous arrêter la saisie des notes ? A(bsent) /O(ui) /N(on)");
		char ch = '\0';
		ch = _getch("AON");  //permet de poser une question à l'utilisateur

		switch (ch)
		{
		case 'A':
		case 'a':
			note == -1;
			break;
		case 'O':
		case 'o':
			compteur = compteur - 1;
			break;

		case 'N':
		case 'n':
			break;
		}

	}
}