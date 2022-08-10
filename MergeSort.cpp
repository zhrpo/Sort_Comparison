//#ifndef MERGESORT_H
//#define MERGESORT_H
#include <vector>

using namespace std;

namespace MergeSort
{
	void MergeSortIntervals(vector<int>& v, int left, int right, int mid)
	{
		//Create a temp vector to store the vector obtained by merging
		vector<int> temp;

		int i, j;
		i = left;
		j = mid + 1;

		while (i <= mid && j < right) //This loop compairs the values from vectors i and j and sorts depending on which is smaller.
		{
			if (v[i] <= v[j])
			{
				temp.push_back(v[i]);
				i++;
			}
			else
			{
				temp.push_back(v[j]);
				j++;
			}
		}
		while (i <= mid) {   // if vector j is empty keeps pushing vector i elements
			temp.push_back(v[i]);
			i++;
		}
		while (j <= right) {  // if vector i is empty pushes vector j elements
			temp.push_back(v[j]);
			j++;
		}
		for (int i = left; i <= right; i++) {
			v[i] = temp[i - left];
		}

	}
	//Merge Sort Function it cuts the vector in two from left to mid to mid +1 to right

	void MergeSort(vector<int>& v, int left, int right)
	{
		if (left < right) {
			int mid = (left + right) / 2;
			MergeSort(v, left, mid);
			MergeSort(v, mid + 1, right);
			MergeSortIntervals(v, left, mid, right);
		}
	}


}
//#endif  //MERGESORT_H