#include<iostream>
#include<vector>
using namespace std;

void rod_cut(vector<int> price, int n) 
{
	vector<int> best_cost, cut;
	best_cost.push_back(0);
	cut.push_back(0);

	for (int i = 1; i <= n; i++) 
	{
		int now_max = INT_MIN;
		int now_cut = 0;
		for (int j = 1; j <= i; j++) 
		{
			if (now_max < price[j] + best_cost[i - j]) 
			{
				now_max = price[j] + best_cost[i - j];
				now_cut = j;
			}
		}
		best_cost.push_back(now_max);
		cut.push_back(now_cut);
	}
	cout << "best_cost: " << best_cost[n] << "\n";
	cout << "cut_position: " << cut[n] << "\n";
}
 
int main() {
	vector<int> price = {0,1,3,8,8,9,10,18,18,23,25 };
	rod_cut(price, 10);
}