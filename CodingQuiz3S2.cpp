/* **************************
 File Name: CodingQuiz3S2.cpp
 Author:   Peter Huynh
 Last Mod: 11 - 28 - 2011
************************** */

#include <stdio.h>
#include <math.h>
#include <iostream>
#include <cstring>
using namespace std;

class Student
{
  private:
    char firstName[20];
    char lastName[20];
    int id;

  public:
	Student();
    ~Student();
    void SetName(char* firstName, char* lastName);
    void SetId(int id);
	void Display(void)
	{
      cout << "Student Name: " << firstName << " " << lastName << endl << "ID: " << id << endl;
	};
};

Student::Student()
{
  strcpy(firstName, "Jonh");
  strcpy(lastName, "Smith");
  id = 150306;
};

Student::~Student(){};

int main()
{
  Student John;
  John.Display();
};
