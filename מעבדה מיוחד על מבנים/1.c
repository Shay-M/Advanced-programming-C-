#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int ID;
	int *arrGrades;
	int Num_of_tests;
} student_init_data;

typedef struct
{
	int ID;
	double Avrg;
} student_processed_data;

typedef struct
{
	student_processed_data *above_avrg, *below_avrg;
	int num_above, num_below;
	double TotalAvrg;
} statistics;

void Init_Array (student_init_data *, int);
int *Input_Data (int);
double Student_Average (int *, int);
double Total_Average (double *, int);
void Classification (student_init_data *, int, statistics * );
void Print_Tab (statistics *);
void Free_Memory (student_init_data *, int, statistics *);

#define N 5

void main ()
{
	int i;
	student_init_data arrStud[N];
	statistics result;
	Init_Array (arrStud, N);
	for (i=0; i<N; i++)
	{
		printf ("\nStudent %d, ID: %d\n", i+1, arrStud[i].ID);
		arrStud[i].arrGrades = Input_Data(arrStud[i].Num_of_tests);
	}
	Classification (arrStud, N, &result);
	Print_Tab (&result);
	Free_Memory (arrStud, N, &result);          
}


void Init_Array (student_init_data *arrStud, int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf ("\nStudent %d\n", i+1);
		printf("Enter ID  ");
		scanf("%d", &arrStud[i].ID);
		printf("Enter number of tests  ");
		scanf("%d",&arrStud[i].Num_of_tests);
	}
}


int *Input_Data (int num)
{
	int i,*arr;
	arr = (int *)malloc (num*sizeof(int));
	for(i=0; i < num; i++)
	{
		printf("Enter grade for course %d  ",i+1);
		scanf("%d",arr+i);
	}
	return arr;
}


double Student_Average (int *arr, int num)
{
	double Avg=0;
    int i;
	for (i=0;i<num;i++)
		Avg += *(arr+i);
	Avg /= num;
    return Avg;
}


double Total_Average (double *arr, int n)
{
	double Avg=0;
    int i;
	for (i=0;i<n;i++)
		Avg += *(arr+i);
	Avg /= n;
    return Avg;
}


void Classification (student_init_data *arrStud, int n, statistics *ptr_stat)
{
	int i, above_cnt=0, below_cnt=0;
	double *arr_avr = (double *)malloc (n*sizeof(double));
	ptr_stat->num_above = 0;
	for (i=0; i<n; i++)
		arr_avr[i] = Student_Average (arrStud[i].arrGrades, arrStud[i].Num_of_tests);
	ptr_stat->TotalAvrg = Total_Average (arr_avr, n);
	for (i=0; i<n; i++)
		if (arr_avr[i] >= ptr_stat->TotalAvrg)
			ptr_stat->num_above++;
	ptr_stat->num_below = n - ptr_stat->num_above;
	ptr_stat->above_avrg = (student_processed_data *)malloc (ptr_stat->num_above * sizeof(student_processed_data));
	ptr_stat->below_avrg = (student_processed_data *)malloc (ptr_stat->num_below * sizeof(student_processed_data));
	for (i=0; i<n; i++)
		if (arr_avr[i] >= ptr_stat->TotalAvrg)
		{
			ptr_stat->above_avrg[above_cnt].ID = arrStud[i].ID;
			ptr_stat->above_avrg[above_cnt].Avrg = arr_avr[i];
			above_cnt++;
		}
		else
		{
			ptr_stat->below_avrg[below_cnt].ID = arrStud[i].ID;
			ptr_stat->below_avrg[below_cnt].Avrg = arr_avr[i];
			below_cnt++;
		}
	free (arr_avr);
}


void Print_Tab (statistics *ptr_stat)
{
	int i;
	printf ("\nTotal average = %.2lf\n", ptr_stat->TotalAvrg);
	printf ("\n%d averages above total:\n", ptr_stat->num_above);
	for (i=0; i<ptr_stat->num_above; i++)
		printf ("ID: %d    Average: %.2lf\n", 
					ptr_stat->above_avrg[i].ID, ptr_stat->above_avrg[i].Avrg);
	printf ("\n%d averages below total:\n", ptr_stat->num_below);
	for (i=0; i<ptr_stat->num_below; i++)
		printf ("ID: %d    Average: %.2lf\n", 
					ptr_stat->below_avrg[i].ID, ptr_stat->below_avrg[i].Avrg);
}


void Free_Memory (student_init_data *arrStud, int n, statistics *ptr_stat)
{
	int i;
    for (i=0; i<n; i++)
		free ( (arrStud+i)->arrGrades ); 
	free (ptr_stat->above_avrg);
	free (ptr_stat->below_avrg);
}


