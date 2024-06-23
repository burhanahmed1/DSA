# **C++ Data Structures and Algorithms**

# Files Description

## 1. AVL_NodeCount : 
Counting nodes while inserting in an AVL tree.

## 2. AVL_Tree : 
Implementation of AVL Tree.

## 3. BST_FindingSequence:
Finding a given sequence in a BST.

## 4. BinarySearchTree_1 : 
Binary Search Tree Class (BST) with Iterative insert and search functionalities.

## 5. BinarySearchTree_2 :
Implementation of Binary Search Tree.

## 6. BinarySearchTree_2D_Node :
A BST with two values like order pair (x,y) and the name of shape placed at that location/node as data.

## 7. CircularDoublyLinkedList :
Implement a Circular Doubly Linked list class having one private data member Node pointer ‘head’.
1. Implement a nested Node class in the linked list class, having three attributes data, next, previous.
2. Now implement the following operations for the circular doubly linked list class:
2. Insert void insertAtHead(int value);
3. Print Forward void print() const;
4. Search a value bool Search(T value) const;
5. Erase a value void erase(T value);
6. Print backward void printback() const;
7. Destructor
8. Insert void insertafter(int key,int value);
9. Design a manu driven main function which will ask the user to perform any of the above function. Ask for -1 to exit program.

## 8. CommonAcestorsOfNodes_inBST:
Checking the common ancestors of any two Nodes in a BST.

## 9. DSA_BuiltInFunctions_C++ :
C++ BuiltIn Functions for Stack, Queue, and LinkedLists.

## 10. Difference_between_BST :
Checking isDifferenceBST if differ. of sum of data of left sub-trees and sum of right sub is equal to that node.

## 11. DisjointSets_Recursive :
Checking if two sets are Disjoint using Recursion

## 12. DoublyLinkedList :
Implementation of Doubly Linked List.

## 13. DoublyLinkedList_MovingHeadPosition :
Implementation of Doubly Linked List in such a way that we can change the position of head.

## 14. Fibonacci_Recursive :
Implementation of a recursive global function to find the Fibonacci number.

## 15. Hashing :
### Question1:
Implement the two constructors (default and overloaded), and destructor of the class HashTable. 
1. HashTable(): constructor assigns a capacity of 10 to hashArray.
2. HashTable(int const capacity): an overloaded constructor that assigns the capacity of given capacity to hashArray. If capacity is less than 1 return error message
3. ~HashTable(): destructor

### Question2 :
Now, implement these functions which are given below, and are required for helping in handling collision, and also in insert and delete methods. ```int getNextCandidateIndex(int key, int i)```: a private method that uses linear probing to return the next candidate index for storing the item containing key k. Linear probing means that it will simply add i to the hash value of key. This method does not check whether the candidate index has collision or not.
```void doubleCapacity()``` A private method which doubles the capacity of hash array and rehashes the existing items (Remember we have a dynamic hash array). Use getNextCandidateIndex method to resolve collision.

### Question3 :
Implement the public insert function ```void insert(int const key, v const value)```
1. The insert method inserts the value at its appropriate location. Find the first candidate index of the key using: index= key mod capacity
2. To resolve hash collision, it will use the function getNextCandidateIndex(key, i) to get the next candidate index. If the candidate index also has collision, then getNextCandidateIndex will be called again with an increment in i. getNextCandidateIndex will be continued to call until we find a valid index. Initially i will be 1.
3. If the loadFactor becomes 0.75, then it will call the doubleCapacity method to double the capacity of array and rehash the existing items into the new array.
Hint: To check load factor, the overall formula used will be currentElements >= 0.75 * capacity

### Question4 :
Implement the following functions for deletion of a given value from the hash table and searching the value in hash table:
```bool deleteKey(int const key) const;```
This method deletes the given key. It returns true if the key was found. If the key was not found it returns false. When the key is found, simply set the status of the hashItem containing the key to deleted (value of 1). It also uses status variable to search for the key intelligently ```string get(int const key) const```
This method returns the value of the key. If the key is not found, it returns a message saying “not found”. It also uses status variable to search for the key intelligently.

