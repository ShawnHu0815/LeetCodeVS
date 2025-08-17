#include <iostream>
using namespace std;

class Q{
public:
    virtual int calculate(int a,int b){
        return a + b;
    }
    // double calculate(double a, double b) {
    //     return a * b;
    // }
    Q(){}

private:
    int m,n;
    // char c;
};

class C2:public Q{
public:
    int calculate(int c, int d) override{
        return c * d;
    }
    C2(){
        cout << "construct C2" << endl;
    };
};

int main(){
    Q C1;
    // C1 = new Q();
    // int ans = C1->calculate(2,3);
    cout << sizeof(C1) << endl;


    // ans = C1->calculate(2.0,3.0);
    // cout << ans << endl;


    // C1 = new C2();
    // int ans = C1->calculate(2,3);
    // cout << ans << endl;
    
    return 0;
}