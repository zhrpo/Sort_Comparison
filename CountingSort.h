#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

#include<vector>
#include<iostream>

using namespace std;

namespace countSort
{
	// Find the biggest number in the data
	int findMax(vector<int> unSorted, int size)
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

	// Build the new sorted list
	void buildOutput(vector<int> unSorted, int size)
	{
		int max = findMax(unSorted, size);

		// Initialize Counting and Output vectors
		vector<int> counter(max + 1);
		vector<int> output(size);

		// Store the count of each object in counter vector
		for (int i = 0; i < size; i++)
		{
			counter[unSorted[i]]++;
		}

		// Move counter elements to contain intended position of a value for the sorted vector
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

		/*
		// Output the sorted vector
		for (int i = 0; i < size; i++)
		{
			cout << output[i] << endl;
		}
		*/
	}
}

#endif /* COUNTINGSORT_H*/

