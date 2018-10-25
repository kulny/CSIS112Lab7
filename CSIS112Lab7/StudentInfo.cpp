#include "stdafx.h"
#include "StudentInfo.h"

StudentInfo::StudentInfo(std::string name)
{
	std::string* studentName = new std::string{ name };
	SetStudentName(studentName);
}

StudentInfo::~StudentInfo()
{
	delete studentName;
}

void StudentInfo::SetStudentName(std::string* name)
{
	this->studentName = name;
}

void StudentInfo::SetStudentID(int n)
{
	this->studentID = n;
}

void StudentInfo::SetMajor(std::string major)
{
	this->major = major;
}

std::string StudentInfo::GetStudentName()
{
	return *this->studentName;
}

int StudentInfo::GetStudentID()
{
	return studentID;
}

std::string StudentInfo::GetMajor()
{
	return this->major;
}
