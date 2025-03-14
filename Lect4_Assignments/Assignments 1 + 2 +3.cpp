#include <iostream>
#include <string>
using namespace std;
//baitap1
#ifdef DISABLED
struct node {
    int data;
    node* next;
};

class linkedList {
    node* head;
public:
    linkedList() : head(NULL) {}
    void append(int x) {
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

    void search(int x) {
        node* temp = head;
        int dem = 0;
        while (temp) {
            if (temp->data == x) {
                cout << dem << endl;
                break;
            }
            else {
                dem++;
                temp = temp->next;
            }
        }

    }

    void reverse() {
        node* prev = NULL;
        node* cur = head;
        node* next = NULL;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;

    }
    void print() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    ~linkedList() {
        node* temp;
        while (temp) {
            temp = head;
            head = head->next;
            delete temp;
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
        if (s == "append") {
            int x;
            cin >> x;
            list.append(x);
        }
        else if (s == "search") {
            int x;
            cin >> x;
            list.search(x);
        }
        else if (s == "reverse") {
            list.reverse();
            list.print();
        }
    }
    return 0;
}


#endif

//baitap2
#ifdef DISABLED
struct node {
    int data;
    int priority;
    node* next;
    node* prev;
};

class doublyLinkedList {
    node* head;
public:
    doublyLinkedList() : head(NULL) {};
    void enqueue(int x, int p) {
        node* newNode = new node();
        newNode->data = x;
        newNode->priority = p;
        newNode->next = NULL;
        newNode->prev = NULL;
        if (head == NULL || p > head->priority) {
            newNode->next = head;
            if (head != NULL) {
                newNode->prev = newNode;
            }
            head = newNode;
            return;
        }
        node* temp = head;
        while (temp->next != NULL && temp->next->data >= p) {
            temp = temp->next;

        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;

    }
    void dequeue() {
        node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;

    }
    void print() {
        node* temp = head;
        while (temp != NULL) {
            cout << "(" << temp->data << "," << temp->priority << "); ";
            temp = temp->next;
        }

    }


};

int main() {
    int n;
    cin >> n;
    doublyLinkedList list;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int x, p;
            cin >> x >> p;
            list.enqueue(x, p);
        }
        else if (s == "dequeue") {
            list.dequeue();
        }

    }
    list.print();
}
#endif

//baitap3
#ifdef DISABLED
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
        newNode->next = head;
        head = newNode;

    }
    void pop() {
        if (head == NULL) {
            return;
        }
        node* temp = head;
        head = head->next;
        delete temp;
    }
    bool empty() {
        return head == NULL;
    }
    char top() {
        if (head == NULL) {
            return '\0';
        }
        return head->data;
    }

};

bool valid(string s) {
    linkedList stack;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack.push(c);
        }
        else {
            if (stack.empty()) {
                return false;
            }
            char top = stack.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                stack.pop();
            }
            else {
                return false;
            }
        }

    }
    return stack.empty();
}
int main() {
    string s;
    while (cin >> s) {
        if (valid(s)) {
            cout << "Valid" << endl;
        }
        else {
            cout << "Invalid" << endl;
        }
    }
    return 0;

}
#endif