#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
using namespace std;

static bool compareStr(string Lstr, string Rstr) {
    int lenL=Lstr.length(), lenR=Rstr.length();
    int result=Lstr.compare(0, min(lenL, lenR), Rstr, 0, min(lenL, lenR));
    if(result<0) return false;
    else if(result>0) return true;
    else {
        if(lenL==lenR) return false;
        else if(lenL>lenR)  // L 的长度比较大
            return compareStr(Lstr.substr(lenR, lenL-lenR), Rstr);
        else
            return compareStr(Lstr, Rstr.substr(lenL, lenR-lenL));
    }
}

static bool compare(int Lhs, int Rhs){
    string Lstr=to_string(Lhs), Rstr=to_string(Rhs);
    return compareStr(Lstr,Rstr);
}

string largestNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end(), compare);
    string result;
    for(auto num : nums)
        result+=to_string(num);
    return result;
}

int main(){
    // vector<int> nums={3,30,34,5,9};
    vector<int> nums={432, 43243};
    cout << largestNumber(nums);
}