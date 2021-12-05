#include<iostream>
#include<sstream>

#include "roster.h"

using namespace std;

/*
E.  Create a Roster class (roster.cpp) by doing the following:
1.  Create an array of pointers, classRosterArray, to hold the data provided in the “studentData Table.”

2.  Create a student object for each student in the data table and populate classRosterArray.
a.  Parse each set of data identified in the “studentData Table.”
b.  Add each student object to classRosterArray.

3.  Define the following functions:
a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.
b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, the function prints an error
message indicating that the student was not found.
c. public void printAll() that prints a complete tab-separated list of student data in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab]
Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should
loop through all the students in classRosterArray and call the print() function for each student.
d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days in the three courses. The student is identified
by the studentID parameter.
e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for a degree program specified by an enumerated type.
*/

// Constructor
Roster::Roster() {}

// Destructor
Roster::~Roster() {
	cout << "DESTRUCTION IS COMING" << endl;
	for (int i = 0; i < classRosterArray.size(); ++i) {
		cout << "Student being destroyed at " << i << endl;
		delete classRosterArray.at(i);
		classRosterArray.at(i) = nullptr;
	}
}

// Parse function
void Roster::parse(string studentdata) {

	// Gives us Student ID
	int rhs = studentdata.find(","); // Find the index of the commas and assign to a variable rhs for right hand side
	string studentID = studentdata.substr(0, rhs); // Gives us Student ID

	// Gives us Student First Name
	int lhs = rhs + 1; // Use lhs (left hand side)
	rhs = studentdata.find(",", lhs); 
	string firstName = studentdata.substr(lhs, rhs - lhs);

	// Gives us Student Last Name
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string lastName = studentdata.substr(lhs, rhs - lhs);

	// Gives us Student Email
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string emailAddress = studentdata.substr(lhs, rhs - lhs);

	// Gives us Student age
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int age = stoi(studentdata.substr(lhs, rhs - lhs)); // Use stoi() function to parse the string into an integer

	// Gives us first number of days to complete course 1
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int crse1 = stoi(studentdata.substr(lhs, rhs - lhs));

	// Gives us first number of days to complete course 2
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int crse2 = stoi(studentdata.substr(lhs, rhs - lhs));

	// Gives us first number of days to complete course 3
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	int crse3 = stoi(studentdata.substr(lhs, rhs - lhs));

	// Gives us degree program
	lhs = rhs + 1;
	rhs = studentdata.find(",", lhs);
	string degreeStr = studentdata.substr(lhs, rhs - lhs);
	Degree_Program degree;
	
	if (degreeStr == "SECURITY") {
		degree = Degree_Program::SECURITY;
	}
	else if (degreeStr == "NETWORK") {
		degree = Degree_Program::NETWORK;
	}
	else if (degreeStr == "SOFTWARE") {
		degree = Degree_Program::SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, crse1, crse2, crse3, degree);
}

// Set the class roster array
void Roster::setClassRosterArray(vector<Student*> classRosterArray) {
	for (int i = 0; i < classRosterArray.size(); ++i) {
		this->classRosterArray.at(i) = classRosterArray.at(i);
	}
}

// Get the Class Roster array
vector<Student*> Roster::getClassRosterArray() {
		return classRosterArray;
}

// Adding students
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree_Program degreeProgram) {
	int crseArr[] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray.push_back(new Student(studentID, firstName, lastName, emailAddress, age, crseArr, degreeProgram));
}

// Remove student based on studentID
void Roster::remove(string studentID) {
	// We assume the student ID is not there, if it is, we remove it
	bool student = false;

	for (int i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->getStudentID() == studentID) {
			student = true; // ID is found, time to delete
			classRosterArray.erase(classRosterArray.begin() + i);// Because we are using a vector, it should take care of resizing itself
		}

	}
	if (student) {
		cout << "Student ID " << studentID << ": is removed from the roster." << endl;
	}
	else cout << "The student you are trying to remove is not found." << endl;


}

// Print all the students in the roster
void Roster::printAll() {
	Student::printColumns();
	cout << endl;
	for (int i = 0; i < classRosterArray.size(); ++i) {
		classRosterArray.at(i)->print();
	}
}

// Print a students average days in course
void Roster::printAverageDaysInCourse(string studentID) {


	for (int i = 0; i < classRosterArray.size(); ++i) {
		if (classRosterArray.at(i)->getStudentID() == studentID) {
			cout << "Student ID " << classRosterArray.at(i)->getStudentID() << " average number of days in 3 courses: ";
			cout << (classRosterArray.at(i)->getNumDaysComplCrse(0)
				+ classRosterArray.at(i)->getNumDaysComplCrse(1)
				+ classRosterArray.at(i)->getNumDaysComplCrse(2)) / 3 << endl;
		}
	}
}

// Emails should contain an (@) symbol and a (.) period
void Roster::printInvalidEmails() {

	cout << "Invalid emails: " << endl;
	for (int i = 0; i < classRosterArray.size(); ++i) {
		// Email should not include spaces
		string email = (classRosterArray.at(i)->getEmailAddress());

		// Spaces validation
		vector<char> testVctr(email.begin(), email.end() - 1);
		for (int j = 0; j < testVctr.size(); ++j) {
			if (isspace(testVctr.at(j))) {
				cout << email << " is an invalid email" << endl;
			}
		}

		// Character validation
		// Use string::npos if the find does not find a position where the character is checked
		if (email.find('@') == string::npos || email.find('.') == string::npos) {
			cout << email << " is an invalid email" << endl;
		}
	}
	cout << endl;
}

// Print students based on their degree program
void Roster::printByDegreeProgram(Degree_Program degreeProgram) {
	
	cout << "Students that are in: " << degreeProgramString[degreeProgram] << endl;
	Student::printColumns();
	cout << endl;
	for (int i = 0; i < classRosterArray.size(); ++i) {
		if ((int) classRosterArray.at(i)->getDegreeProgram() == degreeProgram) {
			classRosterArray.at(i)->print();
		}
	}
	cout << endl;
}
