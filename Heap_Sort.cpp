//Heap Sort Implimentation 
#include <iostream>
#include "Heap_Sort.h"
using namespace std;


void HSort::heap(int Heap[], int n, int i)
{
    int largest = i; //Tracks Largest INT
    int L = 0; //Tracks LEFT
    int R = 0; //Tracks RIGHT

    // If left child is larger than root
    if (L < n && Heap[L] > Heap[largest])
    {
        largest = 2 * i + 1;
    }
    // If right child is larger than largest so far
    if (R < n && Heap[R] > Heap[largest])
    {
        largest = 2 * i + 2;
    }
    // If largest is not root
    if (largest != i) {
        swap(Heap[i], Heap[largest]);

        // Recursively heapify the affected sub-tree
        heap(Heap, n, largest);
    }
}

// main function to do heap sort
void HSort::Sort(int Heap[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heap(Heap, n, i);
    }

    for (int i = n - 1; i > 0; i--) 
    {
        // Move current root to end
        swap(Heap[0], Heap[i]);

        // call max heapify on the reduced heap
        heap(Heap, i, 0);
    }
}

/* A utility function to print array of size n */
void HSort::printArray(int Heap[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        cout << Heap[i] << " ";
        cout << "\n";
    }
}
// Main Function to test sort algorithm 
int main()
{

    HSort H;
    int Heap[] = { 12, 11, 13, 5, 6, 7 };
    int n = sizeof(Heap) / sizeof(Heap[0]);

    H.Sort(Heap, n);

    cout << "Sorted array is \n";
    H.printArray(Heap, n);

}
