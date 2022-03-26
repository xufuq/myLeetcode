#include <string>

using namespace std;

bool canConstruct(string ransomNote, string magazine) {
    int ranArray[26], magArray[26];
    for(auto &c : ransomNote)
        ++ranArray[c-'a'];
    for(auto &c : magazine)
        ++magArray[c-'a'];
    for(int i=0; i<26; ++i)
        if(ranArray[i]>magArray[i])
            return false;
    return true;
}