#include <vector>
#include <iostream>
using namespace std;

// implement SELECTION_SORT method

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
	vector<int> data = { 8,2,5,7,4 };

	cout << "initial data: ";
	printArray(data);

	for (int i = 0; i < data.size(); i++)
	{
		int min_index = i;
		for (int j = i + 1; j < data.size(); j++) 
		{
			if (data[min_index]> data[j])
				min_index = j;
		}
		swap(data[i], data[min_index]);
		cout << "round " << i << ": \n";
		printArray(data);
	}

	cout << "after sorted: ";
	printArray(data);

	system("pause");
}