/* -----------------------------------------------------------------------------
FILE:              networkStudent.h

DESCRIPTION:       Header file for networkStudent class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-14           V1
----------------------------------------------------------------------------- */
#pragma once
#include "student.h"
#include "degree.h"

class networkStudent : public Student {
protected:
	//enum data type
	Degree d = NETWORKING;
public:
	networkStudent();//default constructor
	networkStudent(string studentID, string fname, string lname, string email, int age, int numDaysToComplete[], Degree d);//overloaded constructor
	~networkStudent();//destructor
	Degree getDegreeProgram();//gets enum data
	void print();//virtual print from student class

};