### BONUS Question :
Rewrite the class in such a way that it performs Quadratic Probing, i.e., add the square of i to the hash value of key.
**Hint :** You have to change ```getNextCandidateIndex(int key, int i)``` method

## 16. Hashing_FamilyWizard :
Hashing practical example : FamilyManagementSystem for upto 20 families each of upto 5 members.

## 17. LinkedList :
Given a single link list of size n which is initialized by numbers from 1 to n in random order. User deletes four elements at random from list. Write a function that finds which elements are missing from the list.

## 18. LinkedList_Advanced :
Implementation of Singly Linked List with some additional functionalities.

## 19. MinHeap :
Implementation of MinHeap with functionalities like ```HeapSort()``` , ```BubbleUp()```, ```BubbleDown``` and etc.

## 20. MinHeapAdvanced :
MinHeap with special additional functionalities like ```heapify()```, converting ```BSTtoMinHeap``` and etc.

## 21. Queue_usingArray :
Implementation of a class Queue Using Array as a circular list. 
Implement the following functions
1. IsFull:
2. IsEmpty:
3. Enqueue: Add an element to the queue.
4. Dequeue: Removes the front element from the queue.
5. Print: It will print all elements of the queue in FIFO order

## 22. Queue_usingStack :
You have to implement a template class queue using stack objects. The private members
of the Queue class are just stack objects and you can only use operations of stacks.
Implement the following functions:
1. IsFull:
2. IsEmpty:
3. Enqueue: Add an element in the queue.
4. Dequeue: Removes a front element from the queue.
5. Print: It will print all elements of the queue in **FIFO** order
**NOTE:** you are not allowed to use any array or link list in the queue class.

## 23. Recursive_Functions :
1. Write a c++ recursive function to reverse a number.
``` cpp
void reverse(int n);
```
3. Write a recursive function that takes an integer as input number and returns the sum of the fibonacci series.
``` cpp
int fib(int a);
```
4. Write a recursive function to find a number in a sorted integer array, return true if number is present else return false.
``` cpp
bool BinarySearch(int arr[],int num,int first,int last);
```
7. Write a recursive function to reverse a given array.
 ``` cpp
int reverseArray(int arr[],int start,int end)
```
7. Write a recursive function to compare two char arrays.
8. Write a recursive function to compare two strings.
9. A palindrome is a string that reads the same both forward and backward. For example, the string
"madam" is a palindrome. Write a program that uses a recursive function to check whether a string is
a palindrome. Your program must contain a value-returning recursive function that returns true if the
string is a palindrome and false otherwise. Do not use any global variables; use the appropriate
parameters.

## 24. Recursive_PetrolandDistance :
Recursion practical example of finding the the nearest route to the destination in specific amount of petrol

## 25. Stack_usingArray :
Implement a template Stack Using an Array
1. ```bool Push (T Val)```// Add an element in Stack. Returns False if push operation is unsuccessful otherwise True.
2. ```bool Pop ()``` // Remove top element from Stack. Returns true if the operation is successful otherwise false if the stack is empty with some error message.
3. ```bool Top(T&amp;)``` //returns the top element but does not remove it from the stack, the topmost element from the stack via the parameter passed by reference. It returns false via a return statement if there is no element in the stack, else it returns true and assigns the topmost element to the parameter passed by reference.
4. ```bool IsEmpty()```
5. ```bool IsFull()```
6. ```Stack()```  //default constructor. Creates a stack of default size 10
7. ```Stack(int size)``` // Parameterized Constructor. Creates a stack of size = size
8. ```~Stack()``` // Destructor
   
   
## 26. Stack_withIsBalancedString :
Given an expression containing opening and closing braces, brackets, and parentheses;
implement a function “isBalanced” to check whether the given expression is a balanced
expression or not, using your stack implementation. For example, {[{}{}]}[()], {{}{}}, and []{}()
are balanced expressions, but {()}[) and {(}) are not balanced. In your main function test your
function using the given examples. bool isBalanced(string exp)

## 27. Stack_withReverseFunction :

## 28. StingCompare_Recursive :
