#include <vector>
#include <iostream>
using namespace std;

// implement INSERTION_SORT method

void printArray(vector<int> data)
{
	for (int i = 0; i < data.size(); i++)
		cout << data[i] << ",";
	cout << "\n";
}

void main()
{
	vector<int> data = { 8,2,5,7,4 };

	cout << "initial data: ";
	printArray(data);
	
	int temp;
	for (int i = 1; i < data.size(); i++)
	{
		temp = data[i];
		int j = i-1;
		while (j >= 0 && data[j] > temp)
		{
			data[j + 1] = data[j];
			j--;
		}
		data[j+1] = temp;
	
		cout << "round " << i << ": \n";
		printArray(data);
	}

	cout << "after sorted: ";
	printArray(data);

	system("pause");
}