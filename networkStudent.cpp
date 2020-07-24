/* -----------------------------------------------------------------------------
FILE:              networkStudent.cpp

DESCRIPTION:       Implementation file for networkStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14           V1
----------------------------------------------------------------------------- */

#include "student.h"
#include "networkStudent.h"
#include "degree.h"

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     networkStudent::networkStudent()

PURPOSE:           Default constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
networkStudent::networkStudent() {
	this->d = NETWORKING;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     networkStudent::networkStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)

PURPOSE:           Overloaded constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
networkStudent::networkStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d)
{
	this->studentID = studentID;
	this->fname = fname;
	this->lname = lname;
	this->email = email;
	this->age = age;
	for (int i = 0; i < 3; i++) { this->numDaysToComplete[i] = numDaysToComplete[i]; }
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     ~networkStudent::networkStudent()

PURPOSE:           Default destructor from student class

RETURNS:           No Return value
----------------------------------------------------------------------------- */
networkStudent::~networkStudent() { Student::~Student();}//destructor

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     networkStudent::getDegreeProgam()

PURPOSE:           getter for enum data type

RETURNS:           enum Degree
----------------------------------------------------------------------------- */
Degree networkStudent::getDegreeProgram() {
	return this->d;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     networkStudent::print()

PURPOSE:           virtual print function from Student class that has been overridden to add enum data type

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void networkStudent::print() {
	this->Student::print();//call superclass print function
	cout << "\tDegree program: Networking" << endl;
}