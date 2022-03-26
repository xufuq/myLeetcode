#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
using namespace std;

// 超出时间限制
unordered_set<string> result;

void removeInvalidParentheses(string &s, int startIndex){
    stack<int> st;
    for(int i = startIndex; i < s.length(); i++) {
        if(s[i] == '(' ) st.push(i);
        else if(s[i] == ')'){
            if(!st.empty()){
                st.pop();
                if(st.empty())
                    startIndex=i+1;
            }
            else { // 已经空了，需要从当前或者前面删除字符
                for(int j = 0; j <=i; ++j){
                    if(s[j] == ')'){
                        s.erase(s.begin()+j);
                        removeInvalidParentheses(s, j);
                        s.insert(s.begin()+j, ')');
                    }
                }
                return;// 已经不满足条件，直接返回，不要当前分支了
            }
        }
    }
    cout << startIndex << " " << s << endl;
    if(st.empty()){
        result.insert(s);

    }
    else { // 后边多（，从startIndex开始删除
        cout << "not empty: " << s << endl;
        for(int i=startIndex;i<s.length();++i){
            if(s[i] == '('){
                s.erase(s.begin()+i);
                cout << "earse: " << s << endl;
                removeInvalidParentheses(s, i);
                s.insert(s.begin()+i, '(');
            }
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    removeInvalidParentheses(s, 0);
    return vector<string>(result.begin(), result.end());
}

// 这种求列举而不是数量的题动归很难做出来
// vector<string> removeInvalidParentheses(string s) {
//     vector<vector<int>> dp(s.length()+1, vector<int>(3, 0));
//     for(auto i=1;i<=s.length();++i){
//         if(s[i-1] == '('){
//             dp[i][0]=dp[i-1][0]+1;
//             dp[i][1]=dp[i-1][1];
//         }
//         else if(s[i-1] == ')'){
//             dp[i][0]=dp[i-1][0];
//             dp[i][1]=dp[i-1][1]+1;
//         }
//         dp[i][2]=dp[i][0]-dp[i][1];
//     }
//     for(auto n : dp){
//         cout << n[0] << " "<< n[1] << " " << n[2] <<  endl;
//     }
//     return vector<string>();
// }

// 官方题解是先统计需要删除的左括号和右括号，然后在用递归来做
// 而且要考虑当前已采用的字符当中左右括号的数量

int main(){
    // string str="())((((((((((b))(";
     string str="()())()";
    auto r=removeInvalidParentheses(str);

}