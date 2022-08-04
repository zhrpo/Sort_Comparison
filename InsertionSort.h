#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

using namespace std;

namespace InsertSort
{
	vector<int> insertSort(vector<int> unSorted, int size)
	{
		int key, j;
		int loading = size / 100; // Finds 1% of the size
		vector<int> vSorted(size);
		vSorted = unSorted;

		cout << endl << "Loading..." << endl;
		cout << "____________________________________________________________________________________________________" << endl;

		for (int i = 0; i < size; i++)
		{
			key = vSorted[i];
			j = i - 1;

			while (j >= 0 && vSorted[j] > key)
			{
				vSorted[j + 1] = vSorted[j];
				j--;
			}
			vSorted[j + 1] = key;

			// Absolutely unnecessary and primative loading screen
			// But its better than wondering if the program is working or not
			if (i == loading)
			{
				cout << "|";
				loading += (size / 100);
			}
		}

		/*
		for (int i = 0; i < size; i++)
		{
			cout << vSorted[i] << endl;
		}
		*/

		return vSorted;
	}
}

#endif /* INSERTIONSORT_H*/