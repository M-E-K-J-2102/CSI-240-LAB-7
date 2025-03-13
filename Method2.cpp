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

#include "Method2.h"

// ------Constructors/Destructors ------

// Default constructor
Method2::Method2() : Encryption()
{

}

// Constructor
Method2::Method2(string input, string output) : Encryption(input, output, -1)
{

}

// Copy constructor
Method2::Method2(Method2& obj) : Encryption(obj)
{
	// Use xor to transform characters
}

// Destructor
Method2::~Method2()
{

}

char Method2::transform(char letter)
{
	// Implement xor operation
	return letter ^ mKey;

}