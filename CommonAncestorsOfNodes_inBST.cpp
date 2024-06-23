////----------------------Checking the common ancestors of two nodes
////------------------------------------
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class TreeNode
{
	int Data;
	TreeNode* Left;
	TreeNode* Right;

	friend class BST;
};

class BST
{
private:
	TreeNode* Root;

	void insertRecursive(TreeNode*& currNode, TreeNode* newNode)
	{
		if (currNode == nullptr)
			currNode = newNode;
		else if (newNode->Data < currNode->Data)
			insertRecursive(currNode->Left, newNode);
		else
			insertRecursive(currNode->Right, newNode);
	}

	void Ancestor(int Value, vector<TreeNode*>& Ancestors, TreeNode* CurrNode)
	{
		if (Value == CurrNode->Data)
			return;
		else if (Value < CurrNode->Data)
		{
			Ancestors.push_back(CurrNode);
			Ancestor(Value, Ancestors, CurrNode->Left);
		}
		else if (Value > CurrNode->Data)
		{
			Ancestors.push_back(CurrNode);
			Ancestor(Value, Ancestors, CurrNode->Right);
		}
	}

public:
	BST()
	{
		Root = nullptr;
	}

	void Insert(int Value)
	{
		TreeNode* newNode = new TreeNode;
		newNode->Data = Value;
		newNode->Left = newNode->Right = nullptr;

		insertRecursive(Root, newNode);
	}

	void commonAncestor(int X, int Y)
	{
		vector<TreeNode*> X_Ancestors;
		vector<TreeNode*> Y_Ancestors;

		Ancestor(X, X_Ancestors, Root);
		Ancestor(Y, Y_Ancestors, Root);

		int size = min(X_Ancestors.size(), Y_Ancestors.size());
		stack<TreeNode*> S;

		for (int i = 0; i < size; i++)
		{
			if (X_Ancestors[i]->Data == Y_Ancestors[i]->Data)
				S.push(X_Ancestors[i]);
		}

		size = S.size();

		for (int i = 1; i <= size; i++)
		{
			TreeNode* Value = S.top();
			cout << Value->Data << " ";
			S.pop();
		}
	}
};

int main()
{
	BST b1;

	b1.Insert(49);
	b1.Insert(39);
	b1.Insert(67);
	b1.Insert(29);
	b1.Insert(42);
	b1.Insert(59);
	b1.Insert(95);
	b1.Insert(40);
	b1.Insert(62);

	b1.commonAncestor(29, 40);

	return 0;
}