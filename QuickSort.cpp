#include "QuickSort.h"
#include <cstddef>
#include <iostream>

using namespace std;

int QuickSort::split(int QuickSortArray[], int first, int end) //swaps the data around to find the smallest value
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

void QuickSort::Sort(int QuickSortArray[], int first, int end) //sorts data from the array
{
    if (first >= end)
    {
        return;
    }

    int p = split(QuickSortArray, first, end);//puls the first and last to swap out until it in numerical order
    Sort(QuickSortArray, first, p - 1);
    Sort(QuickSortArray, p + 1, end);
}

void QuickSort::display(int QuickSortArray[], int n) //displays the array
{
    for (int i = 0; i < n; ++i)
    {
        cout << QuickSortArray[i] << " ";
        cout << "\n";
    }
    
}