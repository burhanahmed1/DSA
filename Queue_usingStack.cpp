/*
You have to implement a template class queue using stack objects. The private members
of the Queue class are just stack objects and you can only use operations of stacks.
Implement the following functions:
1. IsFull:
2. IsEmpty:
3. Enqueue: Add an element in the queue.
4. Dequeue: Removes a front element from the queue.
5. Print: It will print all elements of the queue in FIFO order
NOTE: you are not allowed to use any array or link list in the queue class.
*/

#include<iostream>
#include<stack>
using namespace std;

template<class T>
class Queue {
	stack<T> s1;
	stack<T> s2;
public:
	bool isEmpty() {
		if (s1.empty())
			return true;
		return false;
	}
	bool enQueue(T val) {
		s1.push(val);
		return true;
	}
	bool deQueue(T& val) {
		if (s1.empty())
			return false;
		else {
			while (!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
			val = s2.top();
			s2.pop();
			while (!s2.empty()) {
				s1.push(s2.top());
				s2.pop();
			}
			return true;
		}
	}
	void display() {
		while (!s1.empty()) {
			s2.push(s1.top());
			s1.pop();
		}
		while (!s2.empty()) {
			cout << s2.top() << ",";
			s2.pop();
		}
	}
};

int main() {
	int value;
	Queue<int> Q;
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