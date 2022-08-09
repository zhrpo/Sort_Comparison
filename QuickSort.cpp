#include "QuickSort.h"
#include <cstddef>
#include <iostream>

using namespace std;

int QuickSort::split(int arr[], int first, int end) //swaps the data around to find the smallest value
{

    int pivot = arr[first];

    int count = 0;
    for (int i = first + 1; i <= end; i++) 
    {
        if (arr[i] <= pivot)
            count++;
    }


    int pivotValue = first + count;
    swap(arr[pivotValue], arr[first]);


    int left = first;
    int right = end;

    while (left < pivotValue && right > pivotValue)
    {
        if (left < pivotValue && right > pivotValue)
        {
            swap(arr[left++], arr[right--]);
        }
        while (arr[left] <= pivot)
        {
            left = left++;
        }

        while (arr[right] > pivot)
        {
            right = right--;
        }

        
    }

    return pivotValue;
}

void QuickSort::Sort(int arr[], int first, int end) //sorts data from the array
{
    if (first >= end)
    {
        return;
    }

    int p = split(arr, first, end);//puls the first and last to swap out until it in numerical order
    Sort(arr, first, p - 1);
    Sort(arr, p + 1, end);
}

void QuickSort::display(int arr[], int n) //displays the array
{
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
        cout << "\n";
    }
    
}