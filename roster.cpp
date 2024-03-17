
#include <iostream>
#include <array>
#include <stdio.h>
#include "student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"
#include <vector>

using namespace std;


class Roster {
	private:
		int rosterSize = 5;
		Student* classRosterArray[5];
		
	public:
		
		Roster() {
			const string studentData[] =
			{
			"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
			"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
			"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
			"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
			"A5,Carolina,Zerga,czerga2@mywgu.edu,31,30,30,40,SOFTWARE"
			};

			Student *ptrS1 = new Student ("A1", "John", "Smith", "John1989@gmail.com", 20, 30, 35, 40, SECURITY);
			Student *ptrS2 = new Student ("A2", "Suzan", "Erickson", "Erickson_1990@gmailcom", 19, 50, 30, 40, NETWORKING);
			Student *ptrS3 = new Student ("A3", "Jack", "Napoli", "The_lawyer99yahoo.com", 19, 20, 40, 33, SOFTWARE);
			Student *ptrS4 = new Student ("A4", "Erin", "Black", "Erin.black@comcast.net", 22, 50, 58, 40, SECURITY);
			Student *ptrS5 = new Student ("A5", "Carolina", "Zerga", "czerga2@mywgu.edu", 31, 30, 30, 40, SOFTWARE);

			classRosterArray[0] = ptrS1;
			classRosterArray[1] = ptrS2;
			classRosterArray[2] = ptrS3;
			classRosterArray[3] = ptrS4;
			classRosterArray[4] = ptrS5;

		}

		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
			Student *ptrS = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degree);
			classRosterArray[rosterSize] = ptrS;
			rosterSize = rosterSize + 1;

			return;
		}
		void remove(string studentID) {
			//loop through array and find student with the corresponding student ID
			bool wasFound = false;
			int studentNum;
			int i = 0;
			while (i < rosterSize) {
				if (classRosterArray[i]->getstudentID() == studentID) {
					//classRosterArray2[i] = NULL;
					wasFound = true;
					studentNum = i;
					break;
				}

				i++;
			}

			if (wasFound == true) {
				for (int i = studentNum+1; i < rosterSize; i++) {
					classRosterArray[i - 1] = classRosterArray[i];
				}

				rosterSize = rosterSize - 1;
			}
			else {
				cout << "Student with this ID was NOT found";
			}

			return;
		}

		void printAll() {
			int i = 0;
			while (i < rosterSize) {
				classRosterArray[i]->print();
				i++;
			}
			return;
		}

		void printAverageDaysInCourse(string studentID) {
			//average number of days in the 3 courses
			int d1 = 0;
			int d2 = 0;
			int d3 = 0;
			double avgDays = 0;
			int i = 0;
			while (i < rosterSize) {
				if (classRosterArray[i]->getstudentID() == studentID) {
					d1 = classRosterArray[i]->getNumberDaysInCourses()[0];
					d2 = classRosterArray[i]->getNumberDaysInCourses()[1];
					d3 = classRosterArray[i]->getNumberDaysInCourses()[2];

					avgDays = (d1 + d2 + d3) / 3.0;
					cout << avgDays;
					break;
				}

				i++;
			}

			return;
		}
		void printInvalidEmails() {
			//spaces are considered invalid
			//@, . is needed for valid email addresses
			//print all invalid email addresses
			int i = 0;
			while (i < rosterSize) {
				string emailAddress = classRosterArray[i]->getemailAddress();

				int j = 0;
				bool hasASymbol = false;
				bool hasDot = false;
				while (j < emailAddress.size()) {
					if (emailAddress[j] == ' ') {
						cout << emailAddress << endl;
						hasASymbol = true;
						hasDot = true;
						break;
					}

					if (emailAddress[j] == '@') {
						hasASymbol = true;
					}
					if (emailAddress[j] == '.') {
						hasDot = true;
					}
					j++;
				}

				if (hasASymbol == true && hasDot == true) {
					//dont do anything
				}
				else {
					cout << emailAddress << endl;
				}
				i++;
			}

			return;
		}

		void printByDegreeProgram(Degree degreeProgram ) {
			Degree studentDegree;

			int i = 0;
			while (i < rosterSize) {
				studentDegree = classRosterArray[i]->getdegreeType();

				if (studentDegree == degreeProgram) {
					classRosterArray[i]->print();
				}

				i++;
			}
		}

		~Roster() {
		}

};

void main()
{
	cout << "Scripting and Programming - Applications - C867" << endl;
	cout << "Programming Language: C++" << endl;
	cout << "Student ID: 000996689" << endl;
	cout << "Carolina Zerga" << endl;
	cout << endl;

	Roster classRoster;

	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	classRoster.printAverageDaysInCourse("A1");
	cout << ", ";
	classRoster.printAverageDaysInCourse("A2");
	cout << ", ";
	classRoster.printAverageDaysInCourse("A3");
	cout << ", ";
	classRoster.printAverageDaysInCourse("A4");
	cout << ", ";
	classRoster.printAverageDaysInCourse("A5");


	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster.remove("A3");
	cout << endl;
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3");


	classRoster.~Roster();



	return;
}