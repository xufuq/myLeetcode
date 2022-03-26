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
#include <queue>
using namespace std;

// 结果相邻连续正数，不能重复
bool isPossible(vector<int>& nums) {
    vector<int> nCount(nums.back()-nums[0]+1);
    int start=nums[0];
    for(auto &n:nums) {
        n-=start;
        ++nCount[n];
    }
    nCount.push_back(0); //添加一个0作为边界，便于处理
    int count=0, sIndex=0, eIndex=1;
    while(sIndex<nCount.size()) {
        while(nCount[eIndex]>=nCount[eIndex-1]) {
            ++eIndex;
        }
        if(eIndex-sIndex>2) { // 可以形成有效的子序列
            count=min(nCount[sIndex], nCount[eIndex-1]-nCount[eIndex]);
            for(int i=sIndex;i<eIndex;++i)
                nCount[i]-=count;
        }
        else
            return false;
        while(sIndex<nCount.size() && nCount[sIndex]==0) ++sIndex;
        eIndex=sIndex+1;
    }
    return true;
}