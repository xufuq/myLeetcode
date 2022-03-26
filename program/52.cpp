#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <numeric>
#include <string>
#include <sstream>
#include "math.h"
using namespace std;

bool isSuitable(int n, int rowIndex, int colIndex, vector<vector<bool>> &queens) {
    for(int i = 0; i < rowIndex; i++) 
        if(queens[i][colIndex]) return false;
    for(int i=rowIndex, j = colIndex; i>=0 && j>=0; i--, j--) 
        if(queens[i][j]) return false;
    for(int i=rowIndex, j = colIndex; i<n && j<n; ++i, ++j)  
        if(queens[i][j]) return false;
    for(int i=rowIndex, j = colIndex; i<n && j>=0; ++i, --j)  
        if(queens[i][j]) return false;
    for(int i=rowIndex, j = colIndex; i>=0 && j<n; --i, ++j)  
        if(queens[i][j]) return false;
    return true;
}

int totalNQueens(int n, int rowIndex, vector<vector<bool>> &queens) {
    if(rowIndex==n) return 1;
    int result=0;
    for(int i=0;i<n;++i) {
        if(isSuitable(n, rowIndex, i, queens)) {
            queens[rowIndex][i]=true;
            result+=totalNQueens(n, rowIndex+1, queens);
            queens[rowIndex][i]=false;
        }
    }
    return result;
}

int totalNQueens(int n) {
    vector<vector<bool>> queens(n, vector<bool>(n, false));
    return totalNQueens(n, 0, queens);
}