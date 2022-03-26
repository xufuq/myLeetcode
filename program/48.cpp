#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int len = matrix.size();
    for(int i=0;i<len/2;++i) { // i代表外面的圈数
        for(int j=i;j<len-i;++j) {
            int temp=matrix[len-j-1][i];
            matrix[len-j-1][i]=matrix[len-i-1][len-j-1]; //
            matrix[len-i-1][len-j-1]=matrix[j][len-i-1];
            matrix[j][len-i-1]=matrix[i][j];
            matrix[i][j]=temp;
        }
    }
}