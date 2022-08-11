#ifndef HEAPSORT
#define HEAPSORT

namespace HSort
{
    void heap(vector<int>& Heap, int n, int i)
    {
        int largest = i; //Tracks Largest INT
        int L = 2 * i + 1; //Tracks LEFT
        int R = 2 * i + 2; //Tracks RIGHT

        // If left child is larger than root
        if (L < n && Heap[L] > Heap[largest])
        {
            largest = L;
        }
        // If right child is larger than largest so far
        if (R < n && Heap[R] > Heap[largest])
        {
            largest = R;
        }
        // If largest is not root
        if (largest != i) {
            swap(Heap[i], Heap[largest]);

            // Recursively heapify the affected sub-tree
            heap(Heap, n, largest);
        }
    }

    // main function to do heap sort
    void Sort(vector<int>& Heap, int n)
    {
        // Build heap (rearrange array)
        for (int i = n / 2 - 1; i >= 0; i--)
        {
            heap(Heap, n, i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            // Move current root to end
            swap(Heap[0], Heap[i]);

            // call max heapify on the reduced heap
            heap(Heap, i, 0);
        }
    }

}
#endif