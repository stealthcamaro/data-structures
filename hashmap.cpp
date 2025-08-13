#include <iostream>
#include <list>
#include <string>
#include <vector>
using namespace std;

class HashMap {
private:
    // Number of buckets
    static const int SIZE = 10;
    // Each bucket is a list of key-value pairs
    vector<list<pair<string, string>>> table;

    // Simple hash function for strings
    int hashFunction(const string& key) {
        int hash = 0;
        for (char ch : key) {
            hash += ch;
        }
        return hash % SIZE;
    }

public:
    HashMap() {
        table.resize(SIZE);
    }

    // Insert or update a key-value pair
    void insert(const string& key, const string& value) {
        int index = hashFunction(key);
        // Check if key already exists
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value; // Update existing value
                cout << "Key updated.\n";
                return;
            }
        }
        // Otherwise insert new pair
        table[index].push_back({key, value});
        cout << "Key inserted.\n";
    }

    // Search for a key
    void search(const string& key) {
        int index = hashFunction(key);
        for (auto& pair : table[index]) {
            if (pair.first == key) {
                cout << "Found: " << pair.first << " => " << pair.second << endl;
                return;
            }
        }
        cout << "Key not found.\n";
    }

    // Delete a key
    void remove(const string& key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key deleted.\n";
                return;
            }
        }
        cout << "Key not found.\n";
    }

    // Print the entire hash map
    void print() {
        for (int i = 0; i < SIZE; i++) {
            cout << "[" << i << "]: ";
            for (auto& pair : table[i]) {
                cout << "(" << pair.first << " => " << pair.second << ") ";
            }
            cout << endl;
        }
    }
};

int main() {
    HashMap map;
    int choice;
    string key, value;

    do {
        cout << "\n------ Hash Map Menu ------n";
        cout << "1. Insert/Update Key\n";
        cout << "2. Search Key\n";
        cout << "3. Delete Key\n";
        cout << "4. Print Hash Map\n";
        cout << "5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                getline(cin, key);
                cout << "Enter value: ";
                getline(cin, value);
                map.insert(key, value);
                break;
            case 2:
                cout << "Enter key to search: ";
                getline(cin, key);
                map.search(key);
                break;
            case 3:
                cout << "Enter key to delete: ";
                getline(cin, key);
                map.remove(key);
                break;
            case 4:
                cout << "Hash Map contents:\n";
                map.print();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
