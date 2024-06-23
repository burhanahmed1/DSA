
//-----A BST with two values like order pair (x,y) and the name of shape placed at that location its node class will be

#include <iostream>
#include <string>
using namespace std;

class Node2dBST {
public:
    int x, y;
    string shapeName;
    Node2dBST* lChild;
    Node2dBST* rChild;

    Node2dBST(int x, int y, string shapeName) {
        this->x = x;
        this->y = y;
        this->shapeName = shapeName;
        this->lChild = nullptr;
        this->rChild = nullptr;
    }
};

class BST {
public:
    Node2dBST* root;

    BST() {
        root = nullptr;
    }

    bool Insert(int x, int y, string shapeName) {
        if (root == nullptr) { // Tree is empty
            Node2dBST* n = new Node2dBST(x, y, shapeName);
            root = n;
            return true;
        }
        else {
            Node2dBST* curr = root;
            Node2dBST* prev = nullptr;
            int level = 0;
            bool found = false;
            while (curr != nullptr && !found) { // Iterative traversal for finding correct insertion point
                if (curr->x == x && curr->y == y)
                    found = true;
                else {
                    prev = curr;
                    if (level % 2 == 0) {
                        if (curr->x > x)
                            curr = curr->lChild;
                        else
                            curr = curr->rChild;
                    }
                    else {
                        if (curr->y > y)
                            curr = curr->lChild;
                        else
                            curr = curr->rChild;
                    }
                }
                level++;
            }
            if (!found) { // Node coordinates not in the tree, insert new node
                Node2dBST* n = new Node2dBST(x, y, shapeName);
                if ((level - 1) % 2 == 0) {
                    if (prev->x > x)
                        prev->lChild = n;
                    else
                        prev->rChild = n;
                }
                else {
                    if (prev->y > y)
                        prev->lChild = n;
                    else
                        prev->rChild = n;
                }
                return true;
            }
        }
        return false;
    }
};

int main() {
    BST tree;

    tree.Insert(5, 10, "Circle");
    tree.Insert(15, 5, "Square");
    tree.Insert(5, 15, "Triangle");
    tree.Insert(10, 20, "Rectangle");
    tree.Insert(20, 25, "Polygon");

    // Additional testing and validation can be done here

    return 0;
}
