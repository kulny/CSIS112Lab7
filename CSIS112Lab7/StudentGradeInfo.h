#pragma once
#include "StudentInfo.h"
#include <vector>
#include <iostream>
#include <exception>



class StudentGradeInfo :
	public StudentInfo  // extends StudentInfo

{
public:
	StudentGradeInfo(std::string name);
	~StudentGradeInfo();

	void AddGrade(int n);
	int GetGradeAtIndex(int index); //returns single grade at index
	void PrintAllGrades();
	void PrintAllGradesAndAvg();

	bool operator==(StudentGradeInfo& sgi); // overloads ==, compares two student grade info classes
	bool operator<(StudentGradeInfo& sgi); // overloads < to compare student ID's for sort



private:
	std::vector<int> grades;

	int CalcAvg();
};

