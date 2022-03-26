#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// 一个表示符记录第0行是否有原生的0
// 一个标识符记录当前行是否有原生的0
// 如果当前行的列有0， 则把第一行对应的位置置为-
void setZeroes(vector<vector<int>>& matrix) {
    bool fisrtRow = false, curRow=false;
    int rows=matrix.size(), cols=matrix[0].size();
    for(int i=0;i<cols;++i){
        if(matrix[0][i]==0){
            fisrtRow=true;
            break;
        }
    }
    for(int i=1;i<rows;++i){
        for(int j=0;j<cols;++j){
            if(matrix[i][j]==0) {
                matrix[0][j]=0;
                curRow=true;
            }
        }
        if(curRow){
            for(int j=0;j<cols;++j)
                matrix[i][j]=0;
            curRow=false;
        }
    }
    for(int j=0;j<cols;++j){
        if(matrix[0][j]==0)
            for(int i=0;i<rows;++i)
                matrix[i][j]=0;
    }
    if(fisrtRow){
        for(int i=0;i<cols;++i)
                matrix[0][i]=0;
    }
}