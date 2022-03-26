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

// 以每个点作为基点，所以不存在重复的情况
// 考虑的是欧氏距离

int countBoom(int a, int b, int c, vector<vector<int>> &line, vector<vector<int>>& points) {
    int count = 0;
    if(line[a][b]==0) 
        line[a][b]=pow(points[a][0]-points[b][0], 2)+pow(points[a][1]-points[b][1], 2);
    if(line[a][c]==0)
        line[a][c]=pow(points[a][0]-points[c][0], 2)+pow(points[a][1]-points[c][1], 2);
    if(line[b][c]==0)
        line[b][c]=pow(points[b][0]-points[c][0], 2)+pow(points[b][1]-points[c][1], 2);
    if(line[a][b]==line[a][c]) count+=2;
    if(line[a][b]==line[b][c]) count+=2;
    if(line[a][c]==line[b][c]) count+=2;
    return count;
}

int numberOfBoomerangs(vector<vector<int>>& points) {
    int result=0;
    int n=points.size();
    vector<vector<int>> line(n, vector<int>(n));
    for(int i = 0; i < n;++i) {
        for(int j = i+1; j < n;++j) {
            for(int k = j+1; k < n;++k) {
                result+=countBoom(i, j, k, line, points);
            }
        }
    }
    return result;
}

// 官方题解，计算所有两个点之间的距离
// 用哈希表记录距离的计数
// 针对每个点进行上述过程
int numberOfBoomerangs(vector<vector<int>>& points) {
    int result=0;
    for(auto &p : points) {
        unordered_map<int, int> count;
        for(auto &q : points) {
            int dist=(p[0]-q[0])*(p[0]-q[0])+(p[1]-q[1])*(p[1]-q[1]);
            ++count[dist];
        }
        for(auto &m : count)
            result+=m.second*(m.second-1);
    }
    return result;
}