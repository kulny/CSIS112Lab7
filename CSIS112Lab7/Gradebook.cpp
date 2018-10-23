#include "stdafx.h"
#include "Gradebook.h"


Gradebook::Gradebook()
{
}


Gradebook::~Gradebook()
{
}

int Gradebook::GetNumStudents()
{
	return students.size();
}

void Gradebook::AddStudent(StudentGradeInfo& sgi)
{
	bool studentExists;
	for (StudentGradeInfo i : students) // checks if studentID already exists
	{
		if (i.GetStudentID != sgi.GetStudentID())
		{
			studentExists = false;
		}
		else
		{
			studentExists = true;
		}
	}
	if (!studentExists) // ! for intuitive
	{
		students.push_back(sgi);
	}
}

void Gradebook::SortStudents()
{
	std::sort(students.begin(), students.end());
}

void Gradebook::PrintAllRecords()
{
	SortStudents();
	for (StudentGradeInfo i : students)
	{
		std::cout << i;
	}
}
