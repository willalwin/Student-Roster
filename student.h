/*---------------------------------------------------------------------------
FILE:              student.h

DESCRIPTION:       Header file for student class

COMPILER:          Visual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-7           V1
----------------------------------------------------------------------------- */
#pragma once
#include "degree.h"
#include <iostream>
using namespace std;

class Student {

protected:
	//Student object variables
	string studentID;
	string fname;
	string lname;
	string email;
	int age;
	int numDaysToComplete[3];
    Degree d;

public:
	Student(); //default constructor
	virtual ~Student(); //destructor

	//setters
	void setStudentID(string studentID);
	void setFirstName(string fname);
	void setLastName(string lname);
	void setEmail(string email);
	void setAge(int age);
	void setDaysToComplete(int numDaysToComplete[]);
	void setDegree(Degree d);

	//getters
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmail() const;
	int getAge() const;
	int getDaysToComplete(int i) const;

	//virtual functions
	virtual Degree getDegreeProgram() = 0;//virtual function not defined in base class
	virtual void print();//base print function, gets overridden in sub-classes
};