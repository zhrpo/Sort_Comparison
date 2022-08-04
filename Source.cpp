#include <iostream>
#include <chrono> // To measure execution time
#include <fstream> // To open txt file
#include <string> // to iterate through file
#include <vector>
#include "CountingSort.h" 
#include "InsertionSort.h"

using namespace std::chrono;

int main()
{
	ifstream datafile;
	string line;
	vector<int> unSorted;
	int size = 0, index = 0;

	// Open the given data file
	//datafile.open("test.txt"); 
	datafile.open("CSCI2320_final_project_dataset.txt");
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return 0;
	}

	// Find and set the size of the given data file
	while (getline(datafile, line)) 
	{
		++size;
	}
	datafile.close();

	// Resize the vector to the newfound size
	unSorted.resize(size);

	// Clear and re-open the data file
	datafile.clear();
	//datafile.open("test.txt"); 
	datafile.open("CSCI2320_final_project_dataset.txt");
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return 0;
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

	cout << endl << size;

	/*
	// Counting Sort Algorithm
	auto startCS = high_resolution_clock::now();
	countSort::buildOutput(unSorted, size);
	auto stopCS = high_resolution_clock::now();
	auto durationCS = duration_cast<microseconds>(stopCS - startCS);

	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << durationCS.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << durationCS.count()/1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(durationCS.count() / 1000)/1000) << endl;
	*/

	// Insertion Sort Algorithm
	auto startIS = high_resolution_clock::now();
	InsertSort::insertSort(unSorted, size);
	auto stopIS = high_resolution_clock::now();
	auto durationIS = duration_cast<microseconds>(stopIS - startIS);

	cout << endl;
	cout << endl << "Insertion Sort Duration (microseconds): " << durationIS.count() << endl;
	cout << endl << "Insertion Sort Duration (milliseconds): " << durationIS.count() / 1000 << endl;
	cout << endl << "Insertion Sort Duration (seconds): " << double(double(durationIS.count() / 1000) / 1000) << endl;

	return 0;
}