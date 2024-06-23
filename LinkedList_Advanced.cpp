#include <iostream>
using namespace std;

// Definition of Node structure
template <typename T>
struct SNode {
    T element;
    SNode* next;

    SNode(T val) {
        element = val;
        next = nullptr;
    }
};

// Definition of singly linked list class
template <typename T>
class list {
private:
    SNode<T>* head;

public:
    list() {
        head = nullptr;
    }

    // Function to append elements to the list
    void append(T value) {
        SNode<T>* newNode = new SNode<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            SNode<T>* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to delete the last occurrence of a value
    bool deleteLastOccurrence(T value) {
        bool found = false;
        if (head == nullptr) // Empty List 
            return found;
        else {
            SNode<T>* current = head; // For complete list traversal
            SNode<T>* pcurrent = nullptr;
            SNode<T>* toremove = nullptr; // For tracking of element
            SNode<T>* ptoremove = nullptr;
            while (current != nullptr) { // Loop to search for the last occurrence of value
                if (current->element == value) {
                    found = true;
                    toremove = current;
                    ptoremove = pcurrent;
                }
                pcurrent = current;
                current = current->next;
            }
            if (found) {
                if (toremove == head) { // Boundary check of head node
                    head = head->next;
                    delete toremove;
                }
                else {
                    ptoremove->next = toremove->next;
                    delete toremove;
                }
            }
        }
        return found;
    }

    // Function to print the list
    void printList() {
        SNode<T>* current = head;
        while (current != nullptr) {
            cout << current->element << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    list<int> myList;

    // Append elements to the list
    myList.append(1);
    myList.append(2);
    myList.append(3);
    myList.append(2);
    myList.append(4);
    myList.append(2);

    cout << "Original list: ";
    myList.printList();

    // Delete the last occurrence of 2
    int valueToDelete = 2;
    if (myList.deleteLastOccurrence(valueToDelete)) {
        cout << "After deleting last occurrence of " << valueToDelete << ": ";
        myList.printList();
    }
    else {
        cout << "Value " << valueToDelete << " not found in the list." << endl;
    }

    return 0;
}
