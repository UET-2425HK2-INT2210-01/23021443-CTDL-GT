#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

//baitap1
#ifdef DISABLED
///prop1:giam kha nang collision- kha nang hai input khac nhau anh xa den cung mot key value
///prop2:input giong nhau luon cho cung mot key value
#endif

//baitap2
#ifdef DISABLED
struct node {
    int key;


    node* next;
    node(int k) : key(k), next(nullptr) {}
};

class hashMapChaining {
private:
    int cap = 11;
    vector<node*> table;

    int hashFunc(int key) {
        return (2 * key + 5) % cap;
    }
public:
    hashMapChaining() {
        table.resize(cap, nullptr);
    }

    void insert(int key) {
        int i = hashFunc(key);
        node* newNode = new node(key);
        newNode->next = table[i];
        table[i] = newNode;

    }
    void print() {
        for (int i = 0; i < cap; i++) {
            cout << i << " ";
            node* temp = table[i];
            while (temp) {
                cout << temp->key << " ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
    }
    ~hashMapChaining() {
        for (int i = 0; i < cap; i++) {
            node* temp = table[i];
            while (temp) {
                node* next = temp->next;
                delete temp;
                temp = next;
            }
        }
    }
};

class linearProbing {
private:
    int cap = 11;
    vector<int> table;
    vector<bool> occupied;
    int hashFunc(int key) {
        return (2 * key + 5) % cap;
    }
public:
    linearProbing() {
        table.resize(cap, -1);
        occupied.resize(cap, false);
    }

    void insert(int key) {
        int i = hashFunc(key);
        int start = i;
        while (occupied[i]) {
            i = (i + 1) % cap;
            if (i == start) {
                cout << "it is full" << endl;
                return;
            }

        }
        table[i] = key;
        occupied[i] = true;
    }

    void print() {
        for (int i = 0; i < cap; i++) {
            cout << i << " ";
            if (occupied[i])
                cout << table[i] << endl;
            else
                cout << "NULL\n";
        }
    }

};

int main() {
    hashMapChaining hashTableChaining;
    vector<int> keys = { 12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5 };
    for (size_t i = 0; i < keys.size(); i++) {
        hashTableChaining.insert(keys[i]);
    }
    hashTableChaining.print();
    cout << endl;
    linearProbing hashTableLinearProbing;
    for (size_t i = 0; i < keys.size(); i++) {
        hashTableLinearProbing.insert(keys[i]);
    }
    hashTableLinearProbing.print();
}
#endif

//baitap3
#ifdef DISABLED
struct node {
    int key;
    node* next;
    node(int k) : key(k), next(nullptr) {}
};

class hashMapChaining {
private:
    int cap = 17;
    vector<node*> table;

    int hashFunc(int key) {
        return (key + 3) % cap;
    }
public:
    hashMapChaining() {
        table.resize(cap, nullptr);
    }

    void insert(int key) {
        int i = hashFunc(key);
        node* newNode = new node(key);
        if (!table[i]) {
            table[i] = newNode;
        }
        else {
            node* temp = table[i];
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void print() {
        for (int i = 0; i < cap; i++) {
            node* temp = table[i];
            cout << "Index " << i << ": ";
            if (!temp) {
                cout << "NULL";
            }
            while (temp) {
                cout << temp->key;
                if (temp->next) {
                    cout << " -> ";
                }
                temp = temp->next;
            }
            cout << endl;
        }
    }

    ~hashMapChaining() {
        for (int i = 0; i < cap; i++) {
            node* temp = table[i];
            while (temp) {
                node* next = temp->next;
                delete temp;
                temp = next;
            }
            table[i] = nullptr;
        }
    }
};

class linearProbing {
private:
    int cap = 17;
    vector<int> table;
    vector<bool> occupied;
    int hashFunc(int key) {
        return (key + 3) % cap;
    }
public:
    linearProbing() {
        table.resize(cap, -1);
        occupied.resize(cap, false);
    }

    void insert(int key) {
        int i = hashFunc(key);
        int start = i;
        while (occupied[i]) {
            i = (i + 1) % cap;
            if (i == start) {
                cout << "it is full" << endl;
                return;
            }
        }
        table[i] = key;
        occupied[i] = true;
    }

    void print() {
        for (int i = 0; i < cap; i++) {
            cout << i << " ";
            if (occupied[i])
                cout << table[i] << endl;
            else
                cout << "NULL\n";
        }
    }
};

int main() {
    hashMapChaining hashTableChaining;
    vector<int> keys = { 1, 3, 18, 8, 23, 35, 11, 36, 20, 16 };

    for (size_t i = 0; i < keys.size(); i++) {
        hashTableChaining.insert(keys[i]);
    }
    hashTableChaining.print();

    cout << endl;

    linearProbing hashTableLinearProbing;
    for (size_t i = 0; i < keys.size(); i++) {
        hashTableLinearProbing.insert(keys[i]);
    }
    hashTableLinearProbing.print();
}
#endif

//baitap4
#ifdef DISABLED
struct node {
    int id;
    string name;
    string info;
    struct node* next;

    node(int i, string n, string in) : id(i), name(n), info(in), next(nullptr) {}
};

class hashMap {
private:
    int cap;
    vector<node*> table;

    int hashFunc(int id) {
        return id % cap;
    }

public:
    hashMap(int cap1 = 100) : cap(cap1) {
        table.resize(cap, nullptr);
    }

    void insert(int id, string name, string info) {
        int index = hashFunc(id);
        node* head = table[index];

        while (head) {
            if (head->id == id) {
                head->name = name;
                head->info = info;
                return;
            }
            head = head->next;
        }


        node* newNode = new node(id, name, info);
        newNode->next = table[index];
        table[index] = newNode;
    }

    void del(int id) {
        int index = hashFunc(id);
        node* head = table[index];
        node* prev = nullptr;

        while (head) {
            if (head->id == id) {
                if (prev) {
                    prev->next = head->next;
                }
                else {
                    table[index] = head->next;
                }
                delete head;
                return;
            }
            prev = head;
            head = head->next;
        }
    }

    void info(int id) {
        int index = hashFunc(id);
        node* head = table[index];

        while (head) {
            if (head->id == id) {
                cout << "OUTPUT: " << head->name << ',' << head->info << endl;
                return;
            }
            head = head->next;
        }
        cout << "OUTPUT: " << "NA,NA" << endl;
    }

    ~hashMap() {
        for (int i = 0; i < cap; i++) {
            node* temp = table[i];
            while (temp) {
                node* next = temp->next;
                delete temp;
                temp = next;
            }
            table[i] = nullptr;
        }
    }
};

int extractID(const string& input) {
    size_t start = input.find('(');
    size_t end = input.find(')');
    if (start == string::npos || end == string::npos) return -1;

    string idStr = input.substr(start + 1, end - start - 1);
    try {
        return stoi(idStr);
    }
    catch (...) {
        return -1;
    }
}

int main() {
    hashMap myMap;
    string input;

    while (getline(cin, input)) {
        if (input == "Stop") break;

        stringstream ss(input);
        string command;
        ss >> command;

        if (command.find("Insert") != string::npos) {
            int id;
            string name, info;

            size_t start = input.find('(');
            size_t end = input.find(')');
            if (start == string::npos || end == string::npos) {
                cout << "Invalid input format for Insert" << endl;
                continue;
            }

            string values = input.substr(start + 1, end - start - 1);
            stringstream valuesStream(values);
            string temp;

            if (!getline(valuesStream, temp, ',') || temp.empty()) {
                cout << "Invalid ID format" << endl;
                continue;
            }
            id = stoi(temp);

            if (!getline(valuesStream, name, ',')) {
                cout << "Invalid name format" << endl;
                continue;
            }
            getline(valuesStream, info);

            myMap.insert(id, name, info);
        }
        else if (command.find("Infor") != string::npos) {
            int id = extractID(input);
            if (id == -1) {
                cout << "Invalid Infor command format" << endl;
                continue;
            }
            myMap.info(id);
        }
        else if (command.find("Delete") != string::npos) {
            int id = extractID(input);
            if (id == -1) {
                cout << "Invalid Delete command format" << endl;
                continue;
            }
            myMap.del(id);
        }
        else {
            cout << "Unknown command: " << command << endl;
        }
    }
    return 0;
}
#endif