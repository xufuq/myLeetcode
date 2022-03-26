#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
#include <queue>
using namespace std;

// 看是否能够一路低走
// 从高处到达海洋
// 需要一个visited保存当前的状态，避免重复访问
// 单个位置的元素返回值需要位运算, 1代表太平洋，2代表大西洋，3表示都能到
int pacificAtlantic(vector<vector<int>>& heights, vector<vector<int>>& visited, int x, int y) {
    if(visited[x][y]>=0) return visited[x][y];
    int result=0, temp=visited[x][y];
    visited[x][y]=-1;
    if(x==0 || y==0) result|=1;
    if(x==heights.size()-1 || y==heights[0].size()-1) result|=2;
    
    if(x-1>=0 && heights[x-1][y]<=heights[x][y] && visited[x-1][y]!=-1 && result!=3)
        result|=pacificAtlantic(heights, visited, x-1, y);
    if(x+1<heights.size() && heights[x+1][y]<=heights[x][y] && visited[x+1][y]!=-1 && result!=3)
        result|=pacificAtlantic(heights, visited, x+1, y);
    if(y-1>=0 && heights[x][y-1]<=heights[x][y] && visited[x][y-1]!=-1 && result!=3)
        result|=pacificAtlantic(heights, visited, x, y-1);
    if(y+1<heights[0].size() && heights[x][y+1]<=heights[x][y] && visited[x][y+1]!=-1 && result!=3)
        result|=pacificAtlantic(heights, visited, x, y+1);
    visited[x][y]=temp;
    return result;
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int rows=heights.size(), cols=heights[0].size();
    vector<vector<int>> visited(rows, vector<int>(cols, INT_MIN));
    vector<vector<int>> result;
    for(int i=0; i<rows; ++i) {
        for(int j=0;j<cols; ++j) {
            if(pacificAtlantic(heights, visited, i, j)==3)
                result.push_back({i, j});
        }
    }
    return result;
}