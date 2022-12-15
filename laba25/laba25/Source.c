#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* randmassiv(int n, int mmax);
double* randlfmassiv(int n, double dm);

void main()
{
	setlocale(LC_ALL, "RUS");
	srand(time(NULL));
	int m = 1 + rand() % 10;
	int k;
	printf("Введиет число: ");
	scanf_s("%d", &k);
	if (k == m)
	{
		printf("Вы угадали число. Вы выбрали: %d. Загаданное число: %d", k, m);
	}
	else
	{
		printf("Вы не угадали число. Вы выбрали: %d. Загаданное число: %d", k, m);
	}
	int A = 1, B = 4, j;
	int q = A + rand() % (B - A);
	printf("\nВыберите предмет - 1-камень, 2-ножницы, 3-бумага - ");
	scanf("%d",&j);
	if (j == q)
	{
		printf("Ничья. Выбраны одинаковые предметы.");
	}
	else if (j == 1 && q == 2)
	{
		printf("Вы победили. Противник выбрал ножницы.");
	}
	else if (j == 1 && q == 3)
	{
		printf("Вы проиграли. Противник выбрал бумагу.");
	}
	else if (j == 2 && q == 3)
	{
		printf("Вы победили. Противник выбрал бумагу.");
	}
	else if (j == 3 && q == 1)
	{
		printf("Вы победили. Противник выбрал камень.");
	}
	else if (j == 2 && q == 1)
	{
		printf("Вы проиграли. Противник выбрал камень.");
	}
	int mmax;
	printf("\nВведите максимальное число в рандоме: ");
	scanf("%d", &mmax);
	printf("\nРандомное целое число: %d", rand10(mmax));
	double dmin, dmax;
	printf("\nВведите интервал из вещественных чисел: ");
	scanf("%lf%lf", &dmin, &dmax);
	printf("\nРандомное вещественное число: %lf", rand_double(dmin,dmax));
	int size;
	double dm;
	printf("\nВведите размер для рандомного массива: ");
	scanf("%d", &size);
	randmassiv(size, mmax);
	printf("\nВведите размер для рандомного массива: ");
	scanf("%d", &size);
	printf("\nВведите масимальное вещественное число в рандоме: ");
	scanf("%lf",&dm);
	randlfmassiv(size,dm);
	printf("\n");
	//3
	int razm=0, max=0;
	printf("\nВведите размер массива: ");
	scanf("%d", &razm);
	printf("\nВведите максимальное число в рандоме: ");
	scanf("%d", &max);
	int* counter;
	counter = (int*)calloc(max, sizeof(int));
	int* randA = randmassiv(razm,max);
	for (int i = 0; i < razm; i++)
	{
		counter[randA[i]]++;
	}
	for (int i = 0; i < max; i++) 
	{
		printf("\ncounter[%d] = %d", i, counter[i]);
	}
	printf("\n\n");
	Gist(counter,max);
}
int rand10(int mmax)
{
	int A = 1;
	int ch = A + rand() % (mmax - A);
	return ch;
}
double rand_double(double dmin, double dmax)
{
	double ch = dmin + 1. * (dmax - dmin) * rand() / RAND_MAX;
	return ch;
}
int* randmassiv(int n, int mmax)
{
	int A[100];
	for (int i = 0; i < n; i++)
	{
		A[i] = 1 + rand() % (mmax - 1);
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %d", i, A[i]);
	}
	return A;
}
double* randlfmassiv(int n, double dm)
{
	double A[100];
	for (int i = 0; i < n; i++)
	{
		A[i] = (-1*dm) + 1.f * (dm-(-1*dm))*rand()/ RAND_MAX;
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %lf", i, A[i]);
	}
	return 0;
}
int Gist(int* counterArray, int arrayLenght) 
{
	int maxNum = -10000000;
	for (int i = 0; i < arrayLenght; i++) 
	{
		if (counterArray[i] > maxNum) 
		{
			maxNum = counterArray[i];
		}
	}
	for (int i = maxNum; i > 0; i--) {
		for (int j = 0; j < arrayLenght; j++) {
			if ((counterArray[j] >= i))
			{
				printf("*");
			}
			else 
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}