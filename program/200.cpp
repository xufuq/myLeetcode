#include <vector>
#include <queue>
#include <map>
using namespace std;


// 只有当当前位置为1，用队列向外扩张
// 空间复杂度过高，报错了
void isValid(vector<vector<char>>& grid, int row, int col) {
    if(row>0 && grid[row-1][col] == '1'){
        grid[row-1][col] = '2';
        isValid(grid, row-1, col);
    }
    if(col>0 && grid[row][col-1] == '1'){
        grid[row][col-1] = '2';
        isValid(grid, row, col-1);
    }
    if(row<grid.size()-1 && grid[row+1][col] == '1'){
        grid[row+1][col] = '2';
        isValid(grid, row+1, col);
    }
    if(col<grid[0].size()-1 && grid[row][col+1] == '1'){
        grid[row][col+1] = '2';
        isValid(grid, row, col+1);
    }
}

int numIslands(vector<vector<char>>& grid) {
    int rows = grid.size(), cols = grid[0].size(), count=0;
    for(int row = 0; row < rows; ++row){
        for(int col = 0; col < cols; ++col){
            if(grid[row][col]=='1'){
                grid[row][col] = '2';
                isValid(grid, row, col);
                ++count;
            }
        }
    }
    return count;
}