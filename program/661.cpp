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
#include <numeric>
using namespace std;

vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
    int row = img.size(), col = img[0].size();
    vector<vector<int>> result(img);
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            int count=1, sum=img[i][j];
            if(i-1>0 && j-1>0)     sum+=img[i-1][j-1], ++count;
            if(j-1>0)              sum+=img[i][j-1], ++count;
            if(i-1>0)              sum+=img[i-1][j], ++count;
            if(i+1<row)            sum+=img[i+1][j], ++count;
            if(j+1<col)            sum+=img[i][j+1], ++count;
            if(i+1<row && j+1<col) sum+=img[i+1][j+1], ++count;
            if(i+1<row && j-1>0)   sum+=img[i+1][j-1], ++count;
            if(i-1>0 && j+1<col)   sum+=img[i-1][j+1], ++count;
            result[i][j]=sum/count;
        }
    }
    return result;
}