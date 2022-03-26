#include <string>
#include <unordered_set>
using namespace std;


string reverseVowels(string s) {
    string yy = "aeiouAEIOU";
    int i=0, j=s.length()-1;
    while(i<j) {
        if(yy.find(s[i])<10 && yy.find(s[j])<10) { // 都是元音字母
            swap(s[i], s[j]);
            ++i, --j;
            continue;
        } 
        if(yy.find(s[i])>=10)
            ++i;
        if(yy.find(s[j])>=10)
            --j;
    }
    return s;
}