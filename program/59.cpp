#include <vector>
#include <iostream>

using namespace std;

vector<vector<int>> generateMatrix(int n) {
    int num = n*n;
    int x=0, y=0, direction = 0;
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 1; i <= num; i++)
    {
        matrix[x][y] = i;
        if (direction==0)
        {
            if (y+1<n && matrix[x][y+1]==0)
                ++y;
            else
                direction = 1;
        }
        if (direction==1)
        {
            if (x+1<n && matrix[x+1][y]==0)
                ++x;
            else
                direction = 2;
        }
        if (direction==2)
        {
            if (y-1>=0 && matrix[x][y-1]==0)
                --y;
            else
                direction = 3;
        }
        if (direction==3)
        {
            if (x-1>=0 && matrix[x-1][y]==0)
                --x;
            else{
                direction = 0;
                if (y+1<n && matrix[x][y+1]==0)
                    ++y;
                else
                    break;
            }
        }
    }
    return matrix;
}

