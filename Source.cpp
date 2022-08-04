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

	countSort cs1;

	datafile.open("CSCI2320_final_project_dataset.txt"); 
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return 0;
	}

	while (getline(datafile, line)) // Find and set the size of the txt file
	{
		++size;
	}
	datafile.close();

	unSorted.resize(size+1);

	datafile.clear();
	datafile.open("CSCI2320_final_project_dataset.txt"); 
	if (!datafile.is_open())
	{
		cout << "ERROR. File failed to open." << endl;
		return 0;
	}

	while (!datafile.eof()) // Insert each oject into the array
	{
		datafile >> unSorted[index];
		if (datafile.fail())
			break;
		index++;
	}
	datafile.close();
	datafile.clear();

	auto start = high_resolution_clock::now();
	cs1.buildOutput(unSorted, size);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);

	cout << endl << "Counting Sort Duration (milliseconds): " << duration.count() << endl;


	return 0;
}