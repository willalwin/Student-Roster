/* -----------------------------------------------------------------------------
FILE:              softwareStudent.cpp

DESCRIPTION:       Implementation file for softwareStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14           V1
----------------------------------------------------------------------------- */

#include "student.h"
#include "softwareStudent.h"
#include "degree.h"

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     softwareStudent::softwareStudent()

PURPOSE:           Default constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
softwareStudent::softwareStudent() {
	this->d = SOFTWARE;
}
/*   ---------------------------------------------------------------------------
FUNCTION NAME:     softwareStudent::softwareStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)

PURPOSE:           Overloaded constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
softwareStudent::softwareStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)
{
	this->studentID = studentID;
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) { this->numDaysToComplete[i] = numDaysToComplete[i]; }
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     ~softwareStudent::softwareStudent()

PURPOSE:           Default destructor from student class

RETURNS:           No Return value
----------------------------------------------------------------------------- */
softwareStudent::~softwareStudent() { Student::~Student();}//destructor

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     softwareStudent::getDegreeProgam()

PURPOSE:           getter for enum data type

RETURNS:           enum Degree
----------------------------------------------------------------------------- */
Degree softwareStudent::getDegreeProgram() {
	return this->d;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     softwareStudent::print()

PURPOSE:           virtual print function from Student class that has been overridden to add enum data type

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void softwareStudent::print() {
	this->Student::print();//call superclass print function
	cout << "\tDegree program: Software" << endl;
}