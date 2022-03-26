#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <queue>
using namespace std;


int getMaxPath(vector<vector<int>>& matrix, vector<vector<int>>& visited, int x, int y) {
    if(visited[x][y]==-1) {
        visited[x][y]=1;
        if(x>0 && matrix[x-1][y]>matrix[x][y])                  visited[x][y]=max(visited[x][y], getMaxPath(matrix,visited,x-1,y)+1);
        if(x<matrix.size()-1 && matrix[x+1][y]>matrix[x][y])    visited[x][y]=max(visited[x][y], getMaxPath(matrix,visited,x+1,y)+1);
        if(y>0 && matrix[x][y-1]>matrix[x][y])                  visited[x][y]=max(visited[x][y], getMaxPath(matrix,visited,x,y-1)+1);
        if(y<matrix[0].size()-1 && matrix[x][y+1]>matrix[x][y]) visited[x][y]=max(visited[x][y], getMaxPath(matrix,visited,x,y+1)+1);
    }
    return visited[x][y];
}

int longestIncreasingPath(vector<vector<int>>& matrix) {
    vector<vector<int>> visited(matrix.size(), vector<int>(matrix[0].size(), -1));
    int maxLength =0;
    for(int i=0; i<matrix.size();++i) {
        for(int j=0; j<matrix[0].size();++j) {
            if(visited[i][j]==-1) 
                visited[i][j] = getMaxPath(matrix, visited, i, j);
            maxLength=max(maxLength, visited[i][j]);
        }
    }
    return maxLength;
}