/*#define_CRT_NONSTDC_NO_WARNINGS
#define_CRT_SECURE_NO_WARNINGS*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>
	int main()
	{
		setlocale(LC_ALL, "Russian");
		int **mas_a = 0;
		int **mas_b = 0;
		int **mas_c= 0;
		int razmer,elem_c;
		clock_t start, end; // объ€вл€ем переменные дл€ определени€ времени выполнени€
		printf("¬введите размер матриц:");
		scanf("%d", &razmer);
		start = clock();
		mas_a = (int**)malloc(sizeof(*mas_a) * razmer);
		for (int i = 0; i<razmer; i++)
			mas_a[i] =  (int*)malloc(sizeof(**mas_a) * razmer);


		mas_b = (int**)malloc(sizeof(*mas_b) * razmer);
		for (int i = 0; i<razmer; i++)
			mas_b[i] =  (int*)malloc(sizeof(**mas_b) * razmer);


		mas_c =  (int**)malloc(sizeof(*mas_c) * razmer);
		for (int i = 0; i<razmer; i++)
			mas_c[i] = (int*)malloc(sizeof(**mas_c) * razmer);


		srand(time(NULL)); // инициализируем параметры генератора случайных чисел

		for (int i = 0; i<razmer; i++)
			for (int j = 0; j <razmer; j++)
				mas_a[i][j] = rand()%10 * razmer + 1;
		
		srand(time(NULL)); // инициализируем параметры генератора случайных чисел
		for (int i = 0; i<razmer; i++)
			for (int j = 0; j <razmer; j++)
				mas_b[i][j] = rand()%10 * razmer + 1;
		
		for (int i = 0; i<razmer; i++)
		{
			for (int j = 0; j <razmer; j++)
			{
				elem_c = 0;
				for (int r = 0; r <razmer; r++)
				{
					elem_c = elem_c + mas_a[i][r] * mas_b[r][j];
					mas_c[i][j] = elem_c;
				}
			}
		}

		
		/*for (int i = 0; i<razmer; i++)
		{
			printf("\n");
			for (int j = 0; j <razmer; j++)
				printf("%d\t", mas_a[i][j]);
		}
		printf("\n\n");
		for (int i = 0; i<razmer; i++)
		{
			printf("\n");
			for (int j = 0; j <razmer; j++)
				printf("%d\t", mas_b[i][j]);
		}
		printf("\n\n");
		for (int i = 0; i<razmer; i++)
		{
			printf("\n");
			for (int j = 0; j <razmer; j++)
				printf("%d\t", mas_c[i][j]);
		}*/

		end = clock();
		float time = end - start;
		printf("¬рем€ выполнени€ работы программы=%.3f с\n", time / CLOCKS_PER_SEC);
		system("pause");
		return(0);
	}

