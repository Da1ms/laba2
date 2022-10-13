#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

void qs(int* items, int left, int right)
{
	int i, j;
	int x, y;

	i = left; j = right;

	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i<right)) i++;
		while ((x <items[j]) && (j >left)) j--;

		if (i<= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} 
	while (i<= j);
	if (left< j) qs(items, left, j);
	if (i<right) qs(items, i, right);
}

void shell(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i<count; ++i) {
			x = items[i];
			for (j = i - gap; (x <items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

void shell_minus(int* items, int count)
{
	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i<count; ++i) {
			x = items[i];
			for (j = i - gap; (x >items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}

int compare(const int* a, const int* b)
{
	return *a - *b;
}
void mas(int *items, int count)
{
	for (int i = 0; i< count; i++)
	{
		items[i] = rand() % 100;
	}
}
void Punkt1shell(int *items, int count)
{
	FILE *in = fopen("input.txt","w");
	fprintf(in,"Случайный набор\n");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	shell(items, count);
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Шелла: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt1qs(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	qs(items, 0, count - 1);
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"QS: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt1shell_minus(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	shell_minus(items, count);	
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Быстрая сортировка: ");
	fprintf(in,"%f\n",(double)res/1000);
	fprintf(in,"\n");
	fclose(in);
	
}
void Punkt2shell(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	fprintf(in,"Возрастающий\n");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	qs(items, 0, count - 1);
	shell(items, count);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Шелла: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt2qs(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	qs(items, 0, count - 1);
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"QS: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt2shell_minus(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	start = clock();
	qs(items, 0, count - 1);
	shell_minus(items, count);	
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Быстрая сортировка: ");
	fprintf(in,"%f\n",(double)res/1000);
	fprintf(in,"\n");
	fclose(in);	
}

void Punkt3shell(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	fprintf(in,"Убывающая\n");
	srand(time(NULL));
	clock_t start, end;
	shell_minus(items, count);
	start = clock();
	shell(items, count);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Шелла: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt3qs(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	shell_minus(items, count);
	start = clock();
	qs(items, 0, count - 1);
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"QS: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt3shell_minus(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	shell_minus(items, count);
	start = clock();
	shell_minus(items, count);	
	end = clock();	
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Быстрая сортировка: ");
	fprintf(in,"%f\n",(double)res/1000);
	fprintf(in,"\n");
	fclose(in);	
}
void Punkt4shell(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	fprintf(in,"Пирамида\n");
	srand(time(NULL));
	clock_t start, end;
	qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Шелла: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt4qs(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"QS: ");
	fprintf(in,"%f\n",(double)res/1000);
	fclose(in);
	
}
void Punkt4shell_minus(int *items, int count)
{
	mas(items,count);
	FILE *in = fopen("input.txt","a");
	srand(time(NULL));
	clock_t start, end;
	qs(items, count / 2, count - 1);
	shell_minus(items, count / 2);
	start = clock();
	shell(items, count);
	qs(items, 0, count - 1);
	end = clock();
	float res = end - start;
	printf("Время сортировки: %f\n", (double)res/ 1000);
	fprintf(in,"Быстрая сортировка: ");
	fprintf(in,"%f\n",(double)res/1000);
	fprintf(in,"\n");
	fclose(in);	
}

int main()
{
	//Задание 2
	setlocale(LC_ALL, "RUS");
	int count;
	printf("Введите размерность массива: ");
	scanf("%d", &count);
	int* items = (int*)malloc(count * sizeof(items));
	for (int i = 0; i< count; i++)
	{
		items[i] = rand() % 100;
	}
	Punkt1shell(items,count);
	Punkt1qs(items,count);
	Punkt1shell_minus(items,count);
	
	Punkt2shell(items,count);
	Punkt2qs(items,count);
	Punkt2shell_minus(items,count);
	
	Punkt3shell(items,count);
	Punkt3qs(items,count);
	Punkt3shell_minus(items,count);

	Punkt4shell(items,count);
	Punkt4qs(items,count);
	Punkt4shell_minus(items,count);
	
	
	system("PAUSE");
	return 0;
}

