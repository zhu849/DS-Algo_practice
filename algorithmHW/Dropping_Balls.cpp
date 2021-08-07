#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//every time go right is even => let this point be false
//every time go left is odd => let this point be true
int Find_Dropping_Ball_Location(int depth,int nball) // nball mean ith times ball dropping 
{
	int position = 1; //now ball's position index
	int j = 1;
	while (j != depth) 
	{
		//in this position ball select go to right or left
		if (nball % 2 == 0) // right
			position = position * 2 + 1;
		else //left
			position *= 2;
		//let next point be the root to search subtree
		if (nball > 1) 
		{
			if (nball % 2 == 0)
				nball /= 2;
			else
				nball = nball / 2 + 1;
		}
		j++;
	}
	return position;
}

int main() 
{
	int ntime;//how many ball will input to the tree
	if (scanf("%d", &ntime)) {};
	int depth;
	int nball; // ith times ball dropping
	int index; // postion of tree index

	while (1)
	{
		if (scanf("%d", &depth)) {};
		if (depth == -1) // break condition
			break;
		if (scanf("%d", &nball)) {};
		if (depth < 2 || depth > 20 || nball < 1 || nball > 524288) //break condition
			break;
		index = Find_Dropping_Ball_Location(depth, nball);
		printf("%d\n", index);
	}

	return 0;
}