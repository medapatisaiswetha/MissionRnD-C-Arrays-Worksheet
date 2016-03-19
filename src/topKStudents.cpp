/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that returns the names and scores of top K students.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40) and K value is 2.
return top 2 students [ { "stud2", 30 }, { "stud3", 40 } ]

INPUTS: array of structures of type student, length of the array, integer K.

OUTPUT: Return top K students from array. Output need not be in decreasing order of scores.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>
#include <malloc.h>

struct student {
	char *name;
	int score;
};

struct student ** topKStudents(struct student *students, int len, int k)
{
	int l = 0;
	struct student temp;
	struct student **astudent = NULL;
	astudent = (struct student**)malloc(len * sizeof(struct student*));
	if (students == 0 || len <= 0 || k <= 0)
		return NULL;
	else
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (students[i].score>students[j].score)
				{
					continue;
				}
				else if (students[i].score < students[j].score)
				{
					temp = students[j];
					students[j] = students[i];
					students[i] = temp;
				}
			}
		}
	}
	
	for (int i = 0, j = len - 1; i < j && i != j; i++, j--)
	{
		temp = students[j];
		students[j] = students[i];
		students[i] = temp;
	}

	if (k > len)
	{
		for (int i = 0; i < len; i++)
		{
			astudent[i] = &students[i];
		}
		return astudent;
	}
	else
	{
		int start = len - 1, end = len - k, i = 0;
		while (start >= end)
		{
			astudent[i] = &students[start];
			i++;
			start--;
		}
		return astudent;
	}
}