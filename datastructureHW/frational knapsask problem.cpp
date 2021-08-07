#include<iostream> 
#include<vector>
#include<algorithm> // use "sort" method
#include<fstream> // use with file input
using namespace std;

// construct a self-define class name "Item" 
class Item 
{
public:
	Item() {} // constructer
	Item(float v,float w) // constructer with value & weight
	{
		value = v;
		weight = w;
	}
	float value;
	float weight;
	float cp;
};

// compare function use with "SORT" method
bool compare(Item a, Item b) 
{
	return a.cp > b.cp;
}

void fraction_knapsack(vector<Item> bag, float W) 
{
	// count the everything's cp value 
	// mean that cp = value/weight
	for (int i = 0; i < bag.size(); i++) 
		bag[i].cp = bag[i].value / bag[i].weight;
	
	//sorting the bag item decresing with it's cp
	sort(bag.begin(), bag.end(), compare);
	int i = 0;
	float max = 0; // the sum with now status

	// loop when bag's weight still > 0
	while (W > 0) 
	{
		// case 1. this item can all take in bag
		if (W - bag[i].weight >= 0)
			max += bag[i].value;
		// case 2. this item can just take fraction
		else 
			max += bag[i].cp * W;
		// remain_weight = before_weight - this item's weight
		W -= bag[i].weight;
		i++;
	}
	// cout << "max: " << max << "\n";
}

void zero_one_knapsack(vector<Item> bag, float W) 
{
	// simulate two bounding
	// case1 : we don't take any item
	// case2 : compute if bag's weight is 0
	Item i0(0, 0);
	bag.insert(bag.begin(), i0);

	// declear 2-dimension vector and initalize it's size
	vector<vector<int>> DP(bag.size(), vector<int>(W + 1));
	

	// for bounding with "we don't take any item"
	for (int k = 0; k < W; k++) 
		DP[0][k] = 0;

	for (int i = 1; i < bag.size(); i++) 
	{
		// for bounding with our bag's maximum weight is 0
		DP[i][0] = 0;

		// bag's weight from 1 to W
		for (int j = 1; j <= W; j++) 
		{
			if (j < bag[i].weight) //can't take this item
			{
				DP[i][j] = DP[i - 1][j];
			}
			else // try to throw something let weight can take this item. And compare which have max profit 
				DP[i][j] = max(DP[i - 1][j], (int)bag[i].value + DP[i - 1][j - bag[i].weight]);
		}
	}

	 cout << "max: " << DP[bag.size() - 1][W];
}
void input_dataset(vector<Item> &bag) 
{
	fstream file1,file2;
	file1.open("p08_w.txt", ios::in);
	file2.open("p08_p.txt", ios::in);
	
	float temp_w,temp_p;
	while (file1 >> temp_w && file2 >> temp_p)
	{
		bag.push_back(Item(temp_w, temp_w));
	}
}

int main() 
{
	vector<Item> bag;
	input_dataset(bag);
	float bag_capacity = 6404180;
	//fraction_knapsack(bag, bag_capacity);
	zero_one_knapsack(bag, bag_capacity);
}