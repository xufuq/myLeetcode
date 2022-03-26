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

// 空格问题
string numberToWords(int num) {
    if(num == 0) return "Zero";
    vector<string> SysBase={"", "Thousand", "Million", "Billion"};
    vector<string> tenNums={"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    vector<string> tenSerials={"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> base={"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    string result;
    int i=0;
    while(num>0) {
        int n=num%1000;
        num/=1000;
        string str;
        if(n>=100)
            str+=base[n/100]+" Hundred ";
        n%=100;
        if(n>=10 && n<20)
            str+=tenSerials[n-10]+" ";
        else {
            if(n>10)
                str+=tenNums[n/10]+" ";
            n%=10;
            if(n>0)
                str+=base[n]+" ";
        }
        if(i!=0 && !str.empty())
            str+=SysBase[i]+" ";
        result=str+result;
        ++i;
        
    }
    while(result.back()==' ') result.pop_back();
    if(result[0]==' ') result.erase(result.begin());
    return result;
}