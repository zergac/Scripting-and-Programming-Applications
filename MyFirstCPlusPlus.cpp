#include <iostream>
#include <array>
#include <stdio.h>
#include "student.h"
//#include "networkStudent.h"
//#include "securityStudent.h"
//#include "softwareStudent.h"
//#include "degree.h"

using namespace std;


int main2()
{

	const string studentData[] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Carolina,Zerga,czerga2@mywgu.edu,31,30,30,40,SOFTWARE"
	};


	//Student b(4, "Erin", "Black", "Erin.black@comcast.net", 22, "SECURITY");
	//cout << b.getemailAddress();



	int i = 0;

	while (i < 5) {
		cout << studentData[i] << endl;
		i++;

	}
	


	return 0;
}