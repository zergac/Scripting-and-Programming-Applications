#pragma once
#include "student.h"
#include "degree.h"



class SoftwareStudent:Student {
public:
	Degree getDegreeProgram();
private:
	Degree DT = SOFTWARE;
};