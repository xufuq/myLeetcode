int minDistance(string word1, string word2) {
    int len1 = word1.length(), len2 = word2.length();
    // dp就是寻找两个字符串的最大重复数
    // dp[i][j]就是word1[0-i],word2[0-j]重复的最大字符数
    vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; ++j){
            if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
        }
    }
    return len1+len2-2*dp[len1][len2];
}