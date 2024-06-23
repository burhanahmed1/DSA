/*
Implement a class Queue Using Array as a circular list
Implement the following functions
1. IsFull:
2. IsEmpty:
3. Enqueue: Add an element to the queue.
4. Dequeue: Removes the front element from the queue.
5. Print: It will print all elements of the queue in FIFO order
*/

#include<iostream>
using namespace std;

class Queue {
	int* arrQueue = 0;
	int maxSize, currSize, front, rear;
public:
	Queue(int maxsize = 10) {
		maxSize = maxsize;
		currSize = 0;
		front = -1;
		rear = -1;
		arrQueue = new int[10];
	}
	~Queue() {
		if (arrQueue != 0) {
			delete[]arrQueue;
			arrQueue = 0;
		}
	}
	bool isFull() {
		if (currSize == maxSize)
			return true;
		return false;
	}
	bool isEmpty() {
		if (currSize == 0)
			return true;
		return false;
	}
	bool enQueue(int val) {
		if (isFull())
			return false;
		else {
			rear = (rear + 1) % maxSize;
			arrQueue[rear] = val;
			currSize++;
			return true;
		}
	}
	bool deQueue(int& val) {
		if (isEmpty())
			return false;
		else {
			front = (front + 1) % maxSize;
			val = arrQueue[front];
			currSize--;
			return true;
		}
	}
	void display() {
		int j = front;
		for (int i = 0; i < currSize; i++) {
			j = (j + 1) % maxSize;
			cout << arrQueue[j] << ",";
		}
	}
};

int main() {
	int value;
	Queue Q;
	Q.enQueue(9);
	Q.enQueue(8);
	Q.enQueue(7);
	Q.deQueue(value);
	Q.enQueue(2);
	Q.deQueue(value);
	Q.enQueue(3);
	Q.deQueue(value);
	Q.enQueue(4);
	Q.deQueue(value);
	Q.enQueue(5);
	Q.deQueue(value);
	Q.deQueue(value);
	Q.enQueue(50);
	Q.enQueue(2);
	Q.enQueue(10);
	Q.display();
	system("pause>nul");
	return 0;
}