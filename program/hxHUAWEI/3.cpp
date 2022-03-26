#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

string replaceSpace(string str) {
    for(int i=str.length();i>=0;--i) {
        if(str[i]==' ') {
            str.replace(str.begin()+i, str.begin()+i+1, "%10");
        }
    }
    return str;
}

int main() {
    string str="abc d jf d";
    cout << replaceSpace(str) << endl;
    char a[]="abc";
    char b[]="abc";
    cout << (a==b) << endl;
}