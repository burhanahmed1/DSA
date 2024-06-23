/*
1. Write a c++ recursive function to reverse a number.
void reverse(int n);
2. Write a recursive function that takes an integer as input number and returns the sum of the fibonacci series.
int fib(int a);
3. Write a recursive function to find a number in a sorted integer array, return true if number is present else return false.
bool BinarySearch(int arr[],int num,int first,int last);
4. Write a recursive function to reverse a given array.
int reverseArray(int arr[],int start,int end)
5. Write a recursive function to compare two char arrays.
6. Write a recursive function to compare two strings.
7. A palindrome is a string that reads the same both forward and backward. For example, the string
"madam" is a palindrome. Write a program that uses a recursive function to check whether a string is
a palindrome. Your program must contain a value-returning recursive function that returns true if the
string is a palindrome and false otherwise. Do not use any global variables; use the appropriate
parameters.
*/

#include<iostream>
#include<string>
using namespace std;

//Task 1
void reverse(int n) {
    if (n < 10) {
        cout << n;
        return;
    }
    else {
        cout << n % 10;
        reverse(n / 10);
    }
}

//Task2
int fib(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}
int fibSum(int n) {
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += fib(i);
    }
    return sum;
}

//Task3
bool BinarySearch(int arr[], int num, int first, int last) {
    if (first <= last) {
        int mid = first + (last - first) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == num)
            return true;

        // If the element is present in the left subarray
        if (arr[mid] > num)
            return BinarySearch(arr, num, first, mid - 1);

        // If the element is present in the right subarray
        return BinarySearch(arr, num, mid + 1, last);
    }
    // If element is not present in the array
    return false;
}

//Task4
void reverseArray(int arr[], int start, int end) {
    if (start >= end)
        return;

    // Swap elements at start and end
    int temp = arr[start];
    arr[start] = arr[end];
    arr[end] = temp;

    // Recur for the remaining elements
    reverseArray(arr, start + 1, end - 1);
}

//Task5
bool compareCharArrays(char arr1[], char arr2[], int index) {
    if (arr1[index] == '\0' && arr2[index] == '\0') {
        return true;
    }
    if (arr1[index] != arr2[index]) {
        return false;
    }
    return compareCharArrays(arr1, arr2, index + 1);
}
//Task6
bool compareStrings(string str1, string str2, int index) {
    if (index == str1.length() && index == str2.length()) {
        return true;
    }

    if (str1[index] != str2[index]) {
        return false;
    }

    return compareStrings(str1, str2, index + 1);
}

//Task7
bool isPalindrome(string str, int start, int end) {
    if (start >= end) {
        return true;
    }
    if (str[start] != str[end]) {
        return false;
    }
    return isPalindrome(str, start + 1, end - 1);
}

int main(){
    int choice;
    cout << "Enter number from 1 to 6 to perform specific task : ";
    cin >> choice;
    cout << "\n\n";
    if (choice < 1 || choice>6){
        cout << "Your entered num is out of tasks range.Again enter number from 1 to 6 : ";
        cin >> choice;
        cout << "\n\n";
    }
    if (choice == 1) {
         int num = 14539;
         cout << "The number is: " << num<<"\n";
         cout << "Reversed number: ";
         reverse(num);
    }
    else if (choice == 2) {
        int num = 5; // Calculate the sum of Fibonacci series up to the 5th term
        int result = fibSum(num);
        cout << "Sum of Fibonacci series up to the " << num << "-th term: " << result << endl;
    }
    else if (choice == 3) {
        int arr[] = { 1, 3, 5, 7, 9, 11, 13, 15 };
        int size = sizeof(arr) / sizeof(arr[0]);
        int num = 7;
        bool result = BinarySearch(arr, num, 0, size - 1);
        if (result)
            cout << "The number " << num << " is present in the array." << endl;
        else
            cout << "The number " << num << " is not present in the array." << endl;
    }
    else if (choice == 4) {
        int arr[] = { 1, 2, 3, 4, 5 };
        int size = sizeof(arr) / sizeof(arr[0]);
        cout << "Original Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        reverseArray(arr, 0, size - 1);
        cout << "\nReversed Array: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
    }
    else if (choice == 5) {

        char arr1[] = "Hello";
        char arr2[] = "Hello";
        if (compareCharArrays(arr1, arr2, 0)) {
            cout << "The arrays are equal." << endl;
        }
        else {
            cout << "The arrays are not equal." << endl;
        }

        string str1 = "Hello";
        string str2 = "Hallo";
        if (compareStrings(str1, str2, 0)) {
            cout << "The strings are equal." << endl;
        }
        else {
            cout << "The strings are not equal." << endl;
        }
    }
    else if (choice == 6) {
        string input;
        cout << "Enter a string: ";
        getline(cin, input);
        bool result = isPalindrome(input, 0, input.length() - 1);
        if (result) {
            cout << "The string \"" << input << "\" is a palindrome." << endl;
        }
        else {
            cout << "The string \"" << input << "\" is not a palindrome." << endl;
        }
    }
        system("pause>nul");
        return 0;
    }