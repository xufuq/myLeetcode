#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <stack>
using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n=matrix.size(), startRow=0;
    int curColIndex = 0, curRowIndex=startRow;
    vector<int> rowIndex(n); // 都是从0开始
    while(startRow!=n) {
        curRowIndex=startRow;
        for(int row=startRow+1;row<n;++row) 
            if(matrix[row][rowIndex[row]] < matrix[curRowIndex][rowIndex[curRowIndex]]) 
                curRowIndex=row;

        if(k==1) return matrix[curRowIndex][rowIndex[curRowIndex]];
        else {
            --k;
            rowIndex[curRowIndex]++;
            if(rowIndex[curRowIndex]==n) ++startRow;
        }
    }
    return 0;
}
// 可以对每一行用二分法，左上角的都是小于当前取值的
// 或者对二维数组归并排序(每次合并2倍)