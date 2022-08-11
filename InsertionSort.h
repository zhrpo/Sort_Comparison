#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

namespace InsertSort
{
	vector<int> insertSort(vector<int> unSorted, int size, int left, int right)
	{

		int key, j;
		vector<int> vSorted(size); // Sub-array
		vSorted = unSorted;

		for (int i = left + 1; i <= right; i++)
		{
			key = vSorted[i];
			j = i - 1;

			while (j >= left && vSorted[j] > key) // Move elements > key one index ahead
			{
				vSorted[j + 1] = vSorted[j];
				--j;
			}
			vSorted[j + 1] = key;
		}
		return vSorted;
	}
}
#endif /* INSERTIONSORT_H*/