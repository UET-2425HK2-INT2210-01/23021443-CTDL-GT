///baitap1
#ifdef DISABLED
2 ^ 10: O(1);
^ log(n) : O(log(n));
4n : O(n);
3n + 100log(n) : O(n)
nlog(n) : O(nlog(n))
4nlog(n) : O(nlog(n))
n ^ 2 + 10n : O(n ^ 2)
n ^ 3 : O(n ^ 3)
2 ^ n : O(2 ^ n)


#endif

///baitap2
#ifdef DISABLED
#ifdef DISABLED1
int pow2(int n) {
    if (n < 0) {
        cout << "n phai lon hon hoac bang 0";
        return 0;
    }
    else if (n == 0) {
        return 1;
    }
    int result = 1;
    for (int i = 0; i < n; i++) {
        result *= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << pow2(n);
}
#endif
///pseudo-code
#ifdef pseudo
funtion pow2(num)
if n < 0
    return "n phai lon hon hoac bang 0"
    if n == 0
        return 1
        result 1
        for i from 0 to n - 1
            result = result * 2
            return result
///time complexity = O(n) do chay vong lap for n lan
/// space complexity = O(1) voi input n code dung nhieu khoang trong mac ke n
#endif

#ifdef DISABLED2

            int pow2(int n) {
            if (n < 0) {
                cout << "n phai lon hon hoac bang 0";
                return -1;
            }
            else if (n == 0) {
                return 1;
            }
            if (n % 2 == 0) {
                int temp = pow2(n / 2);
                return temp * temp;
            }
            else if (n % 2 == 1) {
                int temp = pow2((n - 1) / 2);
                return 2 * temp * temp;
            }
        }

int main() {
    int n;
    cin >> n;
    cout << pow2(n) << endl;
}
#endif
///pseudo code
#ifdef pseudo
function pow2(int n)
if n < 0
    cout << "n phai lon hon hoac bang 0"
else if n == 0
return 1
if n % 2 == 0
int temp = pow2(n / 2)
return temp * temp
else if n % 2 == 1
int temp = pow2((n - 1) / 2)
return 2 * temp * temp
///time complexity O(log(n)) boi vi ta goi lai n/2 
///space complexity O(log(n)) tuong tu nhu tren
#endif
#endif

//baitap3
#ifdef DISABLED
void enqueue(int arr[], int size, int element, int& first, int& last, int& count) {
    if (count == size) {
        cout << "Array is full" << endl;
        return;
    }
    arr[last] = element;
    last = (last + 1) % size;
    count++;
}

int dequeue(int arr[], int& first, int& last, int& count, int size) {
    if (count == 0) {
        cout << "Array is empty" << endl;
        return -1;
    }
    int element = arr[first];
    first = (first + 1) % size;
    count--;
    return element;
}

void print(int arr[], int size, int first, int last, int count) {
    if (count == 0) {
        return;
    }
    int i = first;
    while (count > 0) {
        cout << arr[i] << " ";
        i = (i + 1) % size;
        count--;
    }
    cout << endl;
}

int main() {
    int size, first = 0, last = 0, count = 0;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        if (s == "enqueue") {
            int element;
            cin >> element;
            enqueue(arr, size, element, first, last, count);
        }
        else if (s == "dequeue") {
            dequeue(arr, first, last, count, size);
        }
    }
    print(arr, size, first, last, count);
    delete[] arr;
    return 0;
}
///pseudocode
#ifdef DISABLED
function enqueue(int arr[], int size, int element, int& first, int& last, int& count)
if count == size
print "Array is full"
return
queue[last] = element
last = (last + 1) % size
count = count + 1

function dequeue(int arr[], int& first, int& last, int& count, int size)
If count == 0:
Print "Array is empty"
Return - 1
element = queue[first]
    first = (first + 1) % size
        count = count - 1
        Return element

        function print(queue, size, first, last, count)
        If count == 0:
    Return
        i = first
        While count > 0:
    Print queue[i]
        i = (i + 1) % size
            count = count - 1

            main :
            Read size
            first = 0
            last = 0
            count = 0
            Allocate queue of size
            For each input :
        Read string
            If string is "enqueue" :
            Read element
            Call enqueue(queue, size, element, first, last, count)
            Else If string is "dequeue" :
            Call dequeue(queue, first, last, count, size)
            Call print(queue, size, first, last, count)
            Deallocate queue
            End Main
///timecomplexity: ham enqueue co insert element O(1) + ham dequeue removing and update first tuong duong O(1) + ham print co vong lap while tuong duong O(n) + ham main set memomry new int[size] tuong duong O(n) => lay ham cao nhat la O(n)
///spacecomplexity: : ham enqueue , dequeue , print deu la O(1) vi khong su dung them memomry, ham main co set array nen la O(n) =. lay mu cao nhat la O(n)

#endif
#endif

///baitap4
#ifdef DISABLED
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

///pseudo
#ifdef DISABLED
Struct Node :
int data
Node* next

Class LinkedList :
Node * head

Method INIT :
Set head to NULL

Method QUEUE1(x) :
    Create newNode
    Set newNode.data to x
    Set newNode.next to NULL
    If head is NULL :
Set newNode.next to head
Set head to newNode
Else :
Set temp to head
While temp.next is not NULL :
    Set temp to temp.next
    End While
    Set temp.next to newNode
    End If
    End Method

    Method DEQUEUE1 :
