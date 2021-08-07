#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void merge(int A[], int head, int mid, int tail)
{
	int n1;//long of L array
	int n2;//long of R array

	n1 = mid - head + 1; 
	n2 = tail - mid;

	//dynamic programming
	int *Larray = (int*)malloc((n1+1) * sizeof(int));
	int *Rarray = (int*)malloc((n2+1) * sizeof(int));
	
	//Larray is left part of merge subarray
	for (int i = 0; i < n1; i++)
		Larray[i] = A[head + i];
	//Rarray is right part of merge subarray
	for (int j = 0; j < n2; j++)
		Rarray[j] = A[mid + j + 1];

	Larray[n1] = INT_MAX; // max boundary value with Larray
	Rarray[n2] = INT_MAX; // max boundary value with Rarray
	
	//initial variable
	int i = 0;//Start i variable with index 0
	int j = 0;//Start j variable with index 0 

	//let A[] be sorted array with range of p to r
	for (int k = head; k <= tail; k++)
	{
		if (Larray[i] <= Rarray[j])
		{
			A[k] = Larray[i];
			i++;
		}
		else //Larray[i] > Rarray[j]
		{
			A[k] = Rarray[j];
			j++;
		}
	}
	//free the memory space with malloc 
	free(Larray);
	free(Rarray);
}

void merge_sort(int A[], int head, int tail)
{
	int mid;
	if (head < tail)
	{
		mid = (head + tail) / 2; // find the middle index
		//the divide into two part use recursive and then have subarray to conqer
		//1.head to mid
		//2.mid to tail
		merge_sort(A, head, mid);//then head to mid will sorted
		merge_sort(A, mid + 1, tail); // then mid to tail will sorted
		merge(A, head, mid, tail); // merge two subarray 
	}
}

int main(void) 
{
	int data[60000];
	int data_index = 0;
	
	//input the data 
	while (scanf("%d", &data[data_index]) != EOF) {
		data_index++;
	}
	if (data_index > 0)//prevent no data input  
	{
		merge_sort(data, 0, data_index-1);		
		//print out the result
		for (int i = 0; i < data_index; i++)	
			printf("%d ", data[i]);
	}
	printf("\n");
	return 0;
}


