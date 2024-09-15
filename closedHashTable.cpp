#include <iostream>
#include <string>

using namespace std;

const int TABLE_SIZE = 10;

struct Node {
    string key;
    int value;
    bool occupied;
};

class HashTable {
private:

    Node table[TABLE_SIZE];

public:
    HashTable() {
        // Initialize all nodes as unoccupied
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i].occupied = false;
        }
    }


    // TODO: Implement this function
    void insert(const string& key, int value) {
     int bucket = getHash(key);
        for (int tries = 0; tries < TABLE_SIZE; tries++){
            if(table[bucket].occupied == false){
                table[bucket].key = key;
                table[bucket].value = value;
                table[bucket].occupied = true;
                cout << "adding " << key << " with hash " << getHash(key) << endl;
                return;
            }
            bucket = (bucket + 1) % TABLE_SIZE;
        }

    }

    // TODO: Implement this function
    bool contains(const string& key) {
     int bucket = getHash(key);
        while(table[bucket].occupied){
            if(table[bucket].key == key){
                return true;
            }
            bucket = (bucket + 1) % TABLE_SIZE;
        }
        return false;
    }


    void printTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << i << ": ";
            if (table[i].occupied) {
                cout << table[i].key << " => " << table[i].value;
            } else {
                cout << "<empty>";
            }
            cout << endl;
        }
    }

private:
    int getHash(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash = (hash * 31 + c) % TABLE_SIZE;
        }
        return hash;
    }
};

int main() {

    HashTable table;
    string str;
    cout<<"\nMenu:\na: add a value\np: print the hash table\nc: test if the table contains a value\nq: quit\n";
    char ch;
    bool loop = true;
    while(loop)
    {            
        cout << "Enter a choice: " << endl;
        cin >> ch;
        switch(ch)
        {
            case 'q':
                loop = false;
                break;
            case 'p':
                table.printTable();
                break;   
            case 'c':
            {
                getline (cin,str);
                cout << "Enter a key to search " << endl;
                getline (cin,str);
                cout << (table.contains(str)==1?"yes":"no") << endl;
                break;
            }                   
            case 'a':
            {
                int val;
                getline (cin,str);
                cout << "Enter a key to add " << endl;
                getline (cin,str);
                cout << "Enter a value (int)" << endl;
                cin >> val;
                table.insert(str, val);
                break;
            }

        }  
    }  

    return 0;
}