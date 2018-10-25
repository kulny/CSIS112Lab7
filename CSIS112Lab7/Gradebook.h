#pragma once
#include <vector>
#include "StudentGradeInfo.h"
#include <algorithm>

class Gradebook
{
public:
	Gradebook();
	~Gradebook();

	int GetNumStudents();
	void AddStudent(StudentGradeInfo& sgi);
	void PrintAllRecords();

private:
	std::vector<StudentGradeInfo> students;

	void SortStudents();
};

std::ostream & operator<<(std::ostream & out, StudentGradeInfo & sgi);