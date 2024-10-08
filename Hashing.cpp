#include <iostream>
#include <list>
using namespace std;

// Hash Table class
class HashTable {
private:
    int numBuckets;           // Number of buckets
    list<int>* table;         // Pointer to an array containing buckets (list)

public:
    // Constructor
    HashTable(int b) {
        numBuckets = b;
        table = new list<int>[numBuckets];
    }

    // Hash function to map values to key
    int hashFunction(int key) {
        return key % numBuckets;
    }

    // Insert a value into the hash table
    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    // Delete a value from the hash table
    void remove(int key) {
        int index = hashFunction(key);
        // Find the key in the list and remove it
        table[index].remove(key);
    }

    // Display the hash table
    void display() {
        for (int i = 0; i < numBuckets; i++) {
            cout << "Bucket " << i << ": ";
            for (auto x : table[i])
                cout << x << " -> ";
            cout << "NULL" << endl;
        }
    }
};

int main() {
    // Create a hash table with 7 buckets
    HashTable ht(7);

    // Insert values into the hash table
    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(17);
    ht.insert(6);
    ht.insert(12);

    cout << "Hash Table: " << endl;
    ht.display();

    // Remove a key from the hash table
    ht.remove(15);
    cout << "After removing 15: " << endl;
    ht.display();

    return 0;
}
