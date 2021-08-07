#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//constrcture a type name "Number" represent a fration that have two part
typedef struct 
{
	int numerator;
	int denominator;
}Number;

void Find_Stern_Brocot_Number(Number F)
{
	Number L, R, M;
	//initial value
	L.numerator = 0;
	L.denominator = 1;
	M.numerator = 1;
	M.denominator = 1;
	R.numerator = 1;
	R.denominator = 0;

	long double Fd = F.numerator / (long double)F.denominator; //input fraction number
	long double Md = M.numerator / (long double)M.denominator; //calculate we want number
	
	/* Rule 
		F>M: L=M, M = M+R
		F<M: R=M, M = M+L
	*/
	//until get we wanted number
	while (!(M.denominator == F.denominator && M.numerator == F.numerator)) {
		//F>M: L=M, M = M+R
		if (Fd > Md)
		{
			L.numerator = M.numerator;
			L.denominator = M.denominator;
			M.numerator = M.numerator + R.numerator;
			M.denominator = M.denominator + R.denominator;
			printf("R");
		}
		// F<M: R=M, M = M+L
		else
		{
			R.numerator = M.numerator;
			R.denominator = M.denominator;
			M.numerator = M.numerator + L.numerator;
			M.denominator = M.denominator + L.denominator;
			printf("L");
		}
		//update Md
		Md = M.numerator / (long double)M.denominator;
	}
};

int main() 
{
	while (1)
	{
		int input_numerator;
		int input_denominator;

		if (scanf("%d", &input_numerator) != 0) {};
		if (scanf("%d", &input_denominator) != 0) {};
		
		//construction a number F with input
		Number F;
		F.numerator = input_numerator;
		F.denominator = input_denominator;

		if (input_numerator == 1 && input_denominator == 1) // break condition
			break;
		else // call function
			Find_Stern_Brocot_Number(F);
		printf("\n");
	}
	return 0;
}

