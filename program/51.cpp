#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_set>
#include <map>

using namespace std;

vector<vector<string>> result;

bool ifAvailable(int i, int j, vector<int> &isUsed){
    int dety;
    for(int row=0;row<isUsed.size(); ++row){
        dety = abs(isUsed[row]-j);
        if(dety==0 || abs(row-i)==dety)
            return false;
    }
    return true;
}

void solveNQueens(int n, vector<int> &isUsed, int iStart) {
    if(iStart==n) { // 放满了
        vector<string> path;
        for(auto num : isUsed){
            string str(n, '.');
            str[num]='Q';
            path.push_back(str);
        }
        result.push_back(path);
        return;
    }
    // 原来这里多了一重没有用的循环
    for(int j=0; j<n; ++j) { // j代表列
        if(ifAvailable(iStart,j,isUsed)){
            isUsed.push_back(j);
            solveNQueens(n, isUsed, iStart+1);
            isUsed.pop_back();
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<int> isUsed; // 第一行代表行占用，第二行代表列占用
    solveNQueens(n, isUsed, 0);
    return result;
}