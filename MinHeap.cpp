/*
Build a min heap class
*/

#include<iostream>
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

};

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


int main() {
	minHeap myHeap(10);
	int a;
	myHeap.insertSingleValueInHeap(4);
	myHeap.insertSingleValueInHeap(10);
	myHeap.insertSingleValueInHeap(3);
	myHeap.insertSingleValueInHeap(5);
	myHeap.insertSingleValueInHeap(1);
	myHeap.getMin(a);
	cout << "Minimum value in the heap: " << a << endl;
	myHeap.getMin(a);

	system("pause");
	return 0;
}