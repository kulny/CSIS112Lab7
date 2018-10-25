#include "stdafx.h"
#include "StudentGradeInfo.h"
#include <iostream>

StudentGradeInfo::StudentGradeInfo(std::string name) : StudentInfo(name)
{
	//StudentInfo StudentInfo(name);
}

StudentGradeInfo::~StudentGradeInfo()
{
}

void StudentGradeInfo::AddGrade(int n)
{
	if (grades.size() < 5) // maxes amount of grades at 5
	{
		if (n <= 100 && n >= 0)
		{
			grades.push_back(n);
		}
		else
		{
			throw std::invalid_argument("Grades cannot be negative or greater than 100.");
		}

	}

}

int StudentGradeInfo::GetGradeAtIndex(int index) // print grade at index
{
	if (index < grades.size())
	{
		return grades[index];
	}
	
}

int StudentGradeInfo::GetAmountOfGrades()
{
	return grades.size();
}

bool StudentGradeInfo::PrintAllGrades()
{
	if (grades.size() > 0)
	{
		for (int i : grades) // iterates through all grades
		{
			std::cout << i << '\n';
		}
		return true; // verifies there were grades to print
	}
	else
	{
		std::cout << "There were no grades." << '\n';
		return false; // flags no grades were available to print
	}
}

void StudentGradeInfo::PrintAllGradesAndAvg()
{
	if (PrintAllGrades())
	{
		std::cout << "The average is: " << CalcAvg() << '\n';
	}

}

bool StudentGradeInfo::operator==(StudentGradeInfo * sgi)
{
	if (this->GetStudentID() == sgi->GetStudentID())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool StudentGradeInfo::operator<(StudentGradeInfo * sgi) // overload allows the std::sort to function with sgi objects
{
	return this->GetStudentID() < sgi->GetStudentID();
}

double StudentGradeInfo::CalcAvg()
{
	int avg = 0;

	for (int i : grades)
	{
		avg += i; // calculates total of all grades
	}

	return double(avg) / double(grades.size()); // divides total by number of grades
}

