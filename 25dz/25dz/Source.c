#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
double* randlfmassiv(int n, double dm);
void main()
{
	int size;
	double max;
	setlocale(LC_ALL, "RUS");
	printf("\n¬ведите размер дл€ рандомного массива: ");
	scanf("%d", &size);
	printf("\n¬ведите масимальное вещественное число в рандоме: ");
	scanf("%lf", &max);
	randlfmassiv(size,max);
}
double* randlfmassiv(int n, double dm)
{
	double A[100];
	for (int i = 0; i < n; i++)
	{
		A[i] = 0.01 + 1.f * (dm-0.01) * rand() / RAND_MAX;
	}
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %lf", i, A[i]);
	}
	double g,h;
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n-1; i++)
		{
			g = A[i] - (int)A[i];
			h = A[i + 1] - (int)A[i + 1];
			if (g > h)
			{
				double y = A[i + 1];
				A[i + 1] = A[i];
				A[i] = y;
			}
		}
	}
	puts("\n\n\n");
	for (int i = 0; i < n; i++)
	{
		printf("\nA[%d] = %lf", i, A[i]);
	}
	return 0;
}