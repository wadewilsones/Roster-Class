#include <iostream>
#include "roster.h";

using namespace std;

int main() {

	// Part F, 1.
	cout << "Course Title: Scripting and programming applications,  C867 \n"
		 << "Used language: C++ \n"
		 << "Student ID: 011020337\n"
		<< "Student Name: Ulada Haranina\n\n";

	// Part F, 2-4.

	const string studentData[5] = {
	"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Ulada,Haranina,uharni@wgu.edu,25,1,1,3,SOFTWARE" };


	Roster classRoster = Roster(studentData); // add students

	cout << "\nStudent List: \n\n";
	classRoster.printAll(); // prints students data (revised)
	cout << "\nInvalid emails:\n";
	classRoster.printInvalidEmails(); //print all invalid emails 


	cout << "\nAverage days is class:\n";
	for (int i = 0; i < classRoster.getclassRosterArray().size(); i++) {
		string studentID = classRoster.getclassRosterArray()[i]->getStudentId();
		classRoster.printAverageDaysInCourse(studentID) ;
	}

	cout << "\nPrinting by Degree:\n";
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << "\nRemoving Student with ID A3...\n";
	classRoster.remove("A3");

	cout << "\nStudent List:\n";
	classRoster.printAll();

	cout << "\n";
	classRoster.remove("A3");
	cout << "\n";

	// Call desctructor
	classRoster.~Roster();  // (revised)
	return 0;

}

