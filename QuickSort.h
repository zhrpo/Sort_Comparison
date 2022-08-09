#pragma once
/*-- QuickSort.h ---------------------------------------------------------------
  This header file defines the QuickSort class
-------------------------------------------------------------------------*/

class QuickSort
{
public:
	/*Split to find the PIVOT*/
	int split(int arr[], int first, int end);
	/*Sort the array*/
	void Sort(int arr[], int first, int end);
	/*Display*/
	void display(int arr[], int n);
};