#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 计算每个字符串有多少个0/1
vector<int> getCount01(string &str){
    vector<int> result(2, 0);
    for(auto c : str){
        if(c == '0')
            ++result[0];
        else
            ++result[1];
    }
    return result;
}

// 这个必须是二维数组，因为有两个维度的条件约束
// 二维数组更新时只对能放下的数组元素进行更新
int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    for(auto &str : strs){
        vector<int> count01 = getCount01(str);
        for(int i=m;i>=count01[0];--i){ // 对m进行计数
            for(int j=n;j>=count01[1];--j){
                dp[i][j] = max(dp[i][j], dp[i-count01[0]][j-count01[1]]+1);
            }
        }
    }
    return dp[m][n];
}