#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define CMAX 10 // CMAX with the constant value of 10

// Function to display result
void displayResult(string StudentID, int numCAnswers, double TMarks)
{
	cout << "\n---------------------------------\n";
	cout << "|   STUDENTS EXAM TEST RESULT   |" << endl;
	cout << "---------------------------------\n\n";
	cout << "Student ID: " << StudentID << endl;
	cout << "Total Score: " << numCAnswers << "/10" << endl;
	cout << "Total Marks: " << TMarks << "%" << endl;
}

// Function to open file testAnswers.txt
bool openRTAnswers(string, ifstream& readTAnswers)
{
	readTAnswers.open("testAnswers.txt");

	// Check if the file can be open
	if (readTAnswers.fail())
	{
		// If file cant be open, display error
		cerr << "File testAnswers.txt cannot be opened !" << endl;
		return 1;
	}
	return false;
}

// Function to open file CorrectAnswers.txt
bool openRCAnswers(string, ifstream& readCAnswers)
{
	readCAnswers.open("CorrectAnswers.txt");

	// Check if the file can be open
	if (readCAnswers.fail())		
	{
		// If file cant be open, display error
		cerr << "File CorrectAnswers.txt cannot be opened !" << endl;		
		return 1;
	}
	return false;
}

int main()
{
	// Declaration
	ifstream readCAnswers;
	ifstream readTAnswers;
	ofstream writeSMarks("studentMarks.txt");
	string StudentID;
	bool fileCAnswers, fileTAnswers;
	char CAnswers[CMAX], SAnswers[CMAX];
	double TMarks = 0;
	int Num = 1;

	// Calling function for input files
	fileCAnswers = openRCAnswers("CorrectAnswers.txt", readCAnswers);
	fileTAnswers = openRTAnswers("testAnswers.txt", readTAnswers);

	for (int i = 0; i < CMAX; i++)
	{
		// Insert content of CorrectAnswers.txt into CAnswers array
		readCAnswers >> CAnswers[i];	
	}
	
	// Insert student id from testAnswers.txt to StudentID string
	while (readTAnswers >> StudentID)	
	{
		
		int numCAnswers = 0;
		for (int i = 0; i < CMAX; i++)
		{
			// Insert content of testAnswers.txt to SAnwers array
			readTAnswers >> SAnswers[i];	
			
			// Compare array SAnswers with CAnswers
			if (SAnswers [i] == CAnswers [i])		
			{
				numCAnswers++;
			}

		}

		// Calculate total score 
		TMarks = (double) numCAnswers / CMAX * 10;

		// Display result
		displayResult(StudentID, numCAnswers, TMarks);
		
		// Write result inside file studentMarks.txt
		writeSMarks << "\n---------------------------------\n"
			<< "|   STUDENTS EXAM TEST RESULT   |" << endl
			<< "---------------------------------\n\n"
			<< "Student ID: " << StudentID << endl
			<< "Total Score: " << numCAnswers << "/10" << endl
			<< "Total Marks: " << TMarks << "%" << endl;

	}

	// Close all files
	readCAnswers.close();
	readTAnswers.close();
	writeSMarks.close();

	return 0;
}