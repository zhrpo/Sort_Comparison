#ifndef MERGESORT_H
#define MERGESORT_H

namespace MergeSort
{
	void MergeSortIntervals(vector<int>& sortedV, int left, int mid, int right)
	{
		int VOne = mid - left + 1;
		int VTwo = right - mid;

		vector<int> leftSub(VOne), rightSub(VTwo);

		for (int i = 0; i < VOne; i++)
			leftSub[i] = sortedV[left + i];
		for (int j = 0; j < VTwo; j++)
			rightSub[j] = sortedV[mid + 1 + j];

		int i = 0, j = 0, k = left;

		while (i < VOne && j < VTwo)
		{
			if (leftSub[i] <= rightSub[j])
			{
				sortedV[k] = leftSub[i];
				i++;
			}
			else
			{
				sortedV[k] = rightSub[j];
				j++;
			}
			k++;
		}

		while (i < VOne)
		{
			sortedV[k] = leftSub[i];
			i++;
			k++;
		}

		while (j < VTwo)
		{
			sortedV[k] = rightSub[j];
			j++;
			k++;
		}
	

	}
	//Merge Sort Function it cuts the vector in two from left to mid to mid +1 to right
	void MergeSort(vector<int>& v, int left, int right)
	{
		if (left >= right)
			return;

			int mid = left + (right - left)/2;
			MergeSort(v, left, mid);
			MergeSort(v, mid + 1, right);
			MergeSortIntervals(v, left, mid, right);
	}
}
#endif  //MERGESORT_H