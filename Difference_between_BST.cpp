//-------------///Checking isDifferenceBST if differ. of sum of data of left sub-trees and sum of right sub is equal to that node
//------------------------------------------------------------
#include<iostream>
using namespace std;

class TreeNode {
    int Data;
    TreeNode* Left;
    TreeNode* Right;

    friend class BST;
};

class BST {
private:
    TreeNode* Root;

    void insertRecursive(TreeNode*& currNode, TreeNode* newNode) {
        if (currNode == nullptr)
            currNode = newNode;
        else if (newNode->Data < currNode->Data)
            insertRecursive(currNode->Left, newNode);
        else
            insertRecursive(currNode->Right, newNode);
    }

    int nodesSum(TreeNode* currNode) {
        if (currNode == nullptr)
            return 0;
        else
            return currNode->Data + nodesSum(currNode->Left) + nodesSum(currNode->Right);
    }

    void isDifferenceBinaryTreeRecursive(TreeNode* currNode, bool& Check) {
        if (currNode == nullptr || !Check)
            return;

        int leftsum = nodesSum(currNode->Left);
        int rightsum = nodesSum(currNode->Right);
        int Diff = leftsum - rightsum;

        if (Diff != currNode->Data) {
            Check = false;
            return;
        }

        isDifferenceBinaryTreeRecursive(currNode->Left, Check);
        isDifferenceBinaryTreeRecursive(currNode->Right, Check);
    }

public:
    BST() {
        Root = nullptr;
    }

    void Insert(int Value) {
        TreeNode* newNode = new TreeNode;
        newNode->Data = Value;
        newNode->Left = newNode->Right = nullptr;

        insertRecursive(Root, newNode);
    }

    bool isDifferenceBinaryTree() {
        bool Check = true;
        isDifferenceBinaryTreeRecursive(Root, Check);
        return Check;
    }
};

int main() {
    BST tree;

    // Insert nodes into the BST
    tree.Insert(10);
    tree.Insert(4);
    tree.Insert(6);
    tree.Insert(1);
    tree.Insert(7);
    tree.Insert(3);

    // Check if the tree is a difference binary tree
    if (tree.isDifferenceBinaryTree()) {
        cout << "The tree is a difference binary tree." << endl;
    }
    else {
        cout << "The tree is not a difference binary tree." << endl;
    }

    return 0;
}
};