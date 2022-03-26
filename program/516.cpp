#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// 递归时间复杂度太高，无法完成
int longestPalindromeSubseq(string s, int startIndex, int endIndex) {
    if(startIndex==endIndex) return 1;
    else if(startIndex>endIndex) return 0;
    int index=endIndex;
    while(index>startIndex && s[startIndex]!=s[index])
        --index;
    if(index==startIndex) // 没有找到相等的
        return max(1, longestPalindromeSubseq(s, startIndex+1, endIndex));
    else    
        return max(longestPalindromeSubseq(s, startIndex+1, index-1)+2,longestPalindromeSubseq(s, startIndex+1, endIndex));
}

int longestPalindromeSubseq(string s) {
    return longestPalindromeSubseq(s, 0, s.size()-1);
}

// 用数组的方式完成
int longestPalindromeSubseq2(string s) {
    int n=s.size();
    vector<vector<int>> dp(n, vector<int>(n,1));
    for(int i=n-1;i>=0;--i){
        for(int j=i;j<n;++j){
            if(j==i+1){
                if(s[i]==s[j])
                    dp[i][j]=2;
            }
            else if(j>i){
                if(s[i]==s[j])
                    dp[i][j]=dp[i+1][j-1]+2;
                else
                    dp[i][j]=max(dp[i][j-1], dp[i+1][j]);
            }
        }
    }
    return dp[0][n-1];
}

int main(){
    string s = "euazbipzncptldueeuechubrcourfpftcebikrxhybkymimgvldiwqvkszfycvqyvtiwfckexmowcxztkfyzqovbtmzpxojfofbvwnncajvrvdbvjhcrameamcfmcoxryjukhpljwszknhiypvyskmsujkuggpztltpgoczafmfelahqwjbhxtjmebnymdyxoeodqmvkxittxjnlltmoobsgzdfhismogqfpfhvqnxeuosjqqalvwhsidgiavcatjjgeztrjuoixxxoznklcxolgpuktirmduxdywwlbikaqkqajzbsjvdgjcnbtfksqhquiwnwflkldgdrqrnwmshdpykicozfowmumzeuznolmgjlltypyufpzjpuvucmesnnrwppheizkapovoloneaxpfinaontwtdqsdvzmqlgkdxlbeguackbdkftzbnynmcejtwudocemcfnuzbttcoew";
    cout << longestPalindromeSubseq2(s) << endl;
}