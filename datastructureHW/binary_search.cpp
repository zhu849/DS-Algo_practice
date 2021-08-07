#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> data , int search_data)
{
	int middle;
	int left = 1;
	int right = data.size() - 1;
	int times = 0;

	while (left <= right) 
	{
		times++;
		middle = (left + right) / 2;
		if (search_data == data[middle])
			return middle;
		else if (search_data > data[middle])
			left = middle + 1;
		else
			right = middle - 1;
	}

	return -1; // mean not search
}

int binary_search_recursive(vector<int> data, int left, int right, int search_data, int &times)
{
	times++;
	int middle = (left + right) / 2;
	if (left > right)
		return -1;
	if (search_data == data[middle])
		return middle;
	else if (search_data > data[middle])
		return binary_search_recursive(data, left + 1, right, search_data, times);
	else
		return binary_search_recursive(data, left, middle - 1, search_data, times);
}

int main() 
{
	vector<int> data = { NULL, 4,9,10,12,18,23,29,33,48,52 };
	sort(data.begin(), data.end());
	int search_data = 13;
	int search_data_index;
	int times = -1;

	search_data_index = binary_search(data, search_data);
	binary_search_recursive(data, 1, data.size() - 1, search_data, times);
}