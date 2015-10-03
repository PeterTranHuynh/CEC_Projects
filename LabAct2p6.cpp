/* **************************
File Name: Number 1.cpp
Author:   Peter Huynh, Frank Skora, Andres Torrez
Last Mod: March 23, 2011
************************** */
#include <stdio.h>

int Greater(int, int); 
int Lesser(int, int);
int Average(int, int);

int a = 1;
int b = 4;

int Greater(int a, int b)
{
	if(a>b)
	return a;
	else
	return b;
};

int Lesser(int a, int b)
{
	if(a<b)
	return a;
	else
	return b;
};

int Average(int a, int b)
{
	return (a + b / 2);
};

int main(void)
{

	printf("Greater: %d\n", Greater(a,b));
	printf("Lesser: %d\n", Lesser(a,b));
	printf("Average: %d\n", Average(a,b));
};

