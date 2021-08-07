#include <vector>
#include <algorithm>
using namespace std;

// Time Complexity: O(n)
int Max_SubarrayDP(vector<int> &data) 
{
	if (data.size() > 0)
	{
		// initialize max_value = data[0] & now_value = data[0]
		int max_val = data[0];
		int now = data[0];

		for (int i = 1; i < data.size(); i++) 
		{
			// check if data[i] > now_value than data[i] is bigger than now_value(current max)
			if (data[i] > now + data[i])
				now = data[i];
			else
				now = data[i] + now;
			
			// compare now_value & max_value
			if (now > max_val)
				max_val = now;
		}
		return max_val;
	}
}

int cross_middle(vector<int> &data) 
{
	int middle = data.size() / 2;
	int left_sum = 0, right_sum = 0, left_max = INT_MIN, right_max = INT_MIN;
	for (int i = middle - 1; i >= 0; i--)
	{
		left_sum += data[i];
		if (left_sum > left_max)
			left_max = left_sum;
	}
	for (int i = middle; i < data.size(); i++)
	{
		right_sum += data[i];
		if (right_sum > right_max)
			right_max = right_sum;
	}
	return left_max + right_max;
}

// Time Complexity: O(nlogn)
int Max_Subarray(vector<int> &data)
{
	if (data.size() == 1)
		return data[0];
	
	int left, right, cross;
	vector<int> Ldata, Rdata;
	Ldata.assign(data.begin(), data.begin() + data.size() / 2);
	Rdata.assign(data.begin() + data.size() / 2, data.end());

	left = Max_Subarray(Ldata);
	right = Max_Subarray(Rdata);
	cross = cross_middle(data);
	if (left > right && left > cross)
		return left;
	else if (right > left && right > cross)
		return right;
	else
		return cross;
}

int main() 
{
	vector<int> data = { 5,-7,-1,2,3,-1,2,-3 };
	vector<int> data2 = { -1,2,3,-4,5,10 };
	vector<int> data3 = { -2,1,-3,4,-1,2,1,-5,4 };
	Max_Subarray(data3);
}