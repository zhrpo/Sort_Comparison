#include <iostream>
#include <chrono> // To measure execution time
#include <fstream> // To open txt file
#include <string> // to iterate through file
#include <vector>
#include "CountingSort.h" 

using namespace std::chrono;

int main()
{
	ifstream datafile;
	string line;
	vector<int> unSorted;
	int size = 0, index = 0;

	// Open the given data file
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
	unSorted.resize(size+1);

	// Clear and re-open the data file
	datafile.clear();
	datafile.open("CSCI2320_final_project_dataset.txt"); 
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return 0;
	}

	// Insert each oject from the data file into unSorted vector
	while (!datafile.eof()) 
	{
		datafile >> unSorted[index];
		if (datafile.fail())
			break;
		index++;
	}
	datafile.close();
	datafile.clear();

	// Counting Sort Algorithm
	auto start = high_resolution_clock::now();
	countSort::buildOutput(unSorted, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << endl << size;

	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << duration.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << duration.count()/1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(duration.count() / 1000)/1000) << endl;


	return 0;
}