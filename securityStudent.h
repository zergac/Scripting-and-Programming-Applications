#pragma once
#include "student.h"
#include "degree.h"



class SecurityStudent:Student{
public:
	Degree getDegreeProgram();
private:
	Degree DT = SECURITY;
};