Set temp to head
Set head to head.next
Delete temp
End Method

Method PRINT_LIST :
Set temp to head
While temp is not NULL :
    Print temp.data
    Set temp to temp.next
    End While
    End Method
    End Class

    Main :
Read n
Create LinkedList queue
For i from 0 to n - 1 :
    Read string
    If stringd is "enqueue" :
    Read num
    Call queue.QUEUE1(num)
    Else If string is "dequeue" :
    Call queue.DEQUEUE1()
    End If
    End For
    Call queue.PRINT_LIST()
#endif
///timecomplexity: ham queue1 chay vong lap nen la O(n) , ham dequeue1 bo mot thanh phan thi chi la O(1)  , ham printList chay vong lap in nen la O(n) , ham main la O(n^2) vi goi ham queue1 => lay mu cao nhat O(n^2)
///spacecomplexity: ham queue1, ham dequeue1 va ham printList deu la O(1), ham main store n node nen la O(n) => lay mu cao nhat O(n)

#endif

/// baitap5
#ifdef DISABLED
void push(int arr[], int size, int element, int& last, int& count) {
    if (count == size) {
        cout << "Array is full" << endl;
        return;
    }
    arr[last] = element;
    last = (last + 1) % size;
    count++;
}

int pop(int arr[], int& last, int& count, int size) {
    if (count == 0) {
        cout << "Array is empty" << endl;
        return -1;
    }
    last = (last - 1 + size) % size;
    int element = arr[last];
    count--;
    return element;
}

void print(int arr[], int size, int last, int count) {
    if (count == 0) {
        return;
    }
    int i = (last - count + size) % size;
    while (count > 0) {
        cout << arr[i] << " ";
        i = (i + 1) % size;
        count--;
    }
    cout << endl;
}

int main() {
    int size, last = 0, count = 0;
    cin >> size;
    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        string s;
        cin >> s;
        if (s == "push") {
            int element;
            cin >> element;
            push(arr, size, element, last, count);
        }
        else if (s == "pop") {
            pop(arr, last, count, size);
        }
    }
    print(arr, size, last, count);
    delete[] arr;
    return 0;
}
///pseudo
#ifdef DISABLED
Function push(arr, size, element, last, count) :
    If count is equal to size :
Print "Array is full"
Return
End If
arr[last] = element
last = (last + 1) % size
count = count + 1
End Function

Function pop(arr, last, count, size) :
    If count is equal to 0 :
    Print "Array is empty"
    Return - 1
    End If
    last = (last - 1 + size) % size
    element = arr[last]
    count = count - 1
        Return element
        End Function

        Function print(arr, size, last, count) :
        If count is equal to 0 :
        Return
        End If
        i = (last - count + size) % size
        While count > 0:
    Print arr[i]
        i = (i + 1) % size
            count = count - 1
            End While
            Print a new line
            End Function

            Main :
        Input size
            arr = array of size
            last = 0
            count = 0
            For i from 0 to size - 1 :
            Input string
            If string is "push" :
            Input element
            Call push(arr, size, element, last, count)
            Else If string is "pop" :
            Call pop(arr, last, count, size)
            End If
            End For
            Call print(arr, size, last, count)
            End Main
///timecomplexity:ham push va pop chi check dieu kien nen co O(1), ham print su dung vong lap nen la O(n) , ham main chay vong lap call cach ham o tren nen co O(n) => lay mu cao nhat ta co O(n)
///spacecomplexity: 3 ham push, pop , print khong su dung them bo nho nen ta co O(1) , trong khi ham main co set array arr nen co O(n) = > lay mu cao nhat ta co O(n)

#endif
#endif

/// baitap6
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
///pseudo
#ifdef DISABLED
Struct Node :
int data
Node* next

Class LinkedList :
Node * head

Method INIT :
Set head to NULL

Method PUSH(x) :
    Create newNode
    Set newNode.data to x
    Set newNode.next to NULL
    If head is NULL :
Set newNode.next to head
Set head to newNode
Else :
Set temp to head
While temp.next is not NULL :
    Set temp to temp.next
    End While
    Set temp.next to newNode
    End If
    End Method

    Method POP :
Set temp to head
While temp.next.next is not NULL :
    Set temp to temp.next
    End While
    Delete temp.next
    Set temp.next to NULL
    End Method

    Method PRINT_STACK :
Set temp to head
While temp is not NULL :
    Print temp.data
    Set temp to temp.next
    End While
    End Method
    End Class

    Main :
Read n
Create LinkedList stack
For i from 0 to n - 1 :
    Read string
    If string is "push" :
    Read num
    Call stack.PUSH(num)
    Else If string is "pop" :
    Call stack.POP()
    End If
    End For
    Call stack.PRINT_STACK()
    End Main
///timecomplexity: ham push chay vong lap nen la O(n) , ham pop chay vong lap nen la O(n)   , ham printStack chay vong lap in nen la O(n) , ham main la O(n^2) vi goi ham push va pop la O(n) => lay mu cao nhat O(n^2)
///spacecomplexity: ham push, ham pop va ham printStack deu la O(1), ham main store n node nen la O(n) => lay mu cao nhat O(n)
#endif
#endif