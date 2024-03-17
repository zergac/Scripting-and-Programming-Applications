#pragma once
#include <iostream>
#include <array>
#include <stdio.h>
#include "degree.h"
#include <vector>
using namespace std;


class Student {
public:
	Student(string ID, string fName, string lName, string eAddrs, int num, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree dType);
	~Student();
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	int * getNumberDaysInCourses();
	Degree getdegreeType();
	
	void setstudentID(string ID);
	void setfirstName(string fName);
	void setlastName(string lName);
	void setemailAddress(string eAddrs);
	void setage(int num);
	void setNumberDaysInCourses(int numDays1, int numDays2, int numDays3);
	void setdegreeType(Degree dType);
	virtual void print();
	virtual Degree getDegreeProgram();
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	//vector <int> daysInCourses;
	int daysInCourses[3];
	Degree degreeType;
};

//Degree type should be populated in subclasses only.