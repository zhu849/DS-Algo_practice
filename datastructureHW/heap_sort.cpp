#include <vector>
using namespace std;

void adjust_max(vector<int> &data, int root_index, int n)
{
	// n is dataSize
	// adjust sub tree with point index "root_index"
	int now_value = data[root_index];
	int j = 2 * root_index; // j is left child's index
	// if left_child's index still <= dataSize 
	while (j <= n)
	{
		//choice left and right child who is bigger
		// if right child exist
		if (j + 1 <= n)
		{
			if (data[j] < data[j + 1])
				j++;
		}

		// now_value is bigger than child
		if (now_value > data[j])
			break;
		else
		{
			data[j / 2] = data[j];
			j *= 2;
		}
	}
	data[j / 2] = now_value;
}

void adjust_min(vector<int> &data, int root_index, int n)
{
	// adjust sub tree with point index "root_index"
	int now_value = data[root_index];
	int j = 2 * root_index;
	while (j <= n)
	{
		//choice left and right child who is smaller
		// if right child exist
		if (j + 1 <= n)
		{
			if (data[j] > data[j + 1])
				j++;
		}

		// now_value is smaller than child
		if (now_value < data[j])
			break;
		else
		{
			data[j / 2] = data[j];
			j *= 2;
		}
	}
	data[j / 2] = now_value;
}

// build Min Heap
void build_min_Heap(vector<int> &data, int dataSize)
{
	for (int i = (dataSize - 1) / 2; i > 0; i--)
		adjust_min(data, i, dataSize - 1);
}

// build Max Heap
void build_max_Heap(vector<int> &data, int dataSize)
{
	for (int i = (dataSize - 1) / 2; i > 0; i--)
		adjust_max(data, i, dataSize - 1);
}

void swap(int &a, int &b) 
{
	int temp; 
	temp = a;
	a = b;
	b = temp;
}

void heap_sort(vector<int> &data, int dataSize)
{
	for (int i = dataSize - 1; i > 0; i--) 
	{
		swap(data[i], data[1]);
		adjust_max(data, 1, i - 1);
	}
}

int main()
{
	//沒過 要再修
	vector<int> data = { NULL,16,5,33,17,25,19,40,50,8,28 };
	vector<int> data2 = { NULL,5,3,2,1,7,8,9,10 };
	vector<int> data3 = { NULL,2,5,8,3,7,9,10,6 };
	vector<int> data4 = { NULL,2,5,8,3,7,9,10 };

	//build_max_Heap(data, data.size()); // 50, 28, 40, 17, 25, 19, 33, 5, 8, 16
	build_max_Heap(data2, data2.size()); // 10, 7, 9, 3, 5, 8, 2, 1
	//build_max_Heap(data3, data3.size()); // 10, 7, 9 ,6 ,5 ,2 ,8 ,3
	build_max_Heap(data4, data4.size()); // 10, 7, 9, 3, 5, 2, 8
	heap_sort(data2, data2.size());
	heap_sort(data4, data4.size());
}