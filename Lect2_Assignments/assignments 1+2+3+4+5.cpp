#include <iostream>

using namespace std;

//baitap1
#ifdef ENABLED
int main() {
    int n;
    int count = 0;
    cin >> n;
    vector<int> store(n);
    for (int i = 0; i < n; i++) {
        cin >> store[i];
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (store[i] == store[j]) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
#endif

//baitap2
#ifdef ENABLED
struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL) {}
    void insert(int p, int x) {
        node* newNode = new node();
        newNode->data = x;
        if (p == 0) {
            newNode->next = head;
            head = newNode;
        }
        else {
            node* temp = head;
            for (int i = 0; i < p - 1 && temp; i++) {
                temp = temp->next;
            }if (!temp) {
                delete newNode;
                return;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }

    void delete1(int p) {
        if (p == 0) {
            node* temp = head;
            head = head->next;
            delete temp;
        }
        else {
            node* temp = head;
            for (int i = 0; i < p - 1 && temp; i++) {
                temp = temp->next;

            }
            if (!temp || !temp->next) {
                cout << p;
                return;
            }
            node* nodeDeleted = temp->next;
            temp->next = temp->next->next;
            delete nodeDeleted;
        }
    }
    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }

    }
};

int main() {
    int n;
    cin >> n;
    linkedList list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "insert") {
            int p, x;
            cin >> p >> x;
            list.insert(p, x);
        }
        else if (s == "delete") {
            int p;
            cin >> p;
            list.delete1(p);
        }
    }
    list.print();
    return 0;

}
#endif

//baitap3
#ifdef ENABLED
struct node {
    int data;
    node* next;
    node* prev;
};


class doublyLinkedList {
    node* head;
public:
    doublyLinkedList() : head(NULL) {};
    void insert(double x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL) {
            newNode->next = head;
            if (head != NULL) {
                head->prev = newNode;
            }
            head = newNode;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;

        }
    }
    int count_triplet() {
        int dem = 0;
        node* temp = head;
        while (temp != NULL && temp->next != NULL && temp->next->next != NULL) {
            int sum = temp->data + temp->next->data + temp->next->next->data;
            if (sum == 0) {
                dem++;
            }
            temp = temp->next;
        }
        return dem;
    }

};

int main() {
    int n;
    cin >> n;
    doublyLinkedList list;
    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;
        list.insert(x);
    }
    cout << list.count_triplet() << endl;
    return 0;
}
#endif

//baitap4
#ifdef ENABLED
struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL) {}
    void queue1(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;

        }
    }
    void dequeue1() {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    void printList() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

int main() {
    int n;
    cin >> n;
    linkedList queue;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int num;
            cin >> num;
            queue.queue1(num);
        }
        else if (s == "dequeue") {
            queue.dequeue1();
        }
    }
    queue.printList();
    return 0;
}
#endif

//baitap5
#ifdef ENABLED
struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL) {}
    void push(int x) {
        node* newNode = new node();
        newNode->data = x;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->next = head;
            head = newNode;
        }
        else {
            node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;

        }
    }
    void pop() {
        node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    void printStack() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

};
int main() {
    int n;
    cin >> n;
    linkedList stack;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int num;
            cin >> num;
            stack.push(num);
        }
        else if (s == "pop") {
            stack.pop();
        }
    }
    stack.printStack();
    return 0;
}
#endif