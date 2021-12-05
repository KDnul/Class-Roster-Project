#pragma once
#ifndef STUDENT_H // Header Guard
#define STUDENT_H // Header Guard

#include<iostream>
#include<vector>

#include "degree.h"

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

class Student {
	private:
		string studentID;
		string firstName, lastName;
		string emailAddress;
		int age;
		const static int maxSizeOfArray = 3;
		int numDaysComplCrse[maxSizeOfArray];
		Degree_Program degreeProgram;

	public:
		// Default Constructor
		Student();

		// Student Constructor
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, int numDaysComplCrse[], Degree_Program degreeProgram);

		// Destructor
		~Student();

		// Mutators
		void setSudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastname);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setNumDaysComplCrse(int* numdaysComplCrse[]);
		void setDegreeProgram(Degree_Program degreeProgram);

		// Accessors
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
		int getNumDaysComplCrse(int arrayIndex);
		Degree_Program getDegreeProgram();

		// Print Function
		void print();
		static void printColumns(); // This is to print the specific columns to make it easier to read
};

#endif // End of header Guard
