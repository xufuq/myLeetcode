#include <iostream>
using namespace std;

class A {
public:
A();
virtual int B()=0;
virtual ~A();
private:
int a;
};

void f(char c) {
    cout << " char " << c << endl;
}


void f(long c) {
    cout << " long " << c << endl;
}

int main() {
    cout << sizeof(A) << endl;
    int a=10;
    A *p;
    // A pp;
}