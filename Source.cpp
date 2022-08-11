#include <iostream>
#include <chrono> // To measure execution time
#include <fstream> // To open txt file
#include <string> // To iterate through file
#include <vector> // To create vectors
#include "toVector.h"
#include "InsertionSort.h"
#include "CountingSort.h" 
#include "Heap_Sort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include "TimSort.h"

using namespace std::chrono;

int main()
{
	string name = "CSCI2320_final_project_dataset.txt";
	
	// Getting unsorted vector from given data file
	toVector Unsorted;	
	Unsorted.setFileName(name);
	int size = Unsorted.getSize();
	vector<int> vUnsorted = Unsorted.getVector();

	// vUnsorted copies for certain algorithms
	vector<int> merge = vUnsorted;
	vector<int> heap = vUnsorted;
	vector<int> quick = vUnsorted;


	// --Counting Sort Algorithm-- O(n) //
	auto startCS = high_resolution_clock::now();
	vector<int> counting = CountSort::buildOutput(vUnsorted, size);
	auto stopCS = high_resolution_clock::now();
	auto durationCS = duration_cast<microseconds>(stopCS - startCS);
	cout << endl;
	cout << endl << "Counting Sort Duration (microseconds): " << durationCS.count() << endl;
	cout << endl << "Counting Sort Duration (milliseconds): " << durationCS.count() / 1000 << endl;
	cout << endl << "Counting Sort Duration (seconds): " << double(double(durationCS.count() / 1000) / 1000) << endl;


	// --TimSort Algorithm-- O(nlog(n)) //
	auto startTS = high_resolution_clock::now();
	vector<int> tim = TimSort::timSort(vUnsorted, size);
	auto stopTS = high_resolution_clock::now();
	auto durationTS = duration_cast<microseconds>(stopTS - startTS);
	cout << endl;
	cout << endl << "TimSort Duration (microseconds): " << durationTS.count() << endl;
	cout << endl << "TimSort Duration (milliseconds): " << durationTS.count() / 1000 << endl;
	cout << endl << "TimSort Duration (seconds): " << double(double(durationTS.count() / 1000) / 1000) << endl;


	// --Merge Sort Algorithm-- O(nlog(n)) //
	auto startMS = high_resolution_clock::now();
	MergeSort::MergeSort(merge, 0, size - 1);
	auto stopMS = high_resolution_clock::now();
	auto durationMS = duration_cast<microseconds>(stopMS - startMS);
	cout << endl;
	cout << endl << "Merge Sort Duration (microseconds): " << durationMS.count() << endl;
	cout << endl << "Merge Sort Duration (milliseconds): " << durationMS.count() / 1000 << endl;
	cout << endl << "Merge Sort Duration (seconds): " << double(double(durationMS.count() / 1000) / 1000) << endl;


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
	auto startHS = high_resolution_clock::now();
	HSort::Sort(heap, size);
	auto stopHS = high_resolution_clock::now();
	auto durationHS = duration_cast<microseconds>(stopHS - startHS);
	cout << endl;
	cout << endl << "Heap Sort Duration (microseconds): " << durationHS.count() << endl;
	cout << endl << "Heap Sort Duration (milliseconds): " << durationHS.count() / 1000 << endl;
	cout << endl << "Heap Sort Duration (seconds): " << double(double(durationHS.count() / 1000) / 1000) << endl;

	
	// --Quick Sort Algorithm-- O(nlog(n)) //
	auto startQS = high_resolution_clock::now();
	QuickSort::Sort(quick, 0, size - 1);
	auto stopQS = high_resolution_clock::now();
	auto durationQS = duration_cast<microseconds>(stopQS - startQS);
	cout << endl;
	cout << endl << "Quick Sort Duration (microseconds): " << durationQS.count() << endl;
	cout << endl << "Quick Sort Duration (milliseconds): " << durationQS.count() / 1000 << endl;
	cout << endl << "Quick Sort Duration (seconds): " << double(double(durationQS.count() / 1000) / 1000) << endl;

	return 0;
}