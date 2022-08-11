/*-- QuickSort.h ---------------------------------------------------------------
  This header file defines the QuickSort class
-------------------------------------------------------------------------*/
#ifndef QUICKSORT_H
#define QUICKSORT_H

namespace QuickSort
{
    int split(vector<int>& QuickSortArray, int first, int end) //swaps the data around to find the smallest value
    {

        int pivot = QuickSortArray[end];

        int count = first - 1;

        for (int i = first; i < end; i++)
        {
            if (QuickSortArray[i] <= pivot)
            {
                count++;
                swap(QuickSortArray[count], QuickSortArray[i]);
            }
        }
        swap(QuickSortArray[count + 1], QuickSortArray[end]);

        return (count + 1);
    }
  
    void Sort(vector<int>& QuickSortArray, int first, int end) //sorts data from the array
    {
        if (first < end)
        {
            int pivot = split(QuickSortArray, first, end);
            Sort(QuickSortArray, first, pivot - 1);
            Sort(QuickSortArray, pivot + 1, end);
        }
    }
}
#endif // !QUICKSORT_H
