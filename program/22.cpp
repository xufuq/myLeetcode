#include <vector>
#include <iostream>
#include <string>
using namespace std;

// 回溯法
vector<string> result;
void generateParenthesis(int n, int left, string &path){ // left表示还有多少个左括号没放
    if(left>0){
        path.push_back('(');
        generateParenthesis(n, left-1, path);
        path.pop_back();
    }
    if(path.length()<2*(n-left)){ // path中有左括号没匹配
        path.push_back(')');
        generateParenthesis(n, left, path);
        path.pop_back();
    }
    else if(path.length()==2*n){
        result.push_back(path);
    }
}

vector<string> generateParenthesis(int n) {
    string path;
    generateParenthesis(n, n, path);
    return result;
}