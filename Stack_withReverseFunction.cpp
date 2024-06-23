/*
Implement a function reverse which reverses the given string using your stack data
structure. string reverse(string const);
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
	void reverse(string a)
	{
		for (int i = 0; i < maxsize; i++)
		{
			push(a[i]);
		}
		char b;
		for (int i = 0; i < maxsize; i++)
		{
			getTopValue(b);
			cout << b;
			pop();
		}
	}
};
int main()
{
	string a;
	cout << "Enter string : ";
	cin >> a;
	int size = a.length();
	stack <char>s1(size);
	s1.reverse(a);

	system("pause>nul");
	return 0;
}