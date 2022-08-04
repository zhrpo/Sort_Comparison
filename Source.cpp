#include <iostream>
#include <chrono> // To measure execution time
#include <fstream> // To open txt file
#include <string> // to iterate through file
#include <vector>
#include "CountingSort.h" 
#include "InsertionSort.h"
#include "toVector.h"

using namespace std::chrono;

int main()
{
	toVector Unsorted;
	string name = "CSCI2320_final_project_dataset.txt";
	//string name = "test.txt";
	
	Unsorted.setFileName(name);
	int size = Unsorted.getSize();
	vector<int> vUnsorted = Unsorted.getVector();
	

	
	// Counting Sort Algorithm
	auto startCS = high_resolution_clock::now();
	vector<int> counting = countSort::buildOutput(vUnsorted, size);
	auto stopCS = high_resolution_clock::now();
	auto durationCS = duration_cast<microseconds>(stopCS - startCS);

	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << durationCS.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << durationCS.count()/1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(durationCS.count() / 1000)/1000) << endl;
	
	// Insertion Sort Algorithm
	auto startIS = high_resolution_clock::now();
	vector<int> insert = InsertSort::insertSort(vUnsorted, size);
	auto stopIS = high_resolution_clock::now();
	auto durationIS = duration_cast<microseconds>(stopIS - startIS);

	cout << endl;
	cout << endl << "Insertion Sort Duration (microseconds): " << durationIS.count() << endl;
	cout << endl << "Insertion Sort Duration (milliseconds): " << durationIS.count() / 1000 << endl;
	cout << endl << "Insertion Sort Duration (seconds): " << double(double(durationIS.count() / 1000) / 1000) << endl;

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