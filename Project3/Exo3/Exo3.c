#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define NBMAXNOTES 30

void main() {
	int i = 0;
	float note[NBMAXNOTES];
	float note_min = 20;
	float note_max = 0;
	char input = 'O';
	int valide = 0, nb_max = 0, nb_min = 0;
	int absent = 0;
	for (int i = 0; i < NBMAXNOTES; i++)
	{
		note[i] = -2;
	}
	while (i < 30)
	{
		printf("Entrer la note n° %d :", i);
		scanf_s("%f", &note[i]);
		if ((note[i] < 0) || (note[i] > 20))
		{

			printf("Elève absent ? ou voulez-vous arrêter la saisie des notes ? A/O/N ");
			char ch = '\0';
			ch = toupper(ch);
			switch(ch)
			{
			case'A':
				note[i] = -1;
				absent = absent + 1;
				i = i + 1;
				break;
			case'O':
				i = 30;
				break;
			case'N':
				i = -1;
				break;
			}
		}
		else
		{
			if (note[i] >= note_max)
			{
				if (note[i] == note_max)
					nb_max++;
				else
				{
					note_max = note[i];
					nb_max = 1;
				}
			}
			if ((note[i] <= note_min) && (note[i] > 0))
			{
				if (note[i] == note_min)
					nb_min++;
				else
				{
					note_min = note[i];
					nb_min = 1;
				}
			}
			valide = valide + 1;
			i = i + 1;
		}
	}
	float quotient = 0;
	float total = 0.0;
	float moyenne = 0.0;
	for (int i = 0; i < NBMAXNOTES; i++)
	{
		if ((note[i] >= 0.0) && (note[i] <= 20))
		{
			quotient = quotient + 1;
			total = total + note[i];
		}
	}
	moyenne = total / quotient;
	double stepone = 0;
	double ecarttype = 0;
	for (int i = 0; i < NBMAXNOTES; i++)
	{
		if ((note[i] >= 0.0) && (note[i] <= 20))
		{
			float var = note[i] - moyenne;
			stepone = stepone + pow(2, var);
		}
	}
	ecarttype = (1 / (quotient - 1)) * stepone;
	printf("Notes valides : %d,\n Note min : %f,\n Note max : %f,\n Nombre d'absences : %d,\n Moyenne : %f,\n Ecarttype : %f", valide, note_min, note_max, absent, moyenne, ecarttype);
}