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

#include "Encryption.h"

// ------ Constructors/Destructors ------

// Default constructor
Encryption::Encryption()
{
	mInputFileName = "";
	mOutputFileName = "";
	mKey = -1;
}

// Constructor
Encryption::Encryption(string input, string output, int key)
{
	mInputFileName = input;
	mOutputFileName = output;
	mKey = key;
}

// Copy constructor
Encryption::Encryption(Encryption& obj)
{
	mInputFileName = obj.mInputFileName;
	mOutputFileName = obj.mOutputFileName;
	mKey = obj.mKey;
}

// Destructor
Encryption::~Encryption()
{

}

// ------ Getters/Setters ------

/* Function:   getKey
*  Purpose:    returns the object's key
*  Pre:        Encryption must be initialized
*  Post:       value of key is returned
****************************************************************/
int Encryption::getKey()
{
	return mKey;
}

/* Function:   setKey
*  Purpose:    sets the object's key to a desired value
*  Pre:        Encryption must be initialized
*  Post:       value of key is changed
****************************************************************/
void Encryption::setKey(int key)
{
	mKey = key;
}


// ------ Member functions ------

/* Function:   encrypt
*  Purpose:    encrypts the object's input file
*  Pre:        Encryption must be initialized and input file specified
*  Post:       input file is encrypted
****************************************************************/
void Encryption::encrypt()
{
	ifstream iFile;
	ofstream oFile;
	string data,eData;

	iFile.open(mInputFileName);
	if (iFile.fail())
	{
		cout << "Failed to open '" << mInputFileName << "' In encrypt()\n";
		exit(1);
	}
	// Input data from file and encrypt it
	getline(iFile, data);
	for (int i = 0; i < data.length(); i++)
	{
		// Calls the transform function for every letter in the string and stores the encrypted value in eData
		eData += transform(data[i]);
	}
	iFile.close();
	//cout << endl << eData << endl;

	oFile.open(mOutputFileName, ios :: app);
	if (oFile.fail())
	{
		cout << "Failed to open '" << mOutputFileName << "' In encrypt()\n";
		exit(1);
	}

	oFile << eData << endl;
	oFile.close();
	return;
}