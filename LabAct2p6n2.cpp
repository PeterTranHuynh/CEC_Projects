#include<stdio.h>

  int a;
  int b;
  int Plus(int, int);
  int Subtract(int, int);
  int Multiply(int, int);
  int Divide(int, int);

  int Plus(int, int)
  {
	  int temp;
	  temp=a+b;
	  return temp;
  };
  
  int Subtract(int, int)
  {
	  int temp;
	  temp=a-b;
	  return temp;
  };
  
  int Multiply(int,int)
  {
	  int temp;
	  temp=a*b;
	  return temp;
  };
  
  int Divide(int,int)
  {
	  int temp;
	  temp=a/b;
	  return temp;
  };

int main()
{
  a = 5;
  b = 10;
  printf("a = %d, b = %d\n a + b = %d\n a - b = %d\n a * b = %d\n a / b = %d\n",a,b,Plus(a,b),Subtract(a,b),Multiply(a,b),Divide(a,b));
  return 0;
}