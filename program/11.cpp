#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 从两边向中间收缩
// 越到中间需要的柱子越高
int maxArea(vector<int>& height) {
    int currentMinHeight=0, result=0;
    for(int i=0, j=height.size()-1; i<j;){
        currentMinHeight = min(height[i], height[j]);
        result = max(result, currentMinHeight*(j-1));
        if(height[i]<=currentMinHeight)
            ++i;
        if(height[j]<=currentMinHeight)
            --i;
    }
    return result;
}