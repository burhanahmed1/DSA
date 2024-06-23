/*
Task No 1:
Implement a recursive global function stringCompare which compares two character strings
recursively and:
1. returns 0 if the two strings are equal.
2. If the character of the first string at the index, where the first mismatch occurred, is
greater in ASCII value; then it returns 1
3. else it returns -1.
*/

#include <iostream>
using namespace std;
int stringCompare(const char* string1, const char* string2)
{
    if (*string1 == *string2)
        return 0;
    if (*string1 > *string2)
        return 1;
    else
        return -1;
}

int main() {
    const char* str1 = "hello";
    const char* str2 = "world";

    int result = stringCompare(str1, str2);

    if (result == 0)
    {
        cout << "The strings are equal.\n";
    }
    else if (result == 1)
    {
        cout << "String 1 is greater than String 2.\n";
    }
    else if (result == -1)
    {
        cout << "String 1 is smaller than String 2.\n";
    }
    system("pause>nul");
    return 0;
}