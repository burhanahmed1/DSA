/*
Given a single link list of size n which is initialized by numbers from 1 to n in random order. User
deletes four elements at random from list. Write a function that finds which elements are
missing from the list.
*/

#include<iostream>
#include<cstdlib>
using namespace std;
class LinkedList;
class Node {
	int data;
	Node* next;
	friend class LinkedList;
};

class LinkedList {
	Node* head;
public:
	LinkedList() {
		head = 0;
	}
	void display() {
		if (head == 0)
			cout << "The list is empty.\n";
		else {
			Node* curr = head;
			while (curr != 0) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}
	}
	bool insertAtStart(int val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = head;
		head = temp;
		return 1;
	}
	bool deleteFromStart(int& val) {
		if (head == 0)
			return 0;
		else {
			Node* curr = head;
			head = head->next;
			val = curr->data;
			delete curr;
			curr = 0;
			return 1;
		}
	}
	bool insertAtEnd(int val) {
		Node* temp = new Node;
		temp->data = val;
		temp->next = 0;
		if (head == 0) {
			head = temp;
			return 1;
		}
		else {
			Node* curr = head, * prev = 0;
			while (curr != 0) {
				prev = curr;
				curr = curr->next;
			}
			prev->next = temp;
			return 1;
		}
	}
	bool deleteFormEnd(int& val) {
		if (head == 0)
			return 0;
		else {
			Node* curr = head, * last = 0, * seclast = 0;
			while (curr != 0) {
				seclast = last;
				last = curr;
				curr = curr->next;
			}
			if (seclast == 0) {
				head = 0;
			}
			else {
				seclast->next = 0;
			}
			val = last->data;
			delete last;
			last = 0;
			return 1;
		}
	}
	bool insertAfterSpecificValue(int sp_val, int val) {
		Node* temp = new Node;
		temp->data = val;
		Node* curr = head;
		bool check = false;
		while (check == false && curr != 0) {
			if (curr->data == sp_val) {
				temp->next = curr->next;
				curr->next = temp;
				check = true;
				return true;
			}
			else {
				curr = curr->next;
			}
		}
		return false;
	}
	~LinkedList() {
		while (head != 0) {
			Node* curr = head;
			head = head->next;
			delete curr;
		}
	}
};

int main() {
	LinkedList l1;
	LinkedList l2;
	int num;
	int misval;
	for (int i = 0; i < 10; i++)
	{
		num = rand() % 10;
		l1.insertAtEnd(num);
	}
	cout << "The list is : ";
	l1.display();
	l1.deleteFromStart(misval);
	l2.insertAtEnd(misval);
	l1.deleteFormEnd(misval);
	l2.insertAtEnd(misval);
	l1.deleteFromStart(misval);
	l2.insertAtEnd(misval);
	l1.deleteFormEnd(misval);
	l2.insertAtEnd(misval);
	cout << "After removing four elements : ";
	l1.display();
	cout << "Missing values : ";
	l2.display();
	system("pause>nul");
	return 0;
}