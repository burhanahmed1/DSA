/*
Implement a Circular Doubly Linked list class having one private data member Node pointer
‘head’.
1. Implement a nested Node class in the linked list class, having three attributes data, next,
previous.
2. Now implement the following operations for the circular doubly linked list class:
2. Insert void insertAtHead(int value);
3. Print Forward void print() const;
4. Search a value bool Search(T value) const;
5. Erase a value void erase(T value);
6. Print backward void printback() const;
7. Destructor
8. Insert void insertafter(int key,int value);
9. Design a manu driven main function which will ask the user to perform any of the
above function. Ask for -1 to exit program.
*/

#include<iostream>
using namespace std;
class CircularDLL;
class Node
{
	int data;
	Node* next, * prev;
	friend class CircularDLL;
};
class CircularDLL
{
	Node* head;
public:
	CircularDLL()
	{
		head = nullptr;
		head = 0;
	}

	void print()
	{
		if (head == nullptr)
		{
			cout << "list is empty";
		}
		else

		{
			Node* curr = head;
			while (curr != 0)
			{
				cout << curr->data << "  ";
				curr = curr->next;

			}
		}
	}
	void insertAtHead(int value)
	{
		Node* temp = new Node;
		temp->next = head;
		temp->data = value;
		if (head != 0)
		{
			temp->prev = head->prev;
			head->prev = temp;
		}
		else
		{
			temp->next = head;
			temp->prev = head;

		}
		head = temp;
	}
	void printback()
	{
		if (head == nullptr)
		{
			cout << "\nlist is empty";
		}
		else

		{
			Node* curr = head;
			curr = curr->next;
			curr = curr->next;
			while (curr != 0)
			{
				cout << curr->data << "  ";
				curr = curr->prev;

			}
		}
	}
	Node* Search(int value)
	{
		if (head == nullptr)
		{
			cout << "\nlist is empty";
			return 0;
		}
		else
		{
			Node* curr = head;
			while (curr != nullptr)
			{
				if (curr->data == value)
				{
					cout << "\nfound";
					return curr;
				}
				else
				{
					cout << "\nnot found";
					return 0;
				}

				curr = curr->next;
			}
			return 0;
		}
	}
	bool deleteSpecificValue(int valToDelete)
	{
		if (head == 0)
		{
			cout << "\nthe list is empty";
			return 0;
		}
		else
		{
			Node* curr = head;
			Node* pre = nullptr;
			if (curr->data == valToDelete)
			{
				head = curr->next;
				if (head != nullptr)
				{
					head->prev = nullptr;
				}
				delete curr;
				return true;
			}
			while (curr != nullptr)
			{
				if (curr->data == valToDelete)
				{
					pre->next = curr->next;
					if (curr->next != nullptr)
					{
						curr->next->prev = pre;
					}
					delete curr;
					return true;
				}
				pre = curr;
				curr = curr->next;
			}
			return false;
		}
	}

	~CircularDLL()
	{
		Node* curr = head;
		while (curr != nullptr)
		{
			Node* nex = curr->next;
			delete curr;
			curr = nex;
		}
		cout << "\ndestructor called";
	}

};
void main()
{
	CircularDLL d;
	d.insertAtHead(2);
	d.insertAtHead(3);
	d.insertAtHead(4);
	d.print();
	cout << "\nBack print: ";
	d.printback();
	Node* a = d.Search(5);
	d.deleteSpecificValue(2);
	cout << "\nAfter deleting : ";
	d.print();
	system("pause>nul");
}