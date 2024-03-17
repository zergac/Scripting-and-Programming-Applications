#include "student.h"



Student::Student(string ID, string fName, string lName, string eAddrs, int num, int daysInCourse1, int daysInCourse2, int daysInCourse3,  Degree dType) {
	studentID = ID;
	firstName = fName;
	lastName = lName;
	emailAddress = eAddrs;
	age = num;
	daysInCourses[0] = daysInCourse1;
	daysInCourses[1] = daysInCourse2;
	daysInCourses[2] = daysInCourse3;
	degreeType = dType;
}

string Student::getstudentID() {
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

int Student::getage(){
	return age;
}

int * Student::getNumberDaysInCourses() {
	return daysInCourses;
}


Degree Student::getdegreeType() {
	return degreeType;
}
//

void Student::setstudentID(string ID) {
	studentID = ID;
	return;
}

void Student::setfirstName(string fName) {
	firstName = fName;
	return;
}

void Student::setlastName(string lName) {
	lastName = lName;
	return;
}

void Student::setemailAddress(string eAddrs) {
	emailAddress = eAddrs;
	return;
}

void Student::setage(int num) {
	age = num;
	return;
}
/*
void Student::setNumberDaysInCourses(int numDays1, int numDays2, int numDays3) {
	daysInCourses.push_back(numDays1);
	daysInCourses.push_back(numDays2);
	daysInCourses.push_back(numDays3);
	return;
}
*/

void Student::setNumberDaysInCourses(int numDays1, int numDays2, int numDays3) {
	daysInCourses[0] = numDays1;
	daysInCourses[1] = numDays2;
	daysInCourses[2] = numDays3;
	return;
}

void Student::setdegreeType(Degree dType) {
	degreeType = dType;
	return;
}

void Student::print(){
	int* daysArr = getNumberDaysInCourses();

	Degree deg = getdegreeType();
	string strDegree;

	if (deg == NETWORKING) {
		strDegree = "NETWORKING";
	}
	else if (deg == SOFTWARE) {
		strDegree = "SOFTWARE";
	}
	else if (deg == SECURITY) {
		strDegree = "SECURITY";
	}

	cout << "Student ID: " << getstudentID() <<
		"\t First Name: " << getfirstName() <<
		"\t Last Name: " << getlastName() <<
		"\t Age: " << getage() <<
		"\t daysInCourse: {" << daysArr[0] << ", " << daysArr[1] << ", " << daysArr[2] << "}" <<
		"\t Degree Program: " << strDegree <<
		endl;

	return;
}

Student::~Student() {
	return;
}
Degree Student::getDegreeProgram() {
	return degreeType;
}

