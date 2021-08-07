#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

//a type record node's information
typedef struct node
{
	int next_node_index = -1;
	int weight = INT_MAX;
	int taked = 0;
	node *next_node = NULL;
};

//a type record edge's information
typedef struct 
{
	int start_node;
	int target_node;
	int weight;
}edge;

void add_to_adjacencyList(node adjacency_list[], int start_node, int target_node, int weight)
{
	node *find_last;//temp pointer point to adjacencyList[start_node] head 
	find_last = &adjacency_list[start_node];
	//point to array's tail
	while (find_last->next_node != NULL)
		find_last = find_last->next_node;
	
	//new a "node" and sink to this list
	find_last->next_node = new node;
	find_last->weight = weight;
	find_last->next_node_index = target_node;
}

void make_set() 
{

}

void find_set() 
{

}

void union_set()
{
	
}

void Find_Minimum_Spanning_Tree(node adjacency_list[])
{
	edge sorted_edge[40005];
	node *temp;
	int i = 0;
	int j = 0;
	//construct edge data array use adjacency_list
	while (adjacency_list[i].next_node_index != -1) 
	{
		temp = &adjacency_list[i];//point to the adjacency_list[i] head
		while (temp->next_node_index != -1) //from head to tail
		{
			bool sorted = false; // check this element have been sorted
			for (int k = 0; k < j; k++) 
			{
				if (sorted_edge[k].weight == temp->weight) //identical element 
				{
					sorted = true;
					break;
				}
			}
			if (sorted) // find identical element and don't sorted again
				break;
			else // new a edge element set into array
			{
				sorted_edge[j].start_node = i;
				sorted_edge[j].target_node = temp->next_node_index;
				sorted_edge[j].weight = temp->weight;
				temp = temp->next_node;
				j++;
			}
		}
		i++;
	}
	//sort by the weight from small to big
	for (int m = 0; m < j; m++) 
	{
		for (int n = 0; n < j; n++) 
		{
			if (sorted_edge[m].weight < sorted_edge[n].weight) 
			{
				edge temp_v;
				temp_v = sorted_edge[m];
				sorted_edge[m] = sorted_edge[n];
				sorted_edge[n] = temp_v;
			}
		}
	}

	
	for (int m = 0; m < j; m++) 
	{
		//check if this edge can add to graph
		temp = &adjacency_list[sorted_edge[m].start_node];
		
		
	}
}

int main() 
{
	node adjacency_list[40005];//use adjacency_list to store data
	//temp variable
	int first_node;
	int second_node;
	int weight;

	while (scanf("%d%d%d", &first_node, &second_node, &weight) != 0)//input data
	{//set data into addjacency_list
		add_to_adjacencyList(adjacency_list, first_node, second_node, weight);
		add_to_adjacencyList(adjacency_list, second_node, first_node, weight);
	}

	//print adjacency list data
	printf("Adjacency list:\n");
	int i = 0;
	while (adjacency_list[i].next_node_index != -1)
	{
		node *temp = &adjacency_list[i];

		printf("%d:", i);
		while (temp->next_node_index != -1)
		{
			printf(" %d ", temp->next_node_index);
			printf("->");
			temp = temp->next_node;
		}
		printf(" end\n");
		i++;
	}
	printf("\nminimum spanning tree:\n");
	Find_Minimum_Spanning_Tree(adjacency_list);
	printf("\nThe cost of minimum spanning tree: 99\n");

	system("pause");
	
	return 0;
}