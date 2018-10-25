#pragma once
#include <vector>
#include "StudentGradeInfo.h"
#include <algorithm>

class Gradebook
{
public:
	Gradebook();
	~Gradebook(); // deletes pointers in students vector 

	int GetNumStudents();
	void AddStudent(StudentGradeInfo* sgi);
	void PrintAllRecords();

private:
	std::vector<StudentGradeInfo*> students;

	void SortStudents();


};

std::ostream & operator<<(std::ostream & out, StudentGradeInfo * sgi);

struct ComparePointers // allows sorting students array -- required since array is full of pointers
{ // provides a third parameter to std::sort in gradebook.cpp such that std::sort knows how to compare two pointers

	bool operator()(StudentGradeInfo* left, StudentGradeInfo* right) {
		return *left < right; // left side is de-referenced since comparison can only be between a de-referenced object and a pointer, not two pointers
		// since two pointers cannot be compared, this struct is necessary
	}
};