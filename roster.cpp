#include "roster.h";
#include "degree.h";
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include<sstream>
#include <regex>

using namespace std;

 //Parse functions
 static DegreeProgram convert_to_degree(string degree); // convert to enum
 static vector <string> splitString(string StudentData); // split string into substrings and place in vector

//Constructor
Roster::Roster (const string studentData[5]) {

	for (int i = 0; i < 5; i++) {

		//Split input 
		vector <string> newData = splitString(studentData[i]);
		
		//Convert string to array of int
		int transformedData[3] = { stoi(newData[5]),  stoi(newData[6]),  stoi(newData[7]) };
		
		//Add students data to vector
		Roster::getclassRosterArray().push_back(
			new Student(
			newData[0],  //id
			newData[1], //fname
			newData[2],//lname
			newData[3], //email
			stoi(newData[4]), //age
			transformedData, //days
			convert_to_degree(newData[8]) //degree
		));
	}

	
}

//Add student ( that sets the instance variables from part D1 and updates the roster) 
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {

	// add days in array for further processing
	int daysInProgram[3] = { daysInCourse1,  daysInCourse2, daysInCourse3 };

	//Update roster
	Roster::getclassRosterArray().push_back(new Student(studentID, firstName, lastName, emailAddress, age, daysInProgram, degreeprogram));
};

//Remove student 
void  Roster::remove(string studentID) {

	//Get index of searched id
	bool isFound = false;
	for (int i = 0; i < getclassRosterArray().size(); i++) {

		if (getclassRosterArray().at(i)->getStudentId() == studentID) {
			isFound = true;
			//Delete this record
			getclassRosterArray().erase(getclassRosterArray().begin() + i);
			break;
		}
		else {
			bool isFound = false;
		}
	}

	//Print error if id is not found
	if (!isFound) {
		cout << "Error! Student ID is not found in the system!";
	}

}


//print all student records
void Roster::printAll() {

	for (int i = 0; i < getclassRosterArray().size(); i++) {
		getclassRosterArray().at(i)->print();
	}
};

//Avarage days in course

void Roster::printAverageDaysInCourse(string studentID) {
	//Find record
	bool isFound = false;
	double average = 0;
	for (int i = 0; i < getclassRosterArray().size(); i++) {

		if (getclassRosterArray().at(i)->getStudentId() == studentID) {
			isFound = true;
			//calculate avarage
			int* days = getclassRosterArray().at(i)->getdaysInClasses();
			average = (days[0] + days[1] + days[2]) / 3;
			//print avarage
			cout <<  "\n Average in class for "  << getclassRosterArray().at(i)->getlastName()  << ": " << average << " days. \n";
			break;
		}
		else {
			bool isFound = false;
		}
	}

	//Print error if id is not found
	if (!isFound) {
		cout << "Error! Student ID is not found in the system!";
	}



}

//verifies student email addresses 
void Roster::printInvalidEmails() {

	//set up regex
	const regex pattern ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
	// Iterate throu each student
	for (int i = 0; i < getclassRosterArray().size(); i++) {
		string email = getclassRosterArray().at(i)->getemailAddress();
		if (!regex_match(email, pattern)) {
			cout << "\nEmail '" << email << "' is not correct!";
		}
		
	}

	cout << "\n";
}

// prints out student information

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {

	for (int i = 0; i < classRosterArray.size(); i++) {

		if (getclassRosterArray().at(i)->getDegreeprogram() == degreeProgram) {
			//print student info
			getclassRosterArray().at(i)->print();
		}
	}
}


// Splitting and Parsing string

static vector <string>  splitString(const string StudentData) {

	vector <string> splittedString;
	//create string stream
	stringstream s_stream(StudentData);

	while (s_stream.good()) {
		// stream state has no errors
		string slice;
		getline(s_stream, slice, ',');
		splittedString.push_back(slice);
	}

	return splittedString;
}

//Parsing to Enum DegreeProgram
static DegreeProgram convert_to_degree(string degree) {
	if (degree == "SECURITY") return DegreeProgram::SECURITY;
	else if (degree == "NETWORK") return DegreeProgram::NETWORK;
	else if (degree == "SOFTWARE") return DegreeProgram::SOFTWARE;
	else {
		return SOFTWARE;
	}
}



