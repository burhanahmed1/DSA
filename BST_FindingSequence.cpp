#include <iostream>
using namespace std;

// Definition of Node structure
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Definition of BST class
class BST {
private:
    Node* root;

    void insertRecursive(Node*& currNode, int value) {
        if (currNode == nullptr) {
            currNode = new Node(value);
        }
        else if (value < currNode->data) {
            insertRecursive(currNode->left, value);
        }
        else {
            insertRecursive(currNode->right, value);
        }
    }

    void seqExistUtil(Node* ptr, int seq[], int& index, int n) {
        if (ptr == nullptr)
            return;
        seqExistUtil(ptr->left, seq, index, n);

        // If current node matches with seq[index] then move forward in sub-sequence
        if (index < n && ptr->data == seq[index])
            index++;

        // We traverse right subtree in the end in Inorder
        seqExistUtil(ptr->right, seq, index, n);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        insertRecursive(root, value);
    }

    bool seqExist(int seq[], int n) {
        int index = 0;
        seqExistUtil(root, seq, index, n);
        return (index == n);
    }
};

int main() {
    BST tree;
    int sortedArray[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(sortedArray) / sizeof(sortedArray[0]);

    // Insert elements into the BST
    for (int i = 0; i < n; ++i) {
        tree.insert(sortedArray[i]);
    }

    // Define a sequence to check
    int sequence[] = { 2, 4, 6 };
    int seqLength = sizeof(sequence) / sizeof(sequence[0]);

    // Check if the sequence exists in the BST
    if (tree.seqExist(sequence, seqLength)) {
        cout << "The sequence exists in the BST." << endl;
    }
    else {
        cout << "The sequence does not exist in the BST." << endl;
    }

    return 0;
}
