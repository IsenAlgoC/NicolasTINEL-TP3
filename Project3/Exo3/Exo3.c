#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <conio.h>
#include <ctype.h>

int main()
{
	setlocale(LC_ALL, "fr-FR");
	int compteur = 0,
		a = 0,
		i = 0,
		nb_min = 0,
		nb_max = 0,
		absence = 0;


	float
		total = 0,
		note = 0,
		note_max = 0,
		note_min = 0,
		tab[30] = { 0 },
		moyenne = 0;




	while (compteur < 30)
	{
		printf("introduisez une note: \n");
		scanf_s("%f", &note);
		
		tab[i] = note;
		i++;

		/*traitement de la note*/
		if (note >= 0 && note <= 20) {
			compteur = compteur + 1;

			if (note >= note_max)
			{
				if (note == note_max)
					nb_max++;
				else
				{
					note_max = note;
					nb_max = 1;
				}
			}
			if ((note <= note_min) && (note > 0))
			{
				if (note == note_min)
					nb_min++;
				else
				{
					note_min = note;
					nb_min = 1;
				}
			}
		}
		//si la note n'est pas valide /
		if (note < 0.00 || note > 20.00) {
			printf("\nVous avez tapé une note invalide, l'élève est-il (A)bsent ou voulez vous arrêter la saisie (O)ui (N)on ?");
			char ch = '\0';
			ch = (char)_getch();  //permet de poser une question à l'utilisateur
			ch = toupper(ch);
			switch (ch)
			{
			case 'A':
				absence += 1;
				break;
			case 'O':
				compteur = 30;
				break;

			case 'N':
				break;
			}

		}
	}
	if (compteur != 0)
	{

		for (i > 0; i < compteur; i++) {
			printf("\n%.2f", tab[i]);
			total += tab[i];
		}
		moyenne = total / (compteur);

		/*affichage des notes*/
		printf("\n La note moyenne est de :%.2f", moyenne);
		printf("\nLa note minimal est :%.2f", note_min);
		printf("\nIl y %d notes minimales", nb_min);
		printf("\nLa note maximale est de :%.2f", note_max);
		printf("\nIl y a %d notes maximales", nb_max);
		printf("\nL'élève a %d heure(s) d'absence.", absence);
	}
	else {
	printf("Aucune note valide !\n");
	}

}
		