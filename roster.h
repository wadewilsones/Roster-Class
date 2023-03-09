#include <string>
#include <iostream>
#include <vector>;
#include "degree.h";
#include "student.h"; 

using namespace std;

class Roster {

public:

	Roster(const string studentData[5]); // constructor
	~Roster() { // (revised)
		for (int i = 0; i < classRosterArray.size(); i++) {
			delete(classRosterArray.at(i)); // deleting pointers
		};
		classRosterArray.clear(); // make vector's size zero
		
	}; // destructor

	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	//Getter for array with students
	vector <Student*> &getclassRosterArray() {
		return classRosterArray;
	}; 


private:
	//Declate vector for holding object pointers
	vector <Student*> classRosterArray;



};

