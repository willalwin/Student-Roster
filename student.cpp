/* -----------------------------------------------------------------------------
FILE:              student.cpp

DESCRIPTION:       Implementation file for student class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-7           V1
----------------------------------------------------------------------------- */

#include "student.h"

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     student::student()

PURPOSE:           Default constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
Student::Student(){
	this->studentID = "none";
	this->fname = "none";
	this->lname = "none";
	this->email = "none";
	this->age = 0;
	this->numDaysToComplete[0] = 0;
	this->numDaysToComplete[1] = 0;
	this->numDaysToComplete[2] = 0;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     student::~student()

PURPOSE:           student destructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
Student::~Student() {}

/*------------------------------------------------------------------------------
FUNCTION GROUP:     student setters()

PURPOSE:           set values for student class

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string fname) {
	this->fname = fname;
}
void Student::setLastName(string lname) {
	this->lname = lname;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setDaysToComplete(int numDaysToComplete[]) {
	int i;
	for (i = 0; i < 3; i++) {
		this->numDaysToComplete[i] = numDaysToComplete[i];
	}
}
void Student::setDegree(Degree d){
	this->d = d;
}

/*------------------------------------------------------------------------------
FUNCTION GROUP:     student getters()

PURPOSE:           get values for student class

RETURNS:           Returns data type of each value
----------------------------------------------------------------------------- */
string Student::getStudentID() const {
	return this->studentID;
}
string Student::getFirstName() const {
	return this->fname;
}
string Student::getLastName() const {
	return this->lname;
}
string Student::getEmail() const {
	return this->email;
}
int Student::getAge() const {
	return this->age;
}
int Student::getDaysToComplete(int i) const {
	return this->numDaysToComplete[i];
}

/*------------------------------------------------------------------------------
FUNCTION NAME:     student::print()

PURPOSE:           prints formatted student class values to screen

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Student::print() {
	cout << endl << this->getStudentID();
	cout << "\tFirst name: " << this->getFirstName();
	cout << "\tLast name: " << this->getLastName();
	cout << "\tAge: " << this->getAge();
	cout << "\t\tDays in course: {" << this->getDaysToComplete(0) << ", " << this->getDaysToComplete(1) << ", " << this->getDaysToComplete(2) << "}";
}