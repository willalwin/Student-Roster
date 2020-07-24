/* -----------------------------------------------------------------------------
FILE:              securityStudent.cpp

DESCRIPTION:       Implementation file for securityStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14           V1
----------------------------------------------------------------------------- */

#include "student.h"
#include "securityStudent.h"
#include "degree.h"

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     securityStudent::securityStudent()

PURPOSE:           Default constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
securityStudent::securityStudent() {
	this->d = SECURITY;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     securityStudent::securityStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)

PURPOSE:           Overloaded constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
securityStudent::securityStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)
{
	this->studentID = studentID;
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) { this->numDaysToComplete[i] = numDaysToComplete[i]; }
}
/*   ---------------------------------------------------------------------------
FUNCTION NAME:     ~securityStudent::securityStudent()

PURPOSE:           Default destructor from student class

RETURNS:           No Return value
----------------------------------------------------------------------------- */
securityStudent::~securityStudent() { Student::~Student();}//destructor

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     securityStudent::getDegreeProgam()

PURPOSE:           getter for enum data type

RETURNS:           enum Degree 
----------------------------------------------------------------------------- */
Degree securityStudent::getDegreeProgram() {
	return this->d;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     securityStudent::print()

PURPOSE:           virtual print function from Student class that has been overridden to add enum data type

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void securityStudent::print() {
	this->Student::print();//call superclass print function
	cout << "\tDegree program: Security" << endl;
}