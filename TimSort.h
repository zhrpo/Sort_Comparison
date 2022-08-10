
#ifndef TIMSORT_H
#define TIMSORT_H

using namespace std;
const int RUN = 32;

namespace TimSort
{
	vector<int> timSort(vector <int> vUnsorted, int size)
	{
		vector<int> vSorted(size);
			vSorted = vUnsorted;

			// Portions of vSorted that have a size of RUN will be sorted through the insertion algorithm
			for (int i = 0; i < size; i += RUN)
				vSorted = InsertSort::insertSort(vSorted, size, i, min((i + RUN - 1), (size - 1)));
			

			for (int length = RUN; length < size; length = 2 * length)
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
						vSorted = MergeSort::MergeSort(vSorted, left, right);
					}
				}
			}
			return vSorted;
	}
}
#endif /* TIMSORT_H*/