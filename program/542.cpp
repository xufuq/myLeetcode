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

int updateMatrix(vector<vector<int>>& mat, vector<vector<int>>& result, int curRow, int curCol) {
    if(mat[curRow][curCol]==0) return 0;
    if(result[curRow][curCol]!=-1 && result[curRow][curCol]!=INT_MAX) return result[curRow][curCol];
    result[curRow][curCol]=INT_MAX;
    int curDist=INT_MAX;
    if(curRow-1>=0) {
        if(result[curRow-1][curCol]!=INT_MAX) { // 这个还没有访问过
            if(result[curRow-1][curCol]!=-1)
                curDist=min(result[curRow-1][curCol], curDist);
            else
                curDist=min(updateMatrix(mat, result, curRow-1, curCol), curDist);
        } 
    }
    if(curRow+1<mat.size()) {
        if(result[curRow+1][curCol]!=INT_MAX) { // 这个还没有访问过
            if(result[curRow+1][curCol]!=-1)
                curDist=min(result[curRow+1][curCol], curDist);
            else
                curDist=min(updateMatrix(mat, result, curRow+1, curCol), curDist);
        } 
    }
    if(curCol-1>=0) {
        if(result[curRow][curCol-1]!=INT_MAX) { // 这个还没有访问过
            if(result[curRow][curCol-1]!=-1)
                curDist=min(result[curRow][curCol-1], curDist);
            else
                curDist=min(updateMatrix(mat, result, curRow, curCol-1), curDist);
        } 
    }
    if(curCol+1<mat.size()) {
        if(result[curRow][curCol+1]!=INT_MAX) { // 这个还没有访问过
            if(result[curRow][curCol+1]!=-1)
                curDist=min(result[curRow][curCol+1], curDist);
            else
                curDist=min(updateMatrix(mat, result, curRow, curCol+1), curDist);
        } 
    }
    result[curRow][curCol]=-1;
    return curDist+1;
}


vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int rows = mat.size(), cols=mat[0].size();
    vector<vector<int>> result(rows, vector<int>(cols, -1));
    for(int i=0;i<rows;i++) {
        for(int j=0;j<cols;j++) {
            updateMatrix(mat, result, i, j);
        }
    }
    return result;
}