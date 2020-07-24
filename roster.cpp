/* -----------------------------------------------------------------------------
FILE:              roster.cpp

DESCRIPTION:       Implementation file for roster class

COMPILER:          Virtual Studio 2019

MODIFICATION HISTORY:

Author                  Date               Version
---------------         ----------         --------------
William Alwin           2019-4-16          V1
----------------------------------------------------------------------------- */
#include "roster.h"
#include "degree.h"

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::Roster()

PURPOSE:           Default constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
Roster::Roster(){}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::Roster(int num)

PURPOSE:           Overloaded constructor

RETURNS:           No Return value
----------------------------------------------------------------------------- */
Roster::Roster(int num) {
	this->num = num;
	this->Index = -1;
	this->classRosterArray = new Student*[num];
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     ~Roster::Roster()

PURPOSE:           Destructor for Roster clasd

RETURNS:           No Return value
----------------------------------------------------------------------------- */
Roster::~Roster() {
	cout << endl << "Deleting student objects.";
	for (int i = 0; i <= Index; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::parse(const string row)

PURPOSE:           Parses student data array and passes data to add function

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::parse(const string row) {
	//variables for student data
	string id[9];//temp array used to hold values prior to variable assignment
	string studentNum, first, last, em;
	int yrs, days1, days2, days3;
	Degree degreeType;
	int j = 0;//iterator for temp array
	//parsing data in managable temp array id[]
	if (Index < num) {
		Index++;
		for (int i = 0; i < row.length(); i++) {			
			if (row[i] == ',') {
				j++;//increment id array if ',' found
			}
			else {
				id[j] += row[i];//else add data to temp array one character at a time
			}
		}
		//assigning to variables for add function call
		studentNum = id[0];
		first = id[1];
		last = id[2];
		em = id[3];
		yrs = stoi(id[4]);
		days1 = stoi(id[5]);
		days2 = stoi(id[6]);
		days3 = stoi(id[7]);
		if (id[8] == "SOFTWARE") {
			degreeType = SOFTWARE;
		}
		else if (id[8] == "SECURITY") {
			degreeType = SECURITY;
		}
		else {
			degreeType = NETWORKING;
		}
		//once variable are filled call add function
		add(studentNum, first, last, em, yrs, days1, days2, days3, degreeType);
	}
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type)

PURPOSE:           Builds Student objects based on enum data type and adds them to classRosterArray

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree type) {
	int courseDays[3];//temp array to hold days1-3
	courseDays[0] = daysInCourse1;
	courseDays[1] = daysInCourse2;
	courseDays[2] = daysInCourse3;
	if (type == SOFTWARE) {
		classRosterArray[Index] = new softwareStudent(studentID, firstName, lastName, emailAddress, age, courseDays, type);
	}
	else if (type == SECURITY) {
		classRosterArray[Index] = new securityStudent(studentID, firstName, lastName, emailAddress, age, courseDays, type);
	}
	else {
		classRosterArray[Index] = new networkStudent(studentID, firstName, lastName, emailAddress, age, courseDays, type);
	}

}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::remove(string studentID)

PURPOSE:           Removes Student objects from classRosterArray based on studentID

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::remove(string studentID) {
	int tempNum = Index;
	for (int i = 0; i <= Index; i++) {
		if(this->classRosterArray[i]->getStudentID() == studentID){
			delete this->classRosterArray[i];
			//updates classRoster after removing student
			for (i; i < Index; i++) {
				this->classRosterArray[i] = this->classRosterArray[i + 1];
			}
			Index--;
			cout << endl << "Student successfully removed." << endl;//if studentID found and object removed prints success message
			break;//breaks for loop if studentID found
		}
	}
	//checks to see if Index was decremented after removal of student
	if (Index == tempNum) {
		cout << endl << "Student not found." << endl;//else prints error message
	}
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::printAll()

PURPOSE:           Prints all student class objects present in classRosterArray

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::printAll() {
	for (int i = 0; i <= Index; i++) {
		(this->classRosterArray)[i]->print();
	}
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::printDaysInCourse(string studentID)

PURPOSE:           Prints average of days in course for student based on studentID

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::printDaysInCourse(string studentID) {
	int days1, days2, days3;
	for (int i = 0; i <= Index; i++) {
		if (this->classRosterArray[i]->getStudentID() == studentID) {
			days1 = this->classRosterArray[i]->getDaysToComplete(0);
			days2 = this->classRosterArray[i]->getDaysToComplete(1);
			days3 = this->classRosterArray[i]->getDaysToComplete(2);
			cout << studentID << ": " << (days1 + days2 + days3) / 3 << endl << endl;
		}
	}
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::printInvalidEmails()

PURPOSE:           Prints error message if email is invalid using regex. Note : A valid email should include an at sign('@') and period('.') and should not include a space(' ')

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::printInvalidEmails() {
	for (int i = 0; i <= Index; i++) {
		//tests for (characters)(possible . or _)(more characters)@(more characters)(. and more characters)
		regex validator("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
		if (!regex_match(this->classRosterArray[i]->getEmail(), validator)) {
			cout << endl << "Student " << this->classRosterArray[i]->getStudentID() << " has input an invalid email: " << this->classRosterArray[i]->getEmail() << endl;//error message if no match found
		}
	}
	cout << endl;
}

/*   ---------------------------------------------------------------------------
FUNCTION NAME:     Roster::printByDegreeProgram(Degree d)

PURPOSE:           Prints student objects based on enum data type

RETURNS:           No Return value
----------------------------------------------------------------------------- */
void Roster::printByDegreeProgram(Degree d) {
	for (int i = 0; i <= Index; i++) {
		if (this->classRosterArray[i]->getDegreeProgram() == d) {
			this->classRosterArray[i]->print();
		}
	}
}
/*   ---------------------------------------------------------------------------
FUNCTION NAME:     main()

PURPOSE:           Driver for program, handles function calls to meet program requirements

RETURNS:           No return value
----------------------------------------------------------------------------- */
void main() {
	int num = 5;//variable to populate number of classRoster objects
	Roster * classRoster = new Roster(num);//creates Roster objects
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,William,Alwin,willalwin@msn.com,41,21,21,14,SOFTWARE" };
	for (int i = 0; i < num; i++) {
		classRoster->parse(studentData[i]);//call to parse to seperate student data into Student objects
	}
	//program output based on requirements
	cout << "Course title: Scripting and Programming - Applications - C867\tLanguage: C++\tStudent ID: #001100213\tName: William Alwin" << endl << endl;
	cout << "Printing class roster: " << endl;
	classRoster->printAll();
	cout << endl << "Checking for invalid emails: " << endl;
	classRoster->printInvalidEmails();
	cout << "Average number of days in courses: " << endl << endl;
	classRoster->printDaysInCourse("A1");
	classRoster->printDaysInCourse("A2");
	classRoster->printDaysInCourse("A3");
	classRoster->printDaysInCourse("A4");
	classRoster->printDaysInCourse("A5");
	cout << "Printing by Software degree program: " << endl;
	classRoster->printByDegreeProgram(SOFTWARE);
	cout << "Printing by Network degree program: " << endl;
	classRoster->printByDegreeProgram(NETWORKING);
	cout << "Printing by Security degree program: " << endl;
	classRoster->printByDegreeProgram(SECURITY);
	cout << endl << "Removing student by ID: A3" << endl;
	classRoster->remove("A3");
	cout << endl << "Attempting to remove student A3 again: " << endl;
	classRoster->remove("A3");
	cout << endl << "Printing revised student roster: " << endl;
	classRoster->printAll();
	delete classRoster;//calls Roster destructor
}