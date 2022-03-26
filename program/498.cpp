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
#include "math.h"
using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int rows=mat.size(), cols=mat[0].size(), num=rows*cols, count=0;
    vector<int> result(num);
    int startX=0, startY=0;
    while(count<num) {
        for(; startX>=0 && startY<cols;--startX, ++startY) {
            result[count]=mat[startX][startY];
            ++count;
        }
        if(startY==cols) {
            --startY;
            startX+=2;
        } else            
            ++startX;
        for(;startX<rows && startY>=0;++startX, --startY) {
            result[count]=mat[startX][startY];
            ++count;
        }
        if(startX==rows){
            --startX;
            startY+=2;
        } else            
            ++startY;
    }
    return result;
}