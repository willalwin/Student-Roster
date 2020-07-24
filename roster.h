/* -----------------------------------------------------------------------------
FILE:              roster.h

DESCRIPTION:       Header file for roster class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-16          V1
----------------------------------------------------------------------------- */
#pragma once
#include "student.h"
#include "softwareStudent.h"
#include "securityStudent.h"
#include "networkStudent.h"
#include "degree.h"
#include <cstring>
#include <string>
#include <regex>

class Roster {
	private:
		int num; //student count
		int Index;//tracks end of studentData array
		Student** classRosterArray;//array of pointers to Student class
	public:
		Roster();//default constructor

		Roster(int num);//overloaded constructor

		~Roster();//destructor

		void parse(const string row); //parses studentData array and sends to add function

		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type);//adds Student objects to classRosterArray

		void remove(string studentID); //removes students from the roster by student ID

		void printAll(); //prints a complete tab - separated list of student data using accessor functions

		void printDaysInCourse(string studentID); //prints a student’s average number of days in the three courses

		void printInvalidEmails(); //verifies student email addresses

		void printByDegreeProgram(Degree d);//prints student objects based on enumerated data type

};