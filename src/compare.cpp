#include <stdio.h>
#include <assert.h>
#include <cmath>
//#include "bst.hpp"
#include "compare.hpp"

/*----------------------------------------------------------------------------
 very similar to the compareTo method in java or the strcmp function in c. it
 returns an integer to tell you if the left value is greater then, less then, or
 equal to the right value. you are comparing the number variable, letter is not
 used in the comparison.

 if left < right return -1
 if left > right return 1
 if left = right return 0
 */

 /*Define this function, type casting the value of void * to the desired type.
  The current definition of TYPE in bst.h is void*, which means that left and
  right are void pointers. To compare left and right, you should first cast
  left and right to the corresponding pointer type (struct data *), and then
  compare the values pointed by the casted pointers.

  DO NOT compare the addresses pointed by left and right, i.e. "if (left < right)",
  which is really wrong.
 */
int compare(struct city* left, struct city* right, int threshold)
{
	int leftInt;
	int leftInt2;
	int rightInt2;
	int rightInt;
	leftInt = (left)->cityXCoord; //cast to data, then use the number values as ints
	leftInt2 = (left)->cityYCoord;
	rightInt = (right)->cityXCoord;
	rightInt2 = (right)->cityYCoord;
		
	if (sqrt(pow(rightInt - leftInt,2) + pow(leftInt2-rightInt2,2)) > threshold ) //-1 for left less than right, 0 for equals, 1 for greater than
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
	leftInt = (left)->cityID; //cast to data, then use the number values as ints
	rightInt = (right)->cityID;

	if (rightInt > leftInt) //-1 for left less than right, 0 for equals, 1 for greater than
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


