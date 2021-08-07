#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

//define a new type "object" to store 3 attribute value, weight and cp
typedef struct 
{
	double value;
	double weighs;
	double cp;
}object;

void Fractional_Knapack(object Obj[],int length, int capacity) 
{
	int load = 0;//now bag load
	int i = 0;//index count
	double value_sum = 0; // now total value sum

	while (load < capacity && i < length) 
	{
		//take all item
		if (Obj[i].weighs <= capacity - load) 
		{
			value_sum += Obj[i].value;
			load += Obj[i].weighs;
		}
		//take fraction item
		else 
		{
			int remain_capacity = capacity - load;
			value_sum += remain_capacity * Obj[i].cp;
			load += remain_capacity;
		}
		i++;
	}
	printf("%.6f\n", value_sum);
}

//sort the array cp by high cp to low cp
void Sort_Array(object Obj[],int n) 
{
	for (int j = 0; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (Obj[j].cp > Obj[i].cp)
				//swap
			{
				object temp;
				temp = Obj[j];
				Obj[j] = Obj[i];
				Obj[i] = temp;
			}
		}
	}
}

int main() 
{
	int capacity;
	object Obj[40010];

	int i = 0; //index of Obj[]

	if (scanf("%d", &capacity)) {};
	while (scanf("%lf%lf", &Obj[i].value, &Obj[i].weighs) != EOF) // scanf double should always use %lf
		i++;
	//count the cp attribute from Obj[]
	for (int j = 0; j < i; j++)
		Obj[j].cp = Obj[j].value / Obj[j].weighs;
	//sort the Obj by cp
	Sort_Array(Obj, i);
	//call function
	Fractional_Knapack(Obj, i, capacity);

	return 0;
}