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


## 19. MinHeap :

## 20. MinHeapAdvanced :

## 21. Queue_usingArray :

## 22. Queue_usingStack :

## 23. Recursive_Functions :

## 24. Recursive_PetrolandDistance :

## 25. Stack_usingArray :

## 26. Stack_withIsBalancedString :

## 27. Stack_withReverseFunction :

## 28. StingCompare_Recursive :
