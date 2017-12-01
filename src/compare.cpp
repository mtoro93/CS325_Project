#include <stdio.h>
#include <assert.h>
#include <cmath>
#include "compare.hpp"

/*
 if left < right return -1
 if left > right return 1
 if left = right return 0
 */
int compare(struct city* left, struct city* right, int threshold)
{
	int leftInt;
	int leftInt2;
	int rightInt2;
	int rightInt;
	leftInt = (left)->cityXCoord; 
	leftInt2 = (left)->cityYCoord;
	rightInt = (right)->cityXCoord;
	rightInt2 = (right)->cityYCoord;
		
	//-1 for left less than right, 0 for equals, 1 for greater than
	if (sqrt(pow(rightInt - leftInt,2) + pow(leftInt2-rightInt2,2)) > threshold ) 
		return -1;
	else if (pow(rightInt, 2) + pow(rightInt2, 2) == pow(leftInt, 2) + pow(leftInt2, 2))
		return 0;
	else
		return 1;
}

int compareID(struct city* left, struct city* right)
{
	int leftInt;
	int rightInt;
	leftInt = (left)->cityID;
	rightInt = (right)->cityID;

	//-1 for left less than right, 0 for equals, 1 for greater than
	if (rightInt > leftInt) 
		return -1;
	else if (rightInt == leftInt)
		return 0;
	else
		return 1;
}

/*Define this function, type casting the value of void * to the desired type*/
void print_type(struct city* curval)
{
	printf("CityID:%d\n", curval->cityID);
	printf("X:%d\n",curval->cityXCoord);
	printf("Y:%d\n\n", curval->cityYCoord);
	
}


