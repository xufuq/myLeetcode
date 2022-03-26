#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <unordered_map>
#include <iostream>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <string>
#include "math.h"
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int top=0, bottom=matrix.size(), left=0, right=matrix[0].size();
    int total=bottom*right, count=0, x=0, y=0, dIndex=0; // x row y col
    vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<int> result(total);
    while(count<total) {
        if(x>=top && x<bottom && y>=left && y<right) { // 在可寻址范围内
            result[count]=matrix[x][y];
            ++count;
        }
        if(x+directions[dIndex][0]>=top && x+directions[dIndex][0]<bottom && y+directions[dIndex][1]>=left && y+directions[dIndex][1]<right)
            x+=directions[dIndex][0], y+=directions[dIndex][1];
        else {
            if(dIndex==0) ++top;
            else if(dIndex==1) --right;
            else if(dIndex==2) --bottom;
            else ++left;
            dIndex=(dIndex+1)%4;
            x+=directions[dIndex][0], y+=directions[dIndex][1];
        }
    }
    return result;
}