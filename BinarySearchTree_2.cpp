#include<iostream>
using namespace std;
class BST;
class TreeNode {
	int data;
	TreeNode* left, * right;
	friend class BST;
};
class BST {
	TreeNode* root;
	void preOrder(TreeNode* t) {
		if (t != NULL) {
			cout << t->data << " ";
			preOrder(t->left);
			preOrder(t->right);
		}
	}
	void inOrder(TreeNode* t) {
		if (t != NULL) {
			inOrder(t->left);
			cout << t->data << " ";
			inOrder(t->right);
		}
	}
	void postOrder(TreeNode* t) {
		if (t != NULL) {
			postOrder(t->left);
			postOrder(t->right);
			cout << t->data << " ";
		}
	}
	void insert(TreeNode*& t, TreeNode* NewNode) {
		if (t == NULL)
			t = NewNode;
		else if (NewNode->data < t->data)
			insert(t->left, NewNode);
		else
			insert(t->right, NewNode);
	}
	bool search(TreeNode* t, int val) {
		if (t == NULL)
			return false;
		else if (t->data == val)
			return true;
		else if (val < t->data)
			search(t->left, val);
		else if (val > t->data)
			search(t->right, val);
	}
public:
	BST() {
		root = NULL;
	}
	void preOrder() {
		preOrder(root);
	}
	void inOrder() {
		inOrder(root);
	}
	void postOrder() {
		postOrder(root);
	}
	void insert(int val) {
		TreeNode* temp = new TreeNode;
		temp->data = val;
		temp->left = NULL;
		temp->right = NULL;
		insert(root, temp);
	}
	void search(int val) {
		search(root, val);
	}
	bool remove(int val) {
		TreeNode* curr = root, * parent = NULL;
		while (curr != 0 && curr->data != val) {
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == NULL)
			return false;
		else {
			if (curr->left != 0 && curr->right != 0) {
				TreeNode* l = curr->left, * pl = curr;
				while (l->right != 0) {
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
				child = curr->left;
			else
				child = curr->right;
			if (child == root)
				root = child;
			else {
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}
	int minimum() {
		TreeNode* curr = root;
		if (curr == 0)
			return 0;
		else {
			while (curr->left != 0)
				curr = curr->left;
			return curr->data;
		}
	}
	int maximum() {
		TreeNode* curr = root;
		if (curr == 0)
			return 0;
		else {
			while (curr->right != 0)
				curr = curr->right;
			return curr->data;
		}
	}

};

int main() {
	BST b1;
	b1.insert(5);
	b1.insert(7);
	b1.insert(4);
	b1.insert(3);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: ";
	b1.postOrder();
	cout << endl;
	b1.search(2);
	cout << "Minimum value of BST is: " << b1.minimum() << endl;
	cout << "Maximum value of BST is: " << b1.maximum() << endl;
	b1.remove(5);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: ";
	b1.postOrder();

	system("pause>nul");
	return NULL;
}