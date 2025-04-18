//bai 1

#include<iostream>
using namespace std;


int sum(int n) {
    if (n == 1) {           // dieu kien dung: neu n = 1 thi tra ve 1
        return 1;
    }
    return n + sum(n - 1);  // cong n voi tong cua (n - 1)
}

int main() {
    int n;
    cin >> n;               // nhap gia tri n
    cout << sum(n);         // in ra tong tu 1 den n
    return 0;
}


// bai2
#include<iostream>
using namespace std;


long long factorial(int n) {
    if (n == 1 || n == 0) {   // neu n = 1 hoac 0 thi giai thua la 1
        return 1;
    }
    return n * factorial(n - 1);  // cong thuc de quy: n! = n * (n-1)!
}

int main() {
    int n;
    cin >> n;                  // nhap n
    cout << factorial(n);      // in ra n!
    return 0;
}



//bai3
#include<iostream>
using namespace std;


int fibonacci(int n) {
    if (n == 0) {           // so thu 0 la 0
        return 0;
    }
    if (n == 1) {           // so thu 1 la 1
        return 1;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);  // cong hai so truoc do
}

int main() {
    int n;
    cin >> n;               // nhap n
    cout << fibonacci(n);   // in ra so Fibonacci thu n
    return 0;
}


//bai4
#include<iostream>
using namespace std;


int luyThua(int x, int n) {
    if (n == 0) {           // x^0 = 1
        return 1;
    }
    return x * luyThua(x, n - 1); // x^n = x * x^(n-1)
}

int main() {
    int x, n;
    cin >> x >> n;          // nhap x va n
    cout << luyThua(x, n);  // in ra x^n
    return 0;
}

//bai5
#include<iostream>
using namespace std;


int countNumbers(int n, int count) {
    int r = n / 10;         // loai bo chu so cuoi cung

    if (r == 0) {           // neu chi con mot chu so thi dung lai
        return count;
    }
    return countNumbers(r, count + 1); // tang bien dem va goi de quy tiep
}

int main() {
    int n;
    cin >> n;                         // nhap so nguyen n
    cout << countNumbers(n, 1);      // goi ham de dem so chu so
    return 0;
}


//bai6

#include<iostream>
using namespace std;


int sumNumbers(int n) {
    if (n == 0) {              // khi het chu so thi tra ve 0
        return 0;
    }
    return (n % 10) + sumNumbers(n / 10);  // lay chu so cuoi + goi de quy phan con lai
}

int main() {
    int n;
    cin >> n;                  // nhap so nguyen n
    cout << sumNumbers(n);     // in ra tong cac chu so
    return 0;
}

//bai7

#include<iostream>
using namespace std;


int reverseNumbers(int n, int revNum) {
    if (n == 0) {                     // khi khong con chu so nao thi tra ve so dao nguoc
        return revNum;
    }
    return reverseNumbers(n / 10, revNum * 10 + (n % 10));
    // lay chu so cuoi them vao revNum va goi de quy voi n/10
}

int main() {
    int n;
    cin >> n;                          // nhap so nguyen n
    cout << reverseNumbers(n, 0);     // dao nguoc n bat dau tu revNum = 0
    return 0;
}