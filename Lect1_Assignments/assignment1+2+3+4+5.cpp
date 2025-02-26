#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//baitap1
#ifdef ENABLE_TESTS
int main(){
    string s;
    getline(cin, s);
    for ( int i = s.size(); i >=0 ; i-- ){
        cout << s[i];
    }
    return 0;
}
#endif

//baitap2
#ifdef ENABLE_TESTS
class Point{
    public:
    double x ,y;
    void import(){
        cin >> x >> y;
    }

};

class Line{
    public:
    double a, b;
    Line (Point p1, Point p2){
        a=(p1.y-p2.y)/(p1.x-p2.x);
        b=p1.y-(p1.x*a);
    }
};

void findIntersectionPoint(Line l1, Line l2){
    if (l1.a == l2.a && l1.b == l2.b){
        cout << "MANY" << endl;
    }
    else if (l1.a == l2.a && l1.b != l2.b){
        cout << "NO" << endl;
    }
    else{
        double x,y;
         x=(l1.b-l2.b)/(l2.a-l1.a);
         y=(l1.a*x-l1.b);
         cout << fixed << setprecision(2) << x << " " << y << endl;
    }
}

int main(){
    Point A, B, C, D;
    A.import();
    B.import();
    C.import();
    D.import();
    Line AB(A, B);
    Line CD(C, D);
    findIntersectionPoint(AB, CD);
    return 0;
}
#endif

//baitap3
#ifdef ENABLED_TESTS
int gcd (int a, int b){
    if (b==0){
        return a;
    }
    return gcd(b, a %b);

}

int main(){
    int a ,b;
    cin >> a >> b;
    cout <<gcd(a,b) << endl;
    return 0;
}
#endif

//baitap4
#ifdef ENABLED_TESTS
int main (){
    int n;
    cin >> n;
    vector<int> listNum(n);
    for (int i = 0 ; i < n ; i++){
        cin >> listNum[i];
    }
    sort(listNum.begin(), listNum.end());
    for (int i = 0 ; i < n ; i++){
        cout << listNum[i] << " ";
    }
    return 0;
}
#endif

//baitap5
#ifdef ENABLED_TESTS
int main (){
    vector<int> listNum(5);
    for (int i = 0 ; i < 5 ; i++){
        cin >> listNum[i];
    }
    sort(listNum.begin(), listNum.end());
    cout << listNum.front() + listNum.back() << endl;
    return 0;
}
#endif
