#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = prev = nullptr;
    }
};

// Definition of Doubly Linked List class
class DoublyLinkedList {
private:
    Node* head;

public:
    DoublyLinkedList() {
        head = nullptr;
    }

    void append(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    bool moveHead(int position) {
        if (position < 0)
            return false;
        if (position == 0)
            return true;

        Node* curr = head;
        int i = 0;
        while (curr != nullptr && i < position) {
            i++;
            curr = curr->next;
        }
        if (curr == nullptr)
            return false;

        // Detach curr from its previous position
        if (curr->prev != nullptr) {
            curr->prev->next = curr->next;
        }
        if (curr->next != nullptr) {
            curr->next->prev = curr->prev;
        }

        // Move curr to head
        if (head != nullptr) {
            Node* tail = head;
            while (tail->next != nullptr) {
                tail = tail->next;
            }
            tail->next = head;
            head->prev = tail;
        }
        head = curr;
        head->prev = nullptr;

        return true;
    }

    void printList() {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;

    // Append some elements to the doubly linked list
    dll.append(1);
    dll.append(2);
    dll.append(3);
    dll.append(4);
    dll.append(5);

    cout << "Original list: ";
    dll.printList();

    int position = 2;
    if (dll.moveHead(position)) {
        cout << "After moving head to position " << position << ": ";
        dll.printList();
    }
    else {
        cout << "Failed to move head to position " << position << endl;
    }

    return 0;
}
