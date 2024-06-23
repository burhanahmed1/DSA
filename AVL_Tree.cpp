/*
AVL Tree
*/

#include<iostream>
using namespace std;

class AVLTreeNode {
	int data;
	AVLTreeNode* left;
	AVLTreeNode* right;
	int height;
	friend class AVLTree;
};

class AVLTree {
private:
	AVLTreeNode* root;

	int height(AVLTreeNode* node) {
		if (node == NULL)
			return -1;
		return node->height;
	}

	int max(int a, int b) {
		if (a > b) {
			return a;
		}
		else {
			return b;
		}
	}


	AVLTreeNode* rightRotate(AVLTreeNode* y) {
		AVLTreeNode* x = y->left;
		AVLTreeNode* T = x->right;

		x->right = y;
		y->left = T;

		y->height = max(height(y->left), height(y->right)) + 1;
		x->height = max(height(x->left), height(x->right)) + 1;

		return x;
	}

	AVLTreeNode* leftRotate(AVLTreeNode* x) {
		AVLTreeNode* y = x->right;
		AVLTreeNode* T = y->left;

		y->left = x;
		x->right = T;

		x->height = max(height(x->left), height(x->right)) + 1;
		y->height = max(height(y->left), height(y->right)) + 1;

		return y;
	}

	int getBalance(AVLTreeNode* node) {
		if (node == NULL)
			return 0;
		return height(node->left) - height(node->right);
	}

	AVLTreeNode* insert(AVLTreeNode* node, int val) {
		if (node == NULL) {
			AVLTreeNode* newNode = new AVLTreeNode;
			newNode->data = val;
			newNode->left = newNode->right = NULL;
			newNode->height = 0;
			return newNode;
		}

		if (val < node->data)
			node->left = insert(node->left, val);
		else if (val > node->data)
			node->right = insert(node->right, val);
		else
			return node; // Duplicate values not allowed

		node->height = 1 + max(height(node->left), height(node->right));

		int balance = getBalance(node);

		// Left Heavy
		if (balance > 1 && val < node->left->data)
			return rightRotate(node);

		// Right Heavy
		if (balance < -1 && val > node->right->data)
			return leftRotate(node);

		// Left Right Heavy
		if (balance > 1 && val > node->left->data) {
			node->left = leftRotate(node->left);
			return rightRotate(node);
		}

		// Right Left Heavy
		if (balance < -1 && val < node->right->data) {
			node->right = rightRotate(node->right);
			return leftRotate(node);
		}

		return node;
	}
	void inOrder(AVLTreeNode* node) {
		if (node != NULL) {
			inOrder(node->left);
			cout << node->data << " ";
			inOrder(node->right);
		}
	}
public:
	AVLTree() {
		root = NULL;
	}

	void insert(int val) {
		root = insert(root, val);
	}

	void inOrder() {
		inOrder(root);
		cout << endl;
	}

};

int main() {
	AVLTree avl;

	avl.insert(5);
	avl.insert(7);
	avl.insert(4);
	avl.insert(3);

	cout << "In-Order Traversal of AVL Tree: ";
	avl.inOrder();

	system("pause>nul");
	return 0;
}
