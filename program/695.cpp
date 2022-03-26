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

int maxAreaOfIsland(vector<vector<int>>& grid) {
    int rows=grid.size(), cols=grid[0].size();
    int result=0, curCount=0;
    for(int i=0;i<rows;++i) {
        for(int j=0;j<cols;++j) {
            if(grid[i][j]==1) {
                grid[i][j]=0;
                queue<vector<int>> pos;
                pos.push({i,j});
                while(!pos.empty()) {
                    ++curCount;
                    int x=pos.front()[0], y=pos.front()[1];
                    pos.pop();
                    if(x-1>=0 && grid[x-1][y]) {
                        pos.push({x-1, y});
                        grid[x-1][y]=0;
                    }
                    if(y+1<cols && grid[x][y+1]) {
                        pos.push({x, y+1});
                        grid[x][y+1]=0;
                    }
                    if(x+1<rows && grid[x+1][y]) {
                        pos.push({x+1, y});
                        grid[x+1][y]=0;
                    }
                    if(y-1>=0 && grid[x][y-1]) {
                        pos.push({x, y-1});
                        grid[x][y-1]=0;
                    }
                }
                result=max(result, curCount);
                curCount=0;
            }
        }
    }
    return result;
}