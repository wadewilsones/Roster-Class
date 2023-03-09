#include "student.h"; // add header 
using namespace std;

//Part D2 - Constructor

Student::Student(string stId, string fname, string lname, string email, int studentAge, int daysInClass[3], DegreeProgram degree)
 {
	
	this->studentID = stId;
	this->firstName = fname;
	this->lastName = lname;
	this->emailAddress = email;
	this->age = studentAge;
	for (int i = 0; i < 3; i++) {

		this->daysInClasses[i] = daysInClass[i];
	}
	this->degree_program = degree;

}


// Imlepentation of setters

void Student::setStudentId(string id) {
	studentID = id;
};
void Student::setfirstName(string name) {
	firstName = name;
}
void Student::setlastName(string name) {
	
		lastName = name;
}
void Student::setemailAddress(string address) {
	emailAddress = address;
}
void Student::setAge(int age) {
	age = age;
}
void Student::setdaysInClasses(int days[]) { // Change to size of
	for (int i = 0; i < 3; i++) {
		daysInClasses[i] = days[i];
	}
}
void Student::setDegreeprogram(DegreeProgram degree) {
	degree_program = degree;
}


// Imlepentation of getters

string Student::getStudentId() {
	return studentID;
}
string Student::getfirstName() {
	return firstName;
}
string Student::getlastName() {
	return lastName;
}
string Student::getemailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getdaysInClasses() {
	
	return daysInClasses;
}
DegreeProgram Student::getDegreeprogram() {
	return degree_program;
}

//Print function
void Student::print() {

	string degree;

	if (this->getDegreeprogram() == 0) {
		degree = "SECURITY";
	}
	else if (this->getDegreeprogram() == 1) {
		degree = "SECURITY";
	}
	else {
		degree = "SOFTWARE";
	}

	cout << "\n" << this->getStudentId() << "\t";
	cout << "First Name: " << this->getfirstName() << "\t";
	cout << "Last Name: " << this->getlastName() << "\t";
	cout << "Age: " << this->getAge() << "\t";
	//The instructions in E 3c didn't display printing of the email, so I did skip it too.
	cout << "\t daysInCourse: {" << this->getdaysInClasses()[0] << ", " << this->getdaysInClasses()[1] << ", " << this->getdaysInClasses()[2] << "}  "; 
	cout << "Degree Program: " << degree << "\n";
	
}


