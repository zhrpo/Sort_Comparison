#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H

using namespace std;

namespace InsertSort
{
	vector<int> insertSort(vector<int> unSorted, int size, int left, int right)
	{

		int key, j;
		vector<int> vSorted(size);
		vSorted = unSorted;

		int loading = size / 100; // Finds 1% of the size
		
		// Display loading screen
		cout << endl << "Loading..." << endl;
		cout << "____________________________________________________________________________________________________" << endl;

		//          [normally 1]  [normally size]
		for (int i = left + 1; i <= right; i++)
		{
			key = vSorted[i];
			j = i - 1;
			
			//       [normally 0]
			while (j >= left && vSorted[j] > key)
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