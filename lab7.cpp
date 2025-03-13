/*
Author:           Matthew Kane
Class:            CSI-240-04
Assignment:       Lab 7
Date Assigned:    2/4/2024
Due Date:         5/4/2024 @ 1:00 PM

Description:
A small program that deals with encryption and polymorphism

Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)
-----------------------------------------------------------------------------------------
Sources:
*/

#include "header.h"

int main()
{
	ifstream iFile;
	ofstream oFile;
	string in, out;
	int key;
	string data = "Bruh";

	// Ask user for i/o File and key
	cout << "Input file name: ";
	getline(cin, in);

	
	cout << "Output file name: ";
	getline(cin, out);

	cout << "Encryption key: ";
	cin >> key;

	// Create Method object
	Method1 obj(in, out);
	obj.setKey(key);

	Method2 meth(in, out);
	meth.setKey(key);

	// Open input file and check it works
	iFile.open(in);
	if (iFile.fail())
	{
		cout << "Failed to open'" << in << "'\n";
		exit(1);
	}
	iFile.close();

	// Encrypt data using both method classes
	// Method1
	obj.encrypt();

	// Method2
	meth.encrypt();

	return 0;
}