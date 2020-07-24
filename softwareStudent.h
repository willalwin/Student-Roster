/* -----------------------------------------------------------------------------
FILE:              softwareStudent.h

DESCRIPTION:       Header file for softwareStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14           V1
----------------------------------------------------------------------------- */
#pragma once
#include "student.h"
#include "degree.h"

class softwareStudent : public Student {
	protected:
		//	enum data type
		Degree d = SOFTWARE;
	public:
		softwareStudent();//default constructor
		softwareStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d);//overloaded constructor 
		~softwareStudent();//destructor
		Degree getDegreeProgram();//gets enum data
		void print();//virtual print from student class

};