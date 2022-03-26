#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 计算曼哈顿距离
bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
    // 看有没有阻碍点比起点更接近终点
    int pathLength = abs(target[0]) + abs(target[1]);
    for(auto &vec : ghosts) {
        if(abs(vec[0]-target[0]) + abs(vec[1]-target[1])  < pathLength)
            return false;
    }
    return true;
}