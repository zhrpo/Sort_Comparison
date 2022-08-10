#pragma once
/*-- QuickSort.h ---------------------------------------------------------------
  This header file defines the QuickSort class
-------------------------------------------------------------------------*/
#ifndef QUICKSORT_H
#define QUICKSORT_H

using namespace std;

namespace QuickSort
{
    int split(vector<int> QuickSortArray, int first, int end) //swaps the data around to find the smallest value
    {

        int pivot = QuickSortArray[first];

        int count = 0;
        for (int i = first + 1; i <= end; i++)
        {
            if (QuickSortArray[i] <= pivot)
            {
                count++;
            }
        }



        int pivotValue = first + count;
        swap(QuickSortArray[pivotValue], QuickSortArray[first]);


        int left = first;
        int right = end;

        while (left < pivotValue && right > pivotValue)
        {
            if (left < pivotValue && right > pivotValue)
            {
                swap(QuickSortArray[left++], QuickSortArray[right--]);
            }
            while (QuickSortArray[left] <= pivot)
            {
                left = left++;
            }
            while (QuickSortArray[right] > pivot)
            {
                right = right--;
            }
        }

        return pivotValue;
    }

    void Sort(vector<int> QuickSortArray, int first, int end) //sorts data from the array
    {
        if (first >= end)
        {
            return;
        }

        int p = split(QuickSortArray, first, end);//pulls the first and last to swap out until it in numerical order
        Sort(QuickSortArray, first, p - 1);
        Sort(QuickSortArray, p + 1, end);

    }

    void display(vector<int> QuickSortArray, int n) //displays the array
    {
        for (int i = 0; i < n; ++i)
        {
            cout << QuickSortArray[i] << " ";
            cout << "\n";
        }

    }

    vector<int> getVector(vector<int> QuickSortArray, int first, int end)
    {
        Sort(QuickSortArray, first, end);

        return QuickSortArray;
    }
}
#endif // !QUICKSORT_H
