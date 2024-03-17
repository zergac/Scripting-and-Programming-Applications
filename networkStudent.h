#pragma once
#include "student.h"
#include "degree.h"



class NetworkStudent:Student {
public:
	Degree getDegreeProgram();
private:
	Degree DT = NETWORKING;
};