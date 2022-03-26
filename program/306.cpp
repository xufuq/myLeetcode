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

// bool isAdditiveNumber(string num) {
//     int end=1; // 第一个子串
//     while(end<=num.length()/2) {
//         int start1=0, len1=end;
//         cout << end << endl;
//         // while(start1+len1<num.length() && num[start1+len1]=='0') ++len1;
//         if(len1==end) ++end;
//         else          end=len1;
//         int len2=1;
        
//         while(start1+len1+len2<num.length()){
//             // while(start1+len1+len2<num.length() && num[start1+len1+len2]=='0') ++len2;
//             string result=addStrings(num.substr(start1, len1), num.substr(start1+len1, len2));
//             cout << "num1: " << num.substr(start1, len1) << " num2: " << num.substr(start1+len1, len2) << " result: " << result << endl;
//             if(result.length()>num.length()-start1-len1-len2) break;
//             if(len2>1 && num[start1+len1]=='0') break;
//             if(result.compare(num.substr(start1+len1+len2, result.length()))!=0) {
//                 ++len2;
//                 continue;
//             }
//             if(start1+len1+len2+result.length()==num.length()) return true;
//             else {
//                 start1=start1+len1;
//                 len1=len2;
//             }
//             len2=1;
//             // cout << "num1: " << num.substr(start1, len1) << " num2: " << num.substr(start1+len1, len2) << endl;
//         }
//     }
//     return false;
// }

// 可能出现的情况过多，用深度优先搜索试试
bool isAdditiveNumber(string &num, int sIndex1, int sIndex2) {
    int len2=1;
    string str1=num.substr(sIndex1, sIndex2-sIndex1);
    while(sIndex2+len2<num.length()){
        string result=addStrings(str1, num.substr(sIndex2, len2));
        cout << "num1: " << str1 << " num2: " << num.substr(sIndex2, len2) << " result: " << result << endl;
        if(result.length()+sIndex2+len2>num.length()) return false;
        if(len2>1 && num[sIndex2]=='0') return false;
        if(result.compare(num.substr(sIndex2+len2, result.length()))!=0) {
            ++len2;
            continue;
        }
        if(sIndex2+len2+result.length()==num.length()) return true;
        else if(isAdditiveNumber(num, sIndex2, sIndex2+len2)) return true;
        else ++len2;
    }
    return false;
}

bool isAdditiveNumber(string num) {
    int sIndex2=1;
    while(sIndex2<=num.length()/2) {
        if(isAdditiveNumber(num, 0, sIndex2)) return true;
        ++sIndex2;
    }
    return false;
}

int main() {
    string num = "111122335588143";
    cout << isAdditiveNumber(num) << endl;
}