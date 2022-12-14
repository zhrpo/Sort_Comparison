#ifndef COUNTINGSORT_H
#define COUNTINGSORT_H

namespace CountSort
{
	// Find the biggest number in the data
	int findMax(vector<int> unSorted, int size)
	{
		int max = unSorted[0];

		for (int i = 1; i < size; i++)
		{
			if (unSorted[i] > max)
				max = unSorted[i];
		}
		return max;
	}

	// Build the new sorted list
	vector<int> buildOutput(vector<int> unSorted, int size)
	{
		int max = findMax(unSorted, size);

		// Initialize Counting and Output vectors
		vector<int> counter(max + 1);
		vector<int> output(size);

		// Store the count of each object in counter vector
		for (int i = 0; i < size; i++)
			counter[unSorted[i]]++;

		// Store the cummulative count 
		for (int i = 1; i <= max; i++)
			counter[i] += counter[i - 1];

		// Place the elements into the output array
		for (int i = size - 1; i >= 0; i--)
		{
			output[counter[unSorted[i]] - 1] = unSorted[i];
			counter[unSorted[i]]--;
		}
		return output;
	}
}
#endif /* COUNTINGSORT_H*/

