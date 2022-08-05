#include <iostream>
#include <chrono> // To measure execution time
#include <fstream> // To open txt file
#include <string> // To iterate through file
#include <vector> // To create vectors
#include "toVector.h"
#include "InsertionSort.h"
#include "CountingSort.h" 
//#include "TimSort.h"

using namespace std::chrono;

int main()
{
	//string name = "CSCI2320_final_project_dataset.txt";
	string name = "test.txt"; // Much shorter datafile for testing purposes
	
	// Getting unsorted vector from given data file
	toVector Unsorted;	
	Unsorted.setFileName(name);
	int size = Unsorted.getSize();
	vector<int> vUnsorted = Unsorted.getVector();
	
	// --Insertion Sort Algorithm-- O(n^2) //
	auto startIS = high_resolution_clock::now();
	vector<int> insert = InsertSort::insertSort(vUnsorted, size, 0, size - 1);
	auto stopIS = high_resolution_clock::now();
	auto durationIS = duration_cast<microseconds>(stopIS - startIS);

	cout << endl;
	cout << endl << "Insertion Sort Duration (microseconds): " << durationIS.count() << endl;
	cout << endl << "Insertion Sort Duration (milliseconds): " << durationIS.count() / 1000 << endl;
	cout << endl << "Insertion Sort Duration (seconds): " << double(double(durationIS.count() / 1000) / 1000) << endl;


	// --Heap Sort Algorithm-- O(nlog(n)) //

	// --Merge Sort Algorithm-- O(nlog(n)) //

	// --Quick Sort Algorithm-- O(nlog(n)) //


	// --Counting Sort Algorithm-- O(n) //
	auto startCS = high_resolution_clock::now();
	vector<int> counting = CountSort::buildOutput(vUnsorted, size);
	auto stopCS = high_resolution_clock::now();
	auto durationCS = duration_cast<microseconds>(stopCS - startCS);

	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << durationCS.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << durationCS.count()/1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(durationCS.count() / 1000)/1000) << endl;

	/*
	// --TimSort Algorithm-- O(nlog(n)) //
	auto startTS = high_resolution_clock::now();
	vector<int> tim = TimSort::timSort(vUnsorted, size);
	auto stopTS = high_resolution_clock::now();
	auto durationTS = duration_cast<microseconds>(stopTS - startTS);

	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << durationTS.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << durationTS.count() / 1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(durationTS.count() / 1000) / 1000) << endl;
	*/

	// Checking if the algorithms built matching vectors
	if (insert == counting)
	{
		cout << "YES";
	}
	else
	{
		cout << "NOPE. something is broken";
	}
	return 0;
}