#include <vector>
using namespace std;

void merge(vector<int> &data, int left_index, int middle_index, int right_index)
{
	int n1 = middle_index - left_index + 1; // left_part length
	int n2 = right_index - middle_index; // right_part length

	vector<int> Ldata, Rdata;
	
	// copy left part to Ldata
	if (n1 > 0)
		Ldata.assign(data.begin() + left_index, data.begin() + left_index + n1);
	// copy right part to Rdata
	if (n2 > 0)
		Rdata.assign(data.begin() + middle_index + 1, data.begin() + middle_index + n2 + 1);

	// bounded check data
	Ldata.push_back(INT_MAX);
	Rdata.push_back(INT_MAX);

	int i = 0, j = 0;
	for (int k = left_index; k <= right_index; k++) 
	{
		if (Ldata[i] <= Rdata[j])
		{
			data[k] = Ldata[i];
			i++;
		}
		else 
		{
			data[k] = Rdata[j];				
			j++;
		}
	}
}

void merge_sort(vector<int> &data,int left_index,int right_index) 
{
	if (left_index < right_index)
	{
		int middle_index = (left_index + right_index) / 2;
		merge_sort(data, left_index, middle_index); // divide and counquer left part 
		merge_sort(data, middle_index + 1, right_index); // divide and counquer right part 
		merge(data, left_index, middle_index, right_index); // counquer left and right part
	}
}

int main() 
{
	vector<int> data = { 12, 15, 23, 4 , 6, 10, 35, 28, 100, 130, 500, 1000, 235, 554, 75, 345, 800, 222, 333, 888, 444, 111, 666, 777, 60 };
	int left_index = 0;
	int right_index = data.size() - 1;
	merge_sort(data, left_index, right_index);
}