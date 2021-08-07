#include <iostream>
#include <vector>
using namespace std;

 // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		int sum = 0;
		if (!root) return sum;
		
		if(root->val > L)
			sum += rangeSumBST(root->left, L, R);
		if(root->val < R)
		sum += rangeSumBST(root->right, L, R);

		if (root->val >= L && root->val <= R)
			return sum + root->val;
		else
			return sum;
	}
};

TreeNode* buildTree(vector<int> &data,TreeNode *parent, int index)
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
		if(data[index * 2 - 1] != NULL)
			parent->left = new TreeNode(data[index * 2 -1]);
		buildTree(data, parent->left, index * 2);
	}
	// have right child
	if ((index * 2) < data.size() )
	{
		if (data[index * 2] != NULL)
			parent->right = new TreeNode(data[index * 2]);
		buildTree(data, parent->right, index * 2 + 1);
	}
	return parent;
}


int main()
{
	Solution test;
	vector<int> data = { 10,5,15,3,7,13,18,1,NULL,6 };
	TreeNode *p = NULL;
	p = buildTree(data, p, 1);
	cout << test.rangeSumBST(p, 6, 10);
}