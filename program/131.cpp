#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<string> > result;

bool isCircle(const string str){ // 这里的判断可以用原字符串s和前后界，会节省一个字符空间
    int mid=str.length()/2, last=str.length()-1;
    for(int i=0; i<mid; ++i) 
        if(str[i]!=str[last-i])
            return false;
    return true;
}

void partition(string &s, int startIndex, vector<string> &path) {
    if(startIndex==s.length())
        result.push_back(path);
    for(int i=1; i<=s.length()-startIndex; ++i){ // i是后界，取不到
        string str = s.substr(startIndex, i);
        if(isCircle(str)){ // 是回文串,不是的话就一直查找
            path.push_back(str);
            partition(s, startIndex+i, path);
            path.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<string> path;
    partition(s, 0, path);
    return result;
}