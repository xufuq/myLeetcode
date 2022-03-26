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

// 时间复杂度过高
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        begin=matrix.begin();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++) 
            sum=accumulate((begin+row1)->begin()+col1, (begin+row1)->begin()+col2+1, sum);
        return sum;
    }
private:
    vector<vector<int>>::iterator begin;
};

// 还可以做二维和
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();++i) {
            for(int j=1;j<matrix[0].size();++j)
                matrix[i][j]+=matrix[i][j-1];
        }
        begin=matrix.begin();
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i=row1;i<=row2;i++) {
            sum+=*((begin+i)->begin()+col2);
            if(col1>0) sum-=*((begin+i)->begin()+col1-1);
        }
            
        return sum;
    }
private:
    vector<vector<int>>::iterator begin;
};
