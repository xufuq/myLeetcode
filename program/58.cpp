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

int countSegments(string s) {
    istringstream is(s);
    string word;
    while(is >> word);
    return word.length();
}

int main() {
    string strr="Hello, my name is John";
    cout << countSegments(strr) << endl;
}