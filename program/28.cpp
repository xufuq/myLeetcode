#include <string>
#include <algorithm>

using namespace std;

int strStr(string haystack, string needle) {
    for(int i = 0; i < haystack.length() - needle.length(); i++) 
        if(!haystack.compare(i, needle.length(), needle))
            return i;
    return -1;
}

/* KMP寻找最长的前后最字符串
 * 寻找next数组是最关键的
 * 
 * 
*/