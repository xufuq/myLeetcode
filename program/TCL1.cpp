#include <vector>
#include <iostream>
using namespace std;

// 没做出来
int ArrayDistance(vector<int>& a, int m, int k){
    int result=1;
    int len=a.size();
    vector<vector<int>> count(len, vector<int>(len, 0));
    for(int i=0;i<len;++i){
        if(a[i]-k>=1)
            count[i][0]=k;
        else
            count[i][0]=a[i]-1;
        if(a[i]+k<=m)
            count[i][1]=k;
        else
            count[i][1]=m-a[i];
    }
    // 对可行数组进行处理
    vector<vector<int>> dp(len, vector<int>(k+1, 0));
    for(int i=0;i<len;++i)
        dp[i][0]=1;
    for(int i=1;i<=k;++i){
        if(count[0][0]>=i)
            dp[0][i]++;
        if(count[0][1]>=i)
            dp[0][i]++;
    }

    for(int i=1;i<len;++i){
        for(int j=1;j<=k;++j){
            dp[i][j]=dp[i-1][j];
            for(int x=1;x<=j;++x){
                if(count[i][0]>=x)
                    dp[i][j]+=dp[i-1][j-x];
            }

        }
    }

    return dp[len-1][k];
}