/////stack
#include<stack>
.empty() – Returns whether the stack is empty
.size() – Returns the size of the stack
.top() – Returns a reference to the top most element of the stack
.push(g) – Adds the element ‘g’ at the top of the stack
.pop() – Deletes the most recent entered element of the stack


/////Queue
#include<queue>
.push(g) – Adds the element ‘g’ at the top of queue
.pop() – Deletes the first entered element of the queue
.front() - to reference the first or the oldest element of the queue
.back() - to reference the last or the newest element of the queue
.empty() – Returns whether  is empty
.size() – Returns the size
q1.swap(q2) - swaps data of q1 and q2


//////List
#include<list>
    // defining list
    list<int> gqlist{ 12,45,8,6 };
    //print element in list
for (auto i : gqlist) {
    cout << i << ' ';
}
.front()       – Returns the value of the first element in the list.
.back()        – Returns the value of the last element in the list.
.push_front()  – Adds a new element ‘g’ at the beginning of the list.
.push_back()   – Adds a new element ‘g’ at the end of the list.
.pop_front()   – Removes the first element of the list, and reduces the size of the list by 1.
.pop_back()    – Removes the last element of the list, and reduces the size of the list by 1.
.insert(position,vlaue)   – Inserts new elements in the list before the element at a specified position.
.size()        – Returns the number of elements in the list.
.begin()       – begin() function returns an iterator pointing to the first element of the list.
.end()         – end() function returns an iterator pointing to the theoretical last element which follows the last element.



