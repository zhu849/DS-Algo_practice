#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

vector<int> other_sort(vector<int> &data)
{
	int i, j;
	for (i = 0; i < data.size(); i++)
	{
		int min_index = i;
		for (j = i + 1; j < data.size(); j++)
		{
			if (data[min_index] > data[j])
				min_index = j;
		}
		swap(data[i], data[min_index]);
	}
	return data;
}

int find_pivot(vector<int> &data,int p,int r)
{
	vector<int> temp;
	vector<int> group;

	for (int i = p; i <= r; i+=5)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i + j <= r)
				temp.push_back(data[i+j]);
		}
		other_sort(temp);
		group.push_back(temp[temp.size()/2]);
		temp.clear();
	}
	return group[group.size()/2];
}

// sort from data[p] to data[r]
int partition(vector<int> &data, int p, int r)
{
	int pivot;
	//find the median of median
	pivot = find_pivot(data, p, r);

	int i = p - 1;
	int j;
	for (j = p; j < r; j++) 
	{
		if (data[j] < pivot)
		{
			i++;
			swap(data[j], data[i]);
		}
	}
	swap(data[i + 1], data[r]);
	return i + 1;
}

void my_qsort(vector<int> &data, int p, int r)
{
	int q; // pivot's position
	if (p < r) 
	{
		q = partition(data, p, r); // sort_total by key
		my_qsort(data, p, q - 1); // sort_left
		my_qsort(data, q + 1, r); // sort_right
	}
}

void print_result(vector<int> data)
{
	int i;
	for (i = 0; i < data.size(); i++)
		cout << data[i] << "  ";

	cout << "\n";
}

int main()
{
	vector<int> data = { 4,3,8,1,0,9,5,2,6,7 };
	my_qsort(data, 0, data.size() - 1);
	print_result(data);
}