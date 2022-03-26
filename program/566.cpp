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

vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
    int rows=mat.size(), cols=mat[0].size();
    int count=0;
    if(rows*cols!=r*c) return mat;
    vector<vector<int>> result(r, vector<int>(c));
    for(int i=0;i<r;++i) {
        for(int j=0;j<c;++j) {
            result[i][j]=mat[count/rows][count%cols];
            ++count;
        }
    }
    return result;
}