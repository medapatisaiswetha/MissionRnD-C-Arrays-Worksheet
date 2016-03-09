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
	struct student **astudent = &students;
	if (students == 0 || len <= 0||k<=0)
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
					temp = *astudent[j];
					students[j] = *astudent[i];
					*astudent[i] = temp;
				}
			}
		}
	}
	if (k == 1)
	{
		return &astudent[0];
	}
	else if (k > len)
	{
		return &astudent[0];
	}
	else if (k < len)
	{
		for (int i = k; i >=0; i--)
		{
			for (int j = (len - 1 - k); j >= 0; j--)
			{
				return &astudent[j];
			}
		}
	}
}