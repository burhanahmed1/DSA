/*
Question1:
Implement the two constructors (default and overloaded), and destructor of the class HashTable. 
1. HashTable(): constructor assigns a capacity of 10 to hashArray.
2. HashTable(int const capacity): an overloaded constructor that assigns the capacity of given
capacity to hashArray. If capacity is less than 1 return error message
3. ~HashTable(): destructor
Question2:
Now, implement these functions which are given below, and are required for helping in handling
collision, and also in insert and delete methods.
int getNextCandidateIndex(int key, int i): a private method that uses linear probing to return
the next candidate index for storing the item containing key k. Linear probing means that it will
simply add i to the hash value of key. This method does not check whether the candidate index
has collision or not.
void doubleCapacity(): A private method which doubles the capacity of hash array and rehashes
the existing items (Remember we have a dynamic hash array). Use getNextCandidateIndex
method to resolve collision.
Question3:
Implement the public insert function
void insert(int const key, v const value):
1. The insert method inserts the value at its appropriate location. Find the first candidate
index of the key using:
index= key mod capacity
2. To resolve hash collision, it will use the function getNextCandidateIndex(key, i) to get the
next candidate index. If the candidate index also has collision, then
getNextCandidateIndex will be called again with an increment in i.
getNextCandidateIndex will be continued to call until we find a valid index. Initially i will
be 1.
3. If the loadFactor becomes 0.75, then it will call the doubleCapacity method to double the
capacity of array and rehash the existing items into the new array.
Hint: To check load factor, the overall formula used will be currentElements >= 0.75 * capacity
Question4:
Implement the following functions for deletion of a given value from the hash table and
searching the value in hash table:
bool deleteKey(int const key) const;
This method deletes the given key. It returns true if the key was found. If the key was not found
it returns false. When the key is found, simply set the status of the hashItem containing the key
to deleted (value of 1). It also uses status variable to search for the key intelligently 
string get(int const key) const
This method returns the value of the key. If the key is not found, it returns a message saying “not
found”. It also uses status variable to search for the key intelligently.
BONUS Question:
Rewrite the class in such a way that it performs Quadratic Probing, i.e., add the square of i to
the hash value of key.
Hint: You have to change getNextCandidateIndex(int key, int i) method
*/

#include <iostream>
#include <string>

using namespace std;

class HashItem {
	friend class HashTable;
private:
	int key;
	string value;
	int status;
};

class HashTable {
public:
	HashItem* hashArray;
	int capacity;
	int currentElements;
	int getNextCandidateIndex(int key, int i) const;
	void doubleCapacity();
	void rehash();
	void insert(int const key, string const value);
	bool deleteKey(int const key);
	string get(int const key) const;

public:
	HashTable() : capacity(10), currentElements(0) {
		hashArray = new HashItem[capacity];
	}

	HashTable(int const capacity) : currentElements(0) {
		if (capacity < 1) {
			cerr << "Error: Capacity must be at least 1." << endl;
			return;
		}
		this->capacity = capacity;
		hashArray = new HashItem[capacity];
	}

	~HashTable() {
		delete[] hashArray;
	}
};

int HashTable::getNextCandidateIndex(int key, int i) const {
	return (key + (i * i)) % capacity;
}

void HashTable::doubleCapacity() {
	capacity *= 2;
	rehash();
}

void HashTable::rehash() {
	HashItem* oldArray = hashArray;
	int oldCapacity = capacity;
	currentElements = 0;

	hashArray = new HashItem[capacity];

	for (int i = 0; i < oldCapacity; ++i) {
		if (oldArray[i].status == 2) {
			insert(oldArray[i].key, oldArray[i].value);
		}
	}
	delete[] oldArray;
}

void HashTable::insert(int const key, string const value) {
	if (currentElements >= 0.75 * capacity) {
		doubleCapacity();
	}

	int index = key % capacity;


	int i = 1;
	while (hashArray[index].status == 2) {
		index = getNextCandidateIndex(key, i);
		++i;
	}


	hashArray[index].key = key;
	hashArray[index].value = value;
	hashArray[index].status = 2;
	++currentElements;
}

bool HashTable::deleteKey(int const key) {
	int index = key % capacity;

	int i = 1;
	while (hashArray[index].status != 0) {
		if (hashArray[index].key == key && hashArray[index].status == 2) {
			hashArray[index].status = 1;
			return true;
		}
		index = getNextCandidateIndex(key, i);
		++i;
	}
	return false;
}

string HashTable::get(int const key) const {
	int index = key % capacity;

	int i = 1;
	while (hashArray[index].status != 0) {
		if (hashArray[index].key == key && hashArray[index].status == 2) {
			return hashArray[index].value;
		}
		index = getNextCandidateIndex(key, i);
		++i;
	}
	return "Not found";
}

int main() {
	HashTable hashtable(5);


	hashtable.insert(101, "Alice");
	hashtable.insert(201, "Bob");
	hashtable.insert(301, "Charlie");
	hashtable.insert(401, "David");
	hashtable.insert(501, "Eva");


	string name = hashtable.get(201);
	if (name != "Not found") {
		cout << "Value at key 201: " << name << endl;
	}
	else {
		cout << "Key 201 not found!" << endl;
	}


	bool deleted = hashtable.deleteKey(301);
	if (deleted) {
		cout << "Key 301 deleted successfully." << endl;
	}
	else {
		cout << "Key 301 not found!" << endl;
	}


	name = hashtable.get(301);
	if (name != "Not found") {
		cout << "Value at key 301: " << name << endl;
	}
	else {
		cout << "Key 301 not found!" << endl;
	}
	system("pause>nul");
	return 0;
}