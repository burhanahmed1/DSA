/*
Implement a template Stack Using an Array
1. bool Push (T Val) // Add an element in Stack. Returns False if push operation is
unsuccessful otherwise True.
2. bool Pop () // Remove top element from Stack. Returns true if the operation is
successful otherwise false if the stack is empty with some error message.
3. bool Top(T&amp;) //returns the top element but does not remove it from the stack, the
topmost element from the stack via the parameter passed by reference. It returns false
via a return statement if there is no element in the stack, else it returns true and
assigns the topmost element to the parameter passed by reference.
4. bool IsEmpty()
5. bool IsFull()
6. Stack()  //default constructor. Creates a stack of default size 10
7. Stack(int size) // Parameterized Constructor. Creates a stack of size = size
8. ~Stack() // Destructor
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
};
int main()
{
	stack <string>s1(50);
	s1.push("Burhan");
	s1.push("Ahmed");
	s1.pop();
	string a;
	s1.getTopValue(a);
	cout << a;

	system("pause>nul");
	return 0;
}