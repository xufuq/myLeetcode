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

string addStrings(string num1, string num2) {
    int getIn=0;
    reverse(num1.begin(), num1.end()), reverse(num2.begin(), num2.end());
    string result;
    string &longStr=num1.length()>num2.length()?num1:num2;
    string &shortStr=num1.length()>num2.length()?num2:num1;
    for(int i=0;i<shortStr.length();i++) {
        int S=shortStr[i]-'0', L=longStr[i]-'0', sum=getIn+S+L;
        result+=to_string(sum%10);
        getIn=sum/10;
    }
    for(int i=shortStr.length(); i<longStr.length();++i) {
        int L=longStr[i]-'0', sum=getIn+L;
        result+=to_string(sum%10);
        getIn=sum/10;
    }
    if(getIn==1) result+="1";
    reverse(result.begin(), result.end());
    return result;
}