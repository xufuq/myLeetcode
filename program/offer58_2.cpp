#include <string>

using namespace std;

string reverseLeftWords(string s, int n) {
    for(int i = 0; i < n; i++) {
        auto c = s[0];
        s.erase(0,1);
        s.append(&c);
    }
    return s;
}

// 利用库获得子字符串
class Solution {
public:
    string reverseLeftWords(string s, int n) {
        s += s;
        return s.substr(n,s.size()/2);
    }
};

/* 或者翻转字符串
 * 先翻转前n个
 * 再翻转后面全部
 * 然后全部翻转
 * 完成
 * 没有额外申请空间
*/