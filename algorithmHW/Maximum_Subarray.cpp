#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int Find_Max_Crossing_Subarray(int A[], int head, int mid, int tail) 
{
	int left_sum = INT_MIN; //maximum  of array's left part
	int right_sum = INT_MIN; //maximum of array's right part
	int total_sum = 0; //maximum of array

	//find the left_sum from head to mid
	for (int i = mid; i >= head; i--) 
	{
		total_sum = total_sum + A[i]; //now total_sum
		if (total_sum > left_sum) 
			left_sum = total_sum;
	}

	//find the right_sum from mid+1 to tail
	total_sum = 0; 
	for (int j = mid + 1; j <= tail; j++) 
	{
		total_sum = total_sum + A[j]; //now total_sum
		if (total_sum > right_sum)
			right_sum = total_sum;
	}
	//cross_sum = left_sum + right_sum
	return left_sum + right_sum;
}

int Find_Maximum_Subarray(int A[], int head, int tail)
{
	int left_sum = INT_MIN;
	int right_sum = INT_MIN;
	int cross_sum = INT_MIN;

	//base case:only one element
	if (head == tail)
		return A[head];
	else //others case:element > 1
	{
		int mid = (head + tail) / 2; //find the middle index
		left_sum = Find_Maximum_Subarray(A, head, mid); // find the maximum of left sum
		right_sum = Find_Maximum_Subarray(A, mid + 1, tail); // find the maximum of right sum
		cross_sum = Find_Max_Crossing_Subarray(A, head, mid, tail); // find the maximum of cross sum
	}

	if ((left_sum >= right_sum) && (left_sum >= cross_sum)) //left_sum is maximum
		return left_sum;
	else if ((right_sum >= left_sum) && (right_sum >= cross_sum)) //right_sum is maximum
		return right_sum;
	else // cross_sum is maximum
		return cross_sum;
}

int main(void) 
{
	int data[50050];
	int data_index = 0; 
	int maximum = INT_MIN; // store the maximum subarray's sum

	while (scanf("%d", &data[data_index]) != EOF) 
		data_index++;

	maximum = Find_Maximum_Subarray(data, 0, data_index - 1);

	printf("%d\n", maximum);
	return 0;
}