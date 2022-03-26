#include <vector>
using namespace std;

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m=obstacleGrid.size(), n=obstacleGrid[0].size();
    if(obstacleGrid[m-1][n-1]==1) return 0;
    else obstacleGrid[m-1][n-1]=1;
    for(int i=m-2;i>=0;--i) {
        if(obstacleGrid[i][n-1]==1 || obstacleGrid[i+1][n-1]==0)
            obstacleGrid[i][n-1]=0;
        else
            obstacleGrid[i][n-1]=1;
    }
    for(int i=n-2;i>=0;--i){
        if(obstacleGrid[m-1][i]==1 || obstacleGrid[m-1][i+1]==0)
            obstacleGrid[m-1][i]=0;
        else
            obstacleGrid[m-1][i]=1;
    }

    for(int i=m-2;i>=0;--i) {
        for(int j=n-2;j>=0;--j){
            if(obstacleGrid[i][j]==1)
                obstacleGrid[i][j]=0;
            else
                obstacleGrid[i][j]=obstacleGrid[i][j+1]+obstacleGrid[i+1][j];
        }
    }
    return obstacleGrid[0][0];
}