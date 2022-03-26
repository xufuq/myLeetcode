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

string multiply(string num1, string num2) {
    if(num1=="0" || num2=="0") return "0";
    int getIn=0;
    reverse(num1.begin(), num1.end()), reverse(num2.begin(), num2.end());
    string result="0";
    string &longStr=num1.length()>num2.length()?num1:num2;
    string &shortStr=num1.length()>num2.length()?num2:num1;
    for(int i=0;i<shortStr.length();++i) {
        int S=shortStr[i]-'0', L=0, mulSL=0, getIn=0;
        string curRes;
        for(auto &c : longStr) {
            L=c-'0', mulSL=L*S+getIn;
            curRes+=to_string(mulSL%10);
            getIn=mulSL/10;
        }
        if(getIn!=0) curRes+=to_string(getIn);
        reverse(curRes.begin(), curRes.end());
        curRes+=string(i, '0');
        result=addStrings(result, curRes);
    }
    return result;
}