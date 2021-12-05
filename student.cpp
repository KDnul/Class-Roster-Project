#include<iostream>
#include<iomanip>

#include "student.h"

using namespace std;

/*
Requirements D.1 & D.2
	 Create the class Student  in the files student.h and student.cpp, which includes each of the following variables:
	 studentID, first name, last name, email address,
	 age, array of number of days to complete each course, and degree program

Create each of the following functions in the Student class:
	 A. an accessor for each instance variable from part D1
	 B. a mutator for each instance vairable from part D1
	 C. All external access and changes to any instance variables of the Student calss must be done using accessor and mutator functions
	 D. constructor using all of the input parameters provided in the table
	 E. print() to print specific student data
 */

 // Default Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < maxSizeOfArray; ++i) {
		this->numDaysComplCrse[i] = numDaysComplCrse[i];
	}
	this->degreeProgram = Degree_Program::SECURITY;
}

// Student Constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysComplCrse[], Degree_Program degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < maxSizeOfArray; ++i) {
		this->numDaysComplCrse[i] = numDaysComplCrse[i];
	}
	this->degreeProgram = degreeProgram;
}

// Destructor
Student::~Student() {
	cout << "Destroyed" << endl;
}

// Mutators
void Student::setSudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDaysComplCrse(int* numDaysComplCrse[]) {
	for (int i = 0; i < maxSizeOfArray; ++i) {
		this->numDaysComplCrse[i] = *numDaysComplCrse[i];
	}
}
void Student::setDegreeProgram(Degree_Program degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// Accessors
string Student::getStudentID() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int Student::getNumDaysComplCrse(int arrayIndex) {
	return numDaysComplCrse[arrayIndex];
}
Degree_Program Student::getDegreeProgram() {
	return degreeProgram;
}

// Print Function
void Student::print() {
	cout << setw(3) << left << this->getStudentID() << '\t';
	cout << setw(10) << left << this->getFirstName() << '\t';
	cout << setw(10) << left << this->getLastName() << '\t';
	cout << setw(20) << left << this->getEmailAddress() << '\t';
	cout << setw(10) << left << this->getAge() << '\t';
	cout << setw(10) << right << this->getNumDaysComplCrse(0) << '\t';
	cout << setw(5) << left << this->getNumDaysComplCrse(1) << '\t';
	cout << setw(10) << left << this->getNumDaysComplCrse(2) << '\t';
	//cout << setw(10) << left << this->getDegreeProgram() << endl;

	if (getDegreeProgram() == 0) {
		cout << setw(5) << left << degreeProgramString[0] << endl;
	}
	else if (getDegreeProgram() == 1) {
		cout << setw(5) << left << degreeProgramString[1] << endl;
	}
	else if (getDegreeProgram() == 2) {
		cout << setw(5) << left << degreeProgramString[2] << endl;
	}
}

void Student::printColumns() {
	cout << setw(3) << left << "|ID|" << '\t';
	cout << setw(10) << left << "|First|" << '\t';
	cout << setw(10) << left << "|Last|" << '\t';
	cout << setw(20) << left << "|Email|" << '\t';
	cout << setw(10) << left << "|Age|" << '\t';
	cout << setw(15) << left << "|Number of days in 3 courses|" << '\t';
	cout << setw(10) << left << "|Degree Program|" << endl;
				  
}