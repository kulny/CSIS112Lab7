//Gradebook 2 -- gradebook management
//CSIS 112-<Section Number>
//ComparePointer struct used for std::sort to compare pointer objects in StudentGradeObject vector inspired from stackoverflow


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
StudentGradeInfo* GetRecordsInput(std::string studentName, int studentID, std::string major);
std::string InputName();
int InputID();
std::string InputMajor();

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
			std::string name = InputName();
			int ID = InputID();

			if (gbook == ID) // prevents the user from having to continue entering information if the student ID already exists in the gradebook
			{
				std::cout << "A student with that ID already exists.\n";
				break;
			}

			std::string major = InputMajor();


			StudentGradeInfo* sgiPtr = GetRecordsInput(name, ID, major);
			gbook.AddStudent(sgiPtr); // adds student with records taken from get record input
			//delete sgiPtr; // deletes dynamically allocated object since all data is stored in gradebook
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

StudentGradeInfo * GetRecordsInput(std::string studentName, int studentID, std::string major)
{
	bool moreGrades = false; // used for when to stop grade input loop
	int totalGrades = 0; // used for less than 5 grades
	int grade;
	std::string query;

	StudentGradeInfo* sgiPtr = new StudentGradeInfo(studentName); // allocates dynamic var for object to prevent out of scope destruction
	// ***** POINTERS ARE DELETED THROUGH GRADEBOOK DESTRUCTOR *****
	sgiPtr->SetStudentID(studentID);
	sgiPtr->SetMajor(major);

	do
	{
		cout << "Please enter a grade for the student." << '\n';
		cin >> grade;
		try // checks to see if grade is positive or less than 100
		{
			sgiPtr->AddGrade(grade);
		}
		catch (const std::invalid_argument e)
		{
			cout << e.what() << '\n'; // prints err msg
		}

		// bool query for grade input loop
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
		totalGrades = sgiPtr->GetAmountOfGrades();
	} while (moreGrades && totalGrades < 5);

	return sgiPtr;
}

std::string InputName()
{
	std::string studentName;

	cin.ignore(); // clear buffer for getline

	std::cout << "Please input student name." << '\n';
	std::getline(cin, studentName);

	return studentName;
}

int InputID()
{
	int studentID;

	std::cout << "Please input student ID." << '\n';
	std::cin >> studentID;
	
	return studentID;
}

std::string InputMajor()
{
	std::string major;

	cin.ignore(); // clear buffer for getline

	std::cout << "Please input student major." << '\n';
	std::getline(cin, major);

	return major;
}
