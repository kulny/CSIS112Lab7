#include "stdafx.h"
#include "Gradebook.h"


Gradebook::Gradebook()
{
}


Gradebook::~Gradebook()
{
	for (StudentGradeInfo* i : students)
	{
		delete i;
	}
}

int Gradebook::GetNumStudents()
{
	return students.size();
}

void Gradebook::AddStudent(StudentGradeInfo* sgi)
{
	bool studentExists = false;
	for (StudentGradeInfo* i : students) // checks if studentID already exists
	{
		/*if (i->GetStudentID() != sgi->GetStudentID())
		{
			studentExists = false;
		}
		else
		{
			studentExists = true;
		}*/
		if (*i == sgi)
		{
			studentExists = true;
		}
		else
		{
			studentExists = false;
		}
	}
	if (!studentExists) // ! for intuitive var bool if student exists
	{
		students.push_back(sgi);
	}
}

void Gradebook::SortStudents() // sorts student vector of sgi* ID numbers from lowest to highest
{
	std::sort(students.begin(), students.end(), ComparePointers());
}




void Gradebook::PrintAllRecords()
{
	SortStudents();
	for (StudentGradeInfo* i : students)
	{
		std::cout << i;
	}
}

bool Gradebook::operator==(int n)
{
	for (StudentGradeInfo * i : students)
	{
		if (i->GetStudentID() == n)
		{
			return true;
		}
	}

	return false;
}


std::ostream & operator<<(std::ostream & out, StudentGradeInfo * sgi)
{
	out << "Student name: " << sgi->GetStudentName() << '\n';
	out << "Student ID: " << sgi->GetStudentID() << '\n';
	out << "Student Major: " << sgi->GetMajor() << '\n';
	out << "Student grades and average:\n";
	sgi->PrintAllGradesAndAvg();
	out << '\n';

	return out;
}
