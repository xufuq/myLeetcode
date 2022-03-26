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

// 找到第一个陆地，然后记录去过的陆地
int islandPerimeter(vector<vector<int>>& grid) {
    unordered_set<int> visited;
    queue<vector<int>> pos;
    int res = 0, row=grid.size(), col=grid[0].size();
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(grid[i][j]) {
                visited.insert(100*i+j);
                pos.push({i, j});
                while(!pos.empty()) {
                    int x=pos.front()[0], y=pos.front()[1];
                    pos.pop();
                    if(x-1>=0) {
                        if(grid[x-1][y]==1 && visited.count(100*(x-1)+y)==0) { // 还没访问过
                            pos.push({x-1, y});
                            visited.insert(100*(x-1)+y);
                        } else if(grid[x-1][y]==0)
                            ++res;
                    }
                    else
                        ++res;
                    if(x+1<row) {
                        if(grid[x+1][y]==1 && visited.count(100*(x+1)+y)==0) { // 还没访问过
                            pos.push({x+1, y});
                            visited.insert(100*(x+1)+y);
                        } else if(grid[x+1][y]==0)
                            ++res;
                    }
                    else
                        ++res;
                    if(y-1>=0) {
                        if(grid[x][y-1]==1 && visited.count(100*x+y-1)==0) { // 还没访问过
                            pos.push({x, y-1});
                            visited.insert(100*x+y-1);
                        } else if(grid[x][y-1]==0)
                            ++res;
                    }
                    else
                        ++res;
                    if(y+1<col) {
                        if(grid[x][y+1]==1 && visited.count(100*x+y+1)==0) { // 还没访问过
                            pos.push({x, y+1});
                            visited.insert(100*x+y+1);
                        } else if(grid[x][y+1]==0)
                            ++res;
                    }
                    else
                        ++res;
                }
                return res;
            }
        }
    }
    return -1;
}