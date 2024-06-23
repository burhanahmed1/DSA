/*
Given an expression containing opening and closing braces, brackets, and parentheses;
implement a function “isBalanced” to check whether the given expression is a balanced
expression or not, using your stack implementation. For example, {[{}{}]}[()], {{}{}}, and []{}()
are balanced expressions, but {()}[) and {(}) are not balanced. In your main function test your
function using the given examples. bool isBalanced(string exp)
*/

#include<iostream>
using namespace std;
template <typename T>
class stack
{
	T* arr = 0;
	int c_size, maxsize, top;
public:
	stack(int maxsize = 5)
	{
		this->maxsize = maxsize;
		arr = new T[maxsize];
		c_size = 0;
		top = -1;
	}
	~stack()
	{
		if (arr != 0)
		{
			delete[] arr;
			arr = 0;
		}
	}
	bool isEmpty()
	{
		if (c_size == 0)
			return true;
		return false;
	}
	bool isFull()
	{
		if (c_size == maxsize)
			return true;
		return false;
	}
	bool push(T value)
	{
		if (isFull())
			return false;
		else
		{
			top++;
			arr[top] = value;
			c_size++;
			return true;
		}
	}
	bool pop()
	{
		if (isEmpty())
			return false;
		else
		{
			c_size--;
			top--;
			return true;
		}
	}
	bool getTopValue(T& value)
	{
		if (isEmpty())
			return false;
		else
		{
			value = arr[top];
			return true;
		}
	}
	bool isBalanced(string exp)
	{
		if (isEmpty() && exp[0] == ')' || exp[0] == '}' || exp[0] == ']' || maxsize % 2 != 0)
			return false;
		for (int i = 0; i < maxsize; i++)
		{
			if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			{
				push(exp[i]);
			}
			else if (arr[top] == '(' && exp[i] == ')' || arr[top] == '{' && exp[i] == '}' || arr[top] == '[' && exp[i] == ']')
			{
				pop();
			}
		}
		if (isEmpty())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main()
{
	string a;
	cout << "enter string : "; cin >> a;
	int size = a.length();
	stack <char>s1(size);
	if (s1.isBalanced(a))
	{
		cout << "Balanced";
	}
	else
	{
		cout << "not Balanced";
	}

	system("pause>nul");
	return 0;
}