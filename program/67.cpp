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

string addBinary(string a, string b) {
    int getIn=0;
    reverse(a.begin(), a.end()), reverse(b.begin(), b.end());
    string result;
    string &longStr=a.length()>b.length()?a:b;
    string &shortStr=a.length()>b.length()?b:a;
    for(int i=0;i<shortStr.length();i++) {
        int S=shortStr[i]=='1'?1:0, L=longStr[i]=='1'?1:0;
        if(getIn+S+L==3)      result+="1", getIn=1;
        else if(getIn+S+L==2) result+="0", getIn=1;
        else if(getIn+S+L==1) result+="1", getIn=0;
        else                  result+="0", getIn=0;
    }
    for(int i=shortStr.length(); i<longStr.length();++i) {
        int L=longStr[i]=='1'?1:0;
        if(getIn+L==2)      result+="0", getIn=1;
        else if(getIn+L==1) result+="1", getIn=0;
        else                result+="0", getIn=0;
    }
    if(getIn==1) result+="1";
    reverse(result.begin(), result.end());
    return result;
}