/* **************************
 File Name: Book2Page111Number4.c
 Author:   Peter Huynh, Andres Torrez
 Last Mod: 03 - 25 - 2011
************************** */

#include<stdio.h>
#include<math.h>

int a;
int b;
float c;

int main()
{
  a = 3;
  b = 4;
  a =(a*a);
  b =(b*b);
  c = a+b;
  c = sqrt(c);

  printf("a and b are %d and %d", a, b);
  printf("c = %f",c);

  return 0;
}
