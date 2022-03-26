#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

string fractionToDecimal(int numerator, int denominator) {
    if(numerator == 0) return "0";
    else if(denominator == 1) return to_string(numerator);
    bool sign=true;
    if((numerator>0 && denominator<0) || (numerator<0 && denominator>0)) sign=false;
    long x = abs((long)numerator), y=abs((long)denominator);
    string result=to_string(x/y);
    x=x%y;
    if(x!=0) result+=".";
    unordered_map<int, int> mp; // 用map记录同一个除数出现的位置
    while(x!=0) {
        x*=10;
        if(mp.count(x)){ // 之前已经出现过这个数字
            result.insert(result.begin()+mp[x], '(');
            result+=')';
            return result;
        }
        else mp[x]=result.length();
        result+=to_string(x/y);
        x=x%y;
    }
    return result;
}