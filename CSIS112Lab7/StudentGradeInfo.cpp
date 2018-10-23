#include "stdafx.h"
#include "StudentGradeInfo.h"
#include <iostream>

StudentGradeInfo::StudentGradeInfo(std::string name)
{
	StudentInfo StudentInfo(name);
}

StudentGradeInfo::~StudentGradeInfo()
{
}

void StudentGradeInfo::AddGrade(int n)
{
	if (n < 100 && n > 0)
	{
		grades.push_back(n);
	}
	else
	{
		throw std::invalid_argument("Grades cannot be negative or greater than 100.");
	}
	
}

int StudentGradeInfo::GetGradeAtIndex(int index) // print grade at index
{
	if (index < grades.size())
	{
		return grades[index];
	}
	
}

void StudentGradeInfo::PrintAllGrades()
{
	for (int i : grades) // iterates through all grades
	{
		std::cout << i << '\n';
	}
}

void StudentGradeInfo::PrintAllGradesAndAvg()
{
	PrintAllGrades();
	std::cout << "The average is :" <<  CalcAvg() << '\n';
}

bool StudentGradeInfo::operator==(StudentGradeInfo & sgi)
{
	if (this->GetStudentID() == sgi.GetStudentID())
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool StudentGradeInfo::operator<(StudentGradeInfo & sgi)
{
	return this->GetStudentID() < sgi.GetStudentID();
}

int StudentGradeInfo::CalcAvg()
{
	int avg;

	for (int i : grades)
	{
		avg += i; // calculates total of all grades
	}

	return avg / grades.size(); // divides total by number of grades
}

std::ostream & operator<<(std::ostream & out, StudentGradeInfo & sgi)
{
	out << "Student name: " << sgi.GetStudentName() << '\n';
	out << "Student ID: " << sgi.GetStudentID() << '\n';
	out << "Student Major: " << sgi.GetMajor() << '\n';
	out << "Student grades and average:";
	sgi.PrintAllGradesAndAvg();

	return out;
}