/* -----------------------------------------------------------------------------
FILE:              securityStudent.h

DESCRIPTION:       Header file for securityStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14          V1
----------------------------------------------------------------------------- */
#pragma once
#include "student.h"
#include "degree.h"

class securityStudent : public Student {
	protected:
		//enum data type
		Degree d = SECURITY;
	public:
		securityStudent();//default constructor
		securityStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d);//overloaded constructor
		~securityStudent();//destructor
		Degree getDegreeProgram();//gets enum data
		void print();//virtual print from Student class

};