#ifndef TIMSORT_H
#define TIMSORT_H

namespace TimSort
{	
	int getMinRun(int size)
	{
		int run = 0;
		while (size >= 64)
		{
			run |= size & 1;
			size >>= 1;
		}

		return size + run;
	}

	vector<int> timSort(vector <int> vUnsorted, int size)
	{
		vector<int> vSorted(size);
			vSorted = vUnsorted;
			int run = getMinRun(size);

			// Portions of vSorted that have a size of RUN will be sorted through the insertion algorithm
			for (int i = 0; i < size; i += run)
				vSorted = InsertSort::insertSort(vSorted, size, i, min((i + run - 1), (size - 1)));
			
			for (int length = run; length < size; length = 2 * length)
			{
				// left is the start point of the left portion
				for (int left = 0; left < size; left += 2 * length)
				{
					// mid is the end point of the left portion
					int mid = left + length - 1;
					// right is the end point of the right portion
					int right = min((left + 2 * length - 1), (size - 1));

					// merge the two portions
					if (mid < right)
					{
						MergeSort::MergeSortIntervals(vSorted, left, mid, right);
					}
				}
			}
			return vSorted;
	}
}
#endif /* TIMSORT_H*/