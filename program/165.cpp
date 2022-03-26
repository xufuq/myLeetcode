#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

int compareVersion(string version1, string version2) {
    istringstream line1(version1), line2(version2);
    string str1, str2;
    int num1, num2;
    while(!line1.eof() || !line2.eof()) {
        if(getline(line1, str1, '.'))
            num1=stoi(str1);
        else
            num1=0;
        if(getline(line2, str2, '.'))
            num2=stoi(str2);
        else
            num2=0;
        if(num1<num2) return -1;
        else if(num1>num2) return 1;
    }
    return 0;
}

int main(){
    // string version1="1.0.1", version2="7.5.3";
    string version1="7.5.3.4", version2="7.5.3";
    cout << compareVersion(version1, version2);
}