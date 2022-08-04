#include "CountingSort.h"
#include <iostream>

using namespace std;

countSort::countSort()
{

}

int countSort::findMax(vector<int> unSorted, int size)
{
	int max = unSorted[0];

	for (int i = 1; i < size; i++)
	{
		if (unSorted[i] > max)
		{
			max = unSorted[i];
		}
	}

	return max;
}

void countSort::buildOutput(vector<int> unSorted, int size)
{
	int max = findMax(unSorted, size);

	vector<int> counter(max + 1);
	vector<int> output(size);

	for (int i = 0; i <= max; i++)
	{
		counter[i] = 0;
	}

	// Store the count of each object
	for (int i = 0; i < size; i++)
	{
		counter[unSorted[i]]++;
	}
	
	// something
	for (int i = 1; i <= max; i++)
	{
		counter[i] += counter[i - 1];
	}


	// Build output unSorted
	for (int i = size - 1; i >= 0; i--)
	{
		output[counter[unSorted[i]] - 1] = unSorted[i];
		counter[unSorted[i]]--;
	}

	for (int i = 0; i < size; i++)
	{
		cout << output[i] << ", ";
	}

}