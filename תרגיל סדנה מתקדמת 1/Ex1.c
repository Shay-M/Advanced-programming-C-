/*This Project was the result of blood sweat and tears of:
Shay Mualem ID: 200332435  |Grop num 661108-62
Maxim Gromov ID: 317225332 |Grop num 61108-61
*/

#include<stdio.h>
#include<malloc.h>
#include <stdlib.h>

/* Function declarations */
unsigned int* powerArray(int);
void Ex1();
/*-----------------------*/

void Ex1() {
	printf("\n-------------(EX1)--------------\n");
	//Definition of the dynamic array, index and number of cells in array
	unsigned int *p, i, num;

	//Getting number of cells from user
	printf("Enter number: ");
	scanf_s("%d", &num);

	//saving the array to pointer p
	p = powerArray(num);

	//if allocation was successful
	if (p)
	{
		//Print the address of p if there was enough memory for the array
		printf("p: %u\n", p);

		//Print the array values
		for (i = 0; i < num; i++)
			printf("%u, ", *(p + i));
		printf("\n");
		//Free the array
		free(p);
	}
}

//creating the array of powers of 2 (up to 32) and returning a pointer to it
unsigned int* powerArray(int n)
{
	//Definition and allocation of the array
	unsigned int *p = (unsigned int*)malloc(n * sizeof(unsigned int));
	//If couldn't allocate memory for array for some reason, print an error message and exit function
	if (p == NULL)
	{
		printf("No memory!\n");
		return 0;
	}
	// If allocation was successful, calculate the powers of 2 based on previous result
	p[0] = 1;
	for (int i = 1; i < n; i++)
	{
		if (i < 32)
		{
			p[i] = p[i - 1] * 2;
		}

		if (i >= 32)
		{
			p[i] = p[i - 32];
		}
	}

	//Return Pointer to result array
	return p;
}
