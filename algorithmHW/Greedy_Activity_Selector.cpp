#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

void Greedy_Activity_Selector(int n, int start_time[], int finish_time[]) 
{
	//n mean that length of array
	int A[30030];
	A[0] = 1; // A <- {a1}
	int i = 1;
	int j = 1; // index for A and A[0] initial set so become with index 1

	//m first with 1 because 0 initial set a1
	for (int m = 1; m < n; m++) 
	{
		//next work's start_time should >= now work's finish_time
		if (start_time[m] >= finish_time[i]) 
		{
			A[j] = m; //let {am} input A sequence
			j++;
			i = m; //update finish_time
		}
	}

	for (int k = 0; k < j; k++)
		printf("%d ", A[k]);
	printf("\n");
}

int main() 
{
	int id[30030];
	int start_time[30030];
	int finish_time[30030];
	int i = 1; // array index for start_time and finish time

	while (scanf("%d%d%d",&id[i], &start_time[i], &finish_time[i]) != EOF) 
		i++;

	Greedy_Activity_Selector(i, start_time, finish_time); // call function
	
	return 0;
}