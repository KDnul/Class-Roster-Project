#include<iostream>


#include "student.h"
#include "roster.h"

using namespace std;

int main() {
	// Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name.
	cout << "Course: C867 Scripting & Programming - Applications" << endl;
	cout << "Programing language: C++" << endl;
	cout << "WGU ID: 001421182" << endl;
	cout << "Name: Kelvin Duong" << endl;
	cout << endl;


	const int numStudents = 5; // For this specific project, there are 5 students in total
	const string studentData[numStudents] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE","A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Bob,Young,byoung@gmail.com,21,10,20,30,SOFTWARE" };

	// Create an instance of the Roster class called classRoster
	Roster classRoster; // Calls default constructor

	// Add each student to classRoster.
	for (int i = 0; i < numStudents; ++i) {
		classRoster.parse(studentData[i]);
	}
	// Convert the following pseudo code to complete the rest of the  main() function
	classRoster.printAll();
	cout << endl;

	classRoster.printInvalidEmails();
	cout << endl;



	//loop through classRosterArray and for each element:
	for (int i = 0; i < classRoster.getClassRosterArray().size(); ++i) {
		string currStudent = classRoster.getClassRosterArray().at(i)->getStudentID();
		classRoster.printAverageDaysInCourse(currStudent);
	}
	cout << endl;

	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	return 0;
}