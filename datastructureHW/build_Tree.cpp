#include <vector>
#include <iostream>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* buildTree(vector<int> &data, TreeNode *parent, int index)
{
	// construct root
	if (index == 1)
	{
		if (data.size() > 0)
			parent = new TreeNode(data[0]);
	}


	// have left child
	if ((index * 2 - 1) < data.size())
	{
		if (data[index * 2 - 1] != NULL)
			parent->left = new TreeNode(data[index * 2 - 1]);
		buildTree(data, parent->left, index * 2);
	}
	// have right child
	if ((index * 2) < data.size())
	{
		if (data[index * 2] != NULL)
			parent->right = new TreeNode(data[index * 2]);
		buildTree(data, parent->right, index * 2 + 1);
	}
	return parent;
}

int main() 
{
	TreeNode *p(NULL);
	vector<int> data = { 2,5,8,3,7,9,10,6 };
	p = buildTree(data, p, 1);
}