/*
MinHeap with special additional functionalities
*/

#include <iostream>
using namespace std;

class minHeap
{
private:
    int* h;
    int maxSize, currHeapSize;

    void bubble_up(int i)
    {
        int parent = (i - 1) / 2;
        while (i > 0 && h[i] < h[parent])
        {
            swap(h[i], h[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void bubble_down(int i)
    {
        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;
        int smallest = i;
        if (left_child < currHeapSize && h[left_child] < h[smallest])
        {
            smallest = left_child;
        }
        if (right_child < currHeapSize && h[right_child] < h[smallest])
        {
            smallest = right_child;
        }

        if (smallest != i)
        {
            swap(h[i], h[smallest]);
            bubble_down(smallest);
        }
    }

public:
    minHeap(int capacity = 10) : h(new int[capacity]), maxSize(capacity), currHeapSize(0) {}

    void buildMinHeap()
    {
        for (int i = currHeapSize / 2 - 1; i >= 0; --i)
        {
            bubble_down(i);
        }
    }

    void insertASingleValueInHeap(const int& x)
    {
        if (currHeapSize == maxSize)
        {
            cout << "Heap is full. Cannot insert more elements." << endl;
            return;
        }

        h[currHeapSize] = x;
        bubble_up(currHeapSize);
        ++currHeapSize;
    }

    bool isEmpty() const
    {
        return currHeapSize == 0;
    }

    const int& getMin() const
    {
        if (isEmpty())
        {
            cout << "Heap is empty. No minimum value to retrieve." << endl;
            return h[0];
        }

        return h[0];
    }

    void heapSort(int arr[], int N)
    {
        minHeap mh(N);

        for (int i = 0; i < N; ++i)
        {
            mh.insertASingleValueInHeap(arr[i]);
        }

        for (int i = 0; i < N; i++)
        {
            arr[i] = mh.getMin();
            mh.h[0] = mh.h[mh.currHeapSize - 1];
            mh.currHeapSize--;
            mh.bubble_down(0);
        }
    }
    void heapSortDescending(int arr[], int n)
    {
        minHeap mh(n);

        for (int i = 0; i < n; ++i)
        {
            mh.insertASingleValueInHeap(arr[i]);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            arr[i] = mh.getMin();
            mh.h[0] = mh.h[mh.currHeapSize - 1];
            --mh.currHeapSize;
            mh.bubble_down(0);
        }
    }
    bool isHeap(int arr[], int i, int n)
    {
        if (i >= n)
        {
            return true;
        }

        int left_child = 2 * i + 1;
        int right_child = 2 * i + 2;

        if (left_child < n && arr[left_child] < arr[i])
        {
            return false;
        }

        if (right_child < n && arr[right_child] < arr[i])
        {
            return false;
        }

        return isHeap(arr, left_child, n) && isHeap(arr, right_child, n);
    }

    void printSmallerThan(int arr[], int n, int x)
    {
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] < x)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }

    void convertBSTtoMinHeap(int arr[], int n)
    {
        heapSort(arr, n);
    }
};
void heapify(int* arr, int size, int i)
{
    int l = 2 * i + 1;
    int r = (2 * i) + 2;
    int smll = i;

    if (arr[l] < arr[smll] && l < size)
    {
        smll = l;
    }

    if (arr[r] < arr[smll] && r < size)
    {
        smll = r;
    }

    swap(arr[smll], arr[i]);

    if (smll != i)
    {
        heapify(arr, size, smll);
    }
}

void bstToMinheap(int* arr, int size)
{
    for (int i = 0; i <= (size / 2) - 1; i++)
    {
        heapify(arr, size, i);
    }

    for (int i = 0; i <= size; i++)
    {
        heapify(arr, size, i);
    }

    for (int i = 0; i <= (size / 2) - 1; i++)
    {
        heapify(arr, size, i);
    }
}
int main()
{
    minHeap myHeap;

    int arr[] = { 5, 3, 8, 2, 1, 7, 6 };
    int n = 7;

    cout << "Original array: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    myHeap.heapSort(arr, n);

    cout << "Sorted array using heapsort: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    bool isHeap = myHeap.isHeap(arr, 0, n);
    cout << "Is the array a binary heap? " << (isHeap ? "Yes" : "No") << endl;

    myHeap.heapSortDescending(arr, n);

    cout << "Sorted array in descending order using heapsort: ";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Values smaller than 6: ";
    myHeap.printSmallerThan(arr, n, 6);

    return 0;
}}