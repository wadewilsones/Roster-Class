#include <string> // adds string directive for using string type in class
#include <iostream>
#include "degree.h";

using namespace std; // access entities 


// Define student class
class Student {

	//Part D2
public:
	Student(string stId, string fname, string lname, string email, int age, int daysInClass[3], DegreeProgram degree); // constructor

	//Getters
	string getStudentId();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getAge();
	int* getdaysInClasses();
	DegreeProgram getDegreeprogram();

	//Setters
	void setStudentId(string id);
	void setfirstName(string name);
	void setlastName(string name);
	void setemailAddress(string address);
	void setAge(int age);
	void setdaysInClasses(int days[]);
	void setDegreeprogram(DegreeProgram degree);

	//Print function
	void print();

private:
	//Part D1
	string studentID;
	string firstName;
	string lastName;
	string	emailAddress;
	int age;
	int daysInClasses[3];
	DegreeProgram degree_program;



};

