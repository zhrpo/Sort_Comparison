#include <iostream>
#include <fstream> // To open txt file
#include <string> // to iterate through file
#include <vector>
#include "toVector.h"

toVector::toVector()
{
	datafile;
	fileName = "";
	unSorted;
	size = NULL;
}

void toVector::setFileName(string name)
{
	fileName = name;
}

void toVector::setSize()
{
	string line;


	// Open the given data file
	//datafile.open("test.txt"); 
	datafile.open(fileName);
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return;
	}

	// Find and set the size of the given data file
	while (getline(datafile, line))
		++size;
	datafile.close();

	// Resize the vector to the newfound size
	unSorted.resize(size);
}

void toVector::setVector()
{
	int index = 0;

	// Clear and re-open the data file
	datafile.clear();
	//datafile.open("test.txt"); 
	datafile.open(fileName);
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return;
	}

	// Insert each oject from the data file into unSorted vector
	while (index < size)
	{
		datafile >> unSorted[index];
		if (datafile.fail())
			break;
		index++;
	}
	datafile.close();
	datafile.clear();
}

int toVector::getSize()
{
	setSize();
	return size;
}

vector<int> toVector::getVector()
{
	setVector();
	return unSorted;
}