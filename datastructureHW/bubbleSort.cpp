#include <vector>
#include <iostream>
using namespace std;

// implement BUBBLE_SORT method

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
void printArray(vector<int> data) 
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << ",";
	cout << "\n";
}

void main() 
{
	vector<int> data = {8,2,5,7,4};
	
	cout << "initial data: ";
	printArray(data);

	for (int i = 0; i < data.size(); i++) 
	{
		for (int j = 0; j < data.size() - i - 1; j++) 
		{
			if (data[j] > data[j + 1])
				swap(data[j], data[j + 1]);
		}
		cout << "round " << i << ": \n";
		printArray(data);
	}

	cout << "after sorted: ";
	printArray(data);

	system("pause");
}