#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int Fibonacci(int n)
{
	int first_value = 1;
	int second_value = 0;
	int now_value = 0;
	int i;

	for (i = 1; i < n; i++)
	{
		second_value = first_value;
		first_value = now_value;
		now_value = second_value + first_value;
	}
	return now_value;
}

int main() 
{
	int n;
	cout << "input a number of Fibonacci: ";
	cin >> n;
	cout << Fibonacci(n) << "\n";
	system("pause");
}

