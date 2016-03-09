/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int temp = 0, temp1 = 0, i, j;
	if (Arr == NULL || len <= 0)
		return NULL;
	else
		Arr = (int*)realloc(Arr, (len + 1)*sizeof(int));
	for (i = 0; i < len; i++)
	{
		if (*(Arr + i) > num)
		{
			temp = *(Arr + i);
			*(Arr + i) = num;
			for (j = i + 1; j < len + 1; j++)
			{
				temp1 = *(Arr + j);
				*(Arr + j) = temp;
				temp = temp1;
			}
			return Arr;
			break;
		}
	}

	if (i == len)
	{
		*(Arr + i ) = num;
		return Arr;
	}

}