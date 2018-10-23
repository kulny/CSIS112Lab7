//Gradebook 2 -- gradebook management
//CSIS 112-<Section Number>
//<Sources if necessary>


//Include statements
#include "stdafx.h"
#include <iostream>
#include <string>
#include "StudentGradeInfo.h"
#include <iostream>
#include "Gradebook.h"


using namespace std;

//Global declarations: Constants and type definitions only -- NO variables
enum choices
{
	ADD, LIST, QUIT
};

//Function prototypes
void ChoiceMenu(choices menuChoice, Gradebook& gbook);
choices getChoice(bool& bquit);
StudentGradeInfo& GetRecordsInput();

int main()
{
	//In cout statement below substitute your name and lab number
	cout << "Cody Moore -- Lab Number 7" << endl << endl;

	//Variable declarations
	bool quit = false; // looping bool

	//Program logic

	Gradebook gradebook;

	do
	{
		std::cout << "What would you like to do? Add a student (A), List all students (L), or Quit (Q)." << std::endl;

		ChoiceMenu(getChoice(quit), gradebook); // gets user choices, flips bool on QUIT, and gives access to each feature A, L, Q
	} while (!quit); // quit is negated because in functions it is used in, it's more readable to have it become true rather than become false


	//Closing program statements
	system("pause");
	return 0;
}

//Function definitions

void ChoiceMenu(choices menuChoice, Gradebook& gbook) // reference to make sure gradebook can be changed within scope of other functions
{
	switch (menuChoice)
	{
	default:
		break;
	case ADD:
		if (gbook.GetNumStudents() < 3)
		{
			gbook.AddStudent(GetRecordsInput()); // adds student with records taken from get record input
		}
		else
		{
			std::cout << "There are already 3 students in the gradebook." << std::endl;
		}
		break;

	case LIST:
		gbook.PrintAllRecords();
		break;

	case QUIT:
		// getChoice already flips this bool, ending the loop. Leaving case to prevent ambiguity and misunderstanding.
		break;
	}
}

choices getChoice(bool& bquit)
{
	char userChoice;

	std::cin >> userChoice;

	if (userChoice == 'a' || userChoice == 'A')
	{
		return ADD;
	}
	else if (userChoice == 'l' || userChoice == 'L')
	{
		return LIST;
	}
	else if (userChoice == 'q' || 'Q')
	{
		bquit = true;
		return QUIT;
	}
	return choices();
}

StudentGradeInfo & GetRecordsInput()
{
	std::string studentName;
	int studentID;
	std::string major;
	bool moreGrades = false;
	int totalGrades = 0;
	int grade;
	std::string query;

	std::cout << "Please input student name." << '\n';
	std::getline(cin, studentName);

	std::cout << "Please input student ID." << '\n';
	std::cin >> studentID;

	std::cout << "Please input student major." << '\n';
	std::getline(cin, major);

	StudentGradeInfo sgi(studentName);
	sgi.SetStudentID(studentID);
	sgi.SetMajor(major);

	do
	{
		cout << "Please enter a grade for the student." << '\n';
		cin >> grade;
		sgi.AddGrade(grade);

		cout << "Would you like to add another grade? y/n" << '\n';
		cin >> query;
		if (query == "y" || query == "Y")
		{
			moreGrades = true;
		}
		else
		{
			moreGrades = false;
		}

	} while (moreGrades && totalGrades <= 5);

	return sgi;
}

