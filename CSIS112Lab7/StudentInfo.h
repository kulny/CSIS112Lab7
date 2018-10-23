#pragma once

#include <string>
#include <exception>

class StudentInfo
{
public:
	StudentInfo(std::string name = "");
	~StudentInfo();

	// setters

	void SetStudentName(std::string* name);
	void SetStudentID(int n);
	void SetMajor(std::string major);

	// getters

	std::string GetStudentName();
	int GetStudentID();
	std::string GetMajor();

private:
	std::string* studentName;
	int studentID;
	std::string major;

};

