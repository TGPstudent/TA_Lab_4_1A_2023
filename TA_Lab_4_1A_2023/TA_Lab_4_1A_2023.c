//TA_Lab_4_1A_2023.c Робота з динамічною пам’яттю. 
//З двох векторів утворити третій заповнивши його різницею елементів первинних масивів.

#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

int main(void)
{	//Мова консолі українська
	system("chcp 1251");
	setlocale(LC_CTYPE, "ukr");
	system("cls");

	int n;
	static int i;
	//Введення з консолі кількості елементів
	do
	{
		printf("\n Введiть кiлькiсть елементiв в векторах, які необхідно опрацювати N="); scanf("%d", &n);
		if (n <= 1) printf("\n Введене некоректне число менше 1. Спробуйте ще раз!");
	} 
	while (n <= 1);
	//Виділення пам'яті та введення вектору А
	int *a = (int*)malloc(sizeof(int)*n);
	if (a == NULL)
	{
		printf("Збiй при виділення динамічної памяті для масиву А");
		return 1;
	}
	else
	{
		printf("\n Введiть значення елементiв масиву A: \n");
		for (i = 0; i < n; i++)
		{
		printf("\t A[%d]=", i + 1); scanf("%d", &a[i]);
		}
	}
	//Виділення пам'яті та введення вектору B
	int *b = (int*)malloc(sizeof(int)*n);
	if (b == NULL)
	{
		printf("Збiй при виділення динамічної памяті для масиву В");
		return 1;
	}
	else
	{
		printf("\n Введiть значення елементiв масиву B: \n");
		for (i = 0; i < n; i++)
		{
			printf("\t B[%d]=", i + 1); scanf("%d", &b[i]);
		}
	}

	system("cls");
		//Виділення пам'яті та обрахунок вектору Rez
		int *Rez = (int*)malloc(sizeof(int)*n);
		if (Rez == NULL)
		{
			printf("Збiй при виділення динамічної памяті для масиву результатів");
			return 1;
		}
		else
		{
			for (i = 0; i < n; i++)
			*(Rez+i) = *(a+i) - *(b+i);
		}
		//Виведення результатыв в консоль
		printf("\n Програма обраховує різницю елементів заданих вами векторів.\n");
		printf("\n Ви задали вектор А={");
		for (i = 0; i < n; i++) printf("%d, ", a[i]); 
		printf("\b\b};");
		printf("\n Ви задали вектор B={");
		for (i = 0; i < n; i++) printf("%d, ", b[i]);
		printf("\b\b};");
		printf("\n\n Вeктор результатів: REZ={");
		for (i = 0; i < n; i++) printf("%d, ", *(Rez+i));
		printf("\b\b}.");
	
	free (a); free (b);	free(Rez);
	
	int getch(); getch();
	return 0;
}
