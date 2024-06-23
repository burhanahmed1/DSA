/*
Implement a recursive global function to find the Fibonacci number.
*/

#include <iostream>
using namespace std;
int Fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}
int main()
{
    int n;
    cout << "Enter a non-negative integer: ";
    cin >> n;
    cout << "Fibonacci number at position " << n << " is: " << Fibonacci(n) << endl;
    system("pause>nul");
    return 0;
}