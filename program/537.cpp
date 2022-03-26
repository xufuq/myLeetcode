#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

string complexNumberMultiply(string num1, string num2) {
    istringstream is(num1);
    string num;
    getline(is, num, '+');
    int R1, I1, R2, I2;
    R1=stoi(num);
    getline(is, num, 'i');
    I1=stoi(num);
    is=istringstream(num2);
    getline(is, num, '+');
    R2=stoi(num);
    getline(is, num, 'i');
    I2=stoi(num);
    int R=R1*R2-I1*I2;
    int I=R1*I2+R2*I1;
    return to_string(R)+"+"+to_string(I)+"i";
}