#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

// word1作为外层循环，看最后一行数字的变化
// 这个dp的思路就不对
int minDistance(string word1, string word2) {
    int len1=word1.length(), len2=word2.length();
    vector<vector<int>> dp(len1+1);
    for(int i=1; i<=len2;++i){
        for(int j=1; j<=len1;++j){
            if(word1[j-1]==word2[i-1]) dp[j].push_back(i);
        }
    }

    // 从后往前找到dp中间隔最小的递增序列
    // 从最后一列开始找
    vector<int> dp2(len2, 0);

    for(auto a : dp){
        for(auto b : a)
            cout << b <<" ";
        cout << endl;
    }
}

// dp数组的内容应该是记录当前i，j两段中，至少需要的操作有多少
int minDistance(string word1, string word2) {
    int len1=word1.length(), len2=word2.length();
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    // 这是代表没有字符的时候的初始化
    for(int i=0;i<=len1;++i)
        dp[i][0]=i;
    for(int i=0;i<=len2;++i)
        dp[0][i]=i;
    // i、j代表有多少个字符
    for(int i=1;i<=len1;++i){
        for(int j=1;j<=len2;++j){
            if(word1[i-1]==word2[j-1]) dp[i][j]=dp[i-1][j-1];
            else dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]})+1;
        }
    }
    return dp[len1][len2];
}

int main(){
    string word1 = "intention", word2 = "execution";
    minDistance(word1, word2);
}