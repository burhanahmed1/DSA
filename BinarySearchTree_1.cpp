/*
Binary Search Tree Class (BST) with Iterative insert and search functionalities
*/

#include<iostream>
using namespace std;
class BST;
class TreeNode {
	int data;
	TreeNode* left;
	TreeNode* right;
	friend class BST;
};
class BST {
	TreeNode* root;
	bool insertRec(TreeNode*& t, TreeNode* NewNode) {
		if (t == 0)
			t = NewNode;
		else if (NewNode->data == t->data)
			return false;
		else if (NewNode->data < t->data)
			insertRec(t->left, NewNode);
		else
			insertRec(t->right, NewNode);
		return true;
	}
	bool searchRec(TreeNode* t, int val) {
		if (t == NULL)
			return false;
		else if (t->data == val)
			return true;
		else if (val < t->data)
			searchRec(t->left, val);
		else if (val > t->data)
			searchRec(t->right, val);
	}
	void inOrder(TreeNode* t) {
		if (t != 0) {
			inOrder(t->left);
			cout << t->data << " ";
			inOrder(t->right);
		}
	}
	void preOrder(TreeNode* t) {
		if (t != 0) {
			cout << t->data << " ";
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void postOrder(TreeNode* t) {
		if (t != 0) {
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << " ";
		}
	}
public:
	BST() {
		root = NULL;
	}
	void insertRec(int val) {
		TreeNode* temp = new TreeNode;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		insertRec(root, temp);
	}
	void insertItr(int val) {
		TreeNode* temp = new TreeNode;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		if (root == 0) {
			root = temp;
		}
		else {
			TreeNode* curr = root;
			TreeNode* curr1 = 0;
			while (curr != 0) {
				if (val < curr->data) {
					curr1 = curr;
					curr = curr->left;
				}
				else if (val >= curr->data) {
					curr1 = curr;
					curr = curr->right;
				}
			}
			if (val < curr1->data) {
				curr1->left = temp;
			}
			else if (val >= curr1->data) {
				curr1->right = temp;
			}
		}

	}

	void inOrderPrint() {
		inOrder(root);
	}
	void inOrder() {
		inOrder(root);
	}
	void preOrder() {
		preOrder(root);
	}
	void postOrder() {
		postOrder(root);
	}
	void searchRec(int val) {
		searchRec(root, val);
	}
	bool searchItr(int val) {
		TreeNode* curr = root;
		while (curr != 0 && curr->data != val) {
			if (val < curr->data) {
				curr = curr->left;
			}
			else if (val > curr->data) {
				curr = curr->right;
			}
		}
		if (curr != 0)
			return true;
		else
			return false;
	}

};


int main() {
	BST T;
	T.insertRec(4);
	T.insertRec(7);
	T.insertRec(2);
	T.insertRec(12);
	T.insertRec(5);
	T.insertRec(15);
	cout << "InOrder Print : ";
	T.inOrder();
	cout << "\npreOrder Print : ";
	T.preOrder();
	cout << "\npostOrder Print : ";
	T.postOrder();

	BST T1;
	T1.insertRec(4);
	T1.insertItr(7);
	T1.insertItr(2);
	T1.insertItr(12);
	T1.insertItr(5);
	T1.insertItr(15);
	cout << "\nInOrder Print : ";
	T1.inOrder();
	cout << "\npreOrder Print : ";
	T1.preOrder();
	cout << "\npostOrder Print : ";
	T1.postOrder();

	system("pause");
	return 0;
}