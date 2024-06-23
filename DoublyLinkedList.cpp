#include<iostream>
using namespace std;

class DoublyLinkedList;
class DNode {
	int data;
	DNode* next, * prev;
	friend class DoublyLinkedList;
};
class DoublyLinkedList {
	DNode* head;
public:
	DoublyLinkedList() {
		head = 0;
	}
	~DoublyLinkedList() {
		while (head != 0)
		{
			DNode* curr = head;
			head = head->next;
			delete curr;
		}
	}
	void display() {
		if (head == 0)
			cout << "The List is empty : \n";
		else {
			DNode* curr = head;
			while (curr != 0) {
				cout << curr->data << " ";
				curr = curr->next;
			}
			cout << "\n";
		}
	}
	bool insertAtStart(int val) {
		DNode* temp = new DNode;
		temp->data = val;
		temp->prev = 0;
		temp->next = head;
		if (head != 0) {
			head->prev = temp;
		}
		head = temp;
		return true;
	}
	bool deleteFromStart() {
		if (head == 0)
			return 0;
		else {
			DNode* curr = head;
			curr = curr->next;
			curr->prev = 0;
			delete head;
			head = curr;
			return true;
		}
	}
	bool insertAtEnd(int val) {
		DNode* temp = new DNode;
		temp->data = val;
		temp->next = 0;
		if (head == 0)
		{
			temp->prev = 0;
			head = temp;
		}
		else {
			DNode* curr = head;
			DNode* last = 0;
			while (curr != 0) {
				last = curr;
				curr = curr->next;
			}
			temp->prev = last;
			last->next = temp;
			return true;
		}
	}
	bool deleteFromEnd() {
		if (head == 0)
			return 0;
		else {
			DNode* curr = head;
			DNode* last = 0;
			while (curr != 0) {
				last = curr;
				curr = curr->next;
			}
			if (last->prev == 0) {
				delete last;
				last = 0;
				head = 0;
			}
			else {
				last = last->prev;
				DNode* del = last->next;
				delete del;
				last->next = 0;
				del = 0;
				return 1;
			}
		}
	}
	bool sortedinsert(int val) {
		DNode* temp = new DNode;
		temp->data = val;
		temp->prev = 0;
		temp->next = head;
		int swapped;
		if (head != 0) {
			head->prev = temp;
		}
		head = temp;
		if (head->next == 0)
		{
			return true;
		}
		else {
			do {
				swapped = 0;
				DNode* curr = head->next;
				DNode* last = head;
				while (curr != 0) {
					if ((last->data) > (curr->data)) {
						swap(last->data, curr->data);
						swapped = 1;
					}
					last = curr;
					curr = curr->next;
				}
			} while (swapped);

			return true;
		}
	}
	DNode* Search(int val) {
		if (head == 0)
			return 0;
		else {
			DNode* curr = head;
			while (curr != 0 && curr->data != val) {
				curr = curr->next;
			}
			if (curr == 0)
				return 0;
			else if (curr->data == val) {
				return curr;
			}
		}
	}
	bool deleteSpecificValue(int val) {
		DNode* del = Search(val);
		if (del == 0) {
			cout << "The list is empty or the value not found.";
			return false;
		}
		else {
			del->next->prev = del->prev;
			del->prev->next = del->next;
			delete del;
			return true;
		}
	}
	bool mergeLists(DoublyLinkedList* Obj2) {
		DNode* curr = head;
		if (Obj2 == 0)
			return false;
		else
		{
			if (head == 0) {
				head = Obj2->head;
				return true;
			}
			else
			{
				while (curr->next != 0) {
					curr = curr->next;
				}
				curr->next = Obj2->head;
				Obj2->head->prev = curr;
				return true;
			}
		}
	}
};


int main() {
	DoublyLinkedList l1, l2;
	l1.insertAtStart(3);
	l1.insertAtStart(5);
	l1.insertAtStart(4);
	l2.insertAtStart(12);
	l2.insertAtStart(13);
	l2.insertAtStart(14);
	cout << "THe list after insertion from start : ";
	l1.display();
	l1.insertAtEnd(10);
	l1.insertAtEnd(8);
	l1.insertAtEnd(7);
	cout << "The list after insertion from end : ";
	l1.display();
	l1.deleteFromStart();
	l1.deleteFromEnd();
	cout << "THe list after deletion from start and end : ";
	l1.display();
	l1.sortedinsert(6);
	cout << "The list after sorted insertion : ";
	l1.display();
	cout << "The address of value present in list : " << l1.Search(5) << "\n";
	cout << "The address of value which is not present in list : " << l1.Search(9) << "\n";
	l1.deleteSpecificValue(5);
	cout << "The list after deleting a specific value : ";
	l1.display();
	cout << "By deleting a value which is not present in list it shows : ";
	l1.deleteSpecificValue(9);
	l1.mergeLists(&l2);
	l1.display();
	system("pause>nul");
	return 0;
}

