#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <string>
#include <sstream>

using namespace std;

int getMaxLen(vector<int>& nums) {
    int spIndex=-1, s0Index=-1;
    vector<int> snIndex(2, -1);
    int ans = 0, cur=1; // cur表示当前的结果是正还是负。
    for(int i=0; i<nums.size(); i++) {
        if(nums[i]==0) {
            if(cur>0) // 当前结果为正值
                ans=max(i-s0Index, ans);
            else { // 为负值
                if(snIndex[1]!=-1)
                    ans=max(ans, max(i-snIndex[1]-1, snIndex[1]-s0Index-1));
                if(snIndex[0]!=-1)
                    ans=max(ans, max(i-snIndex[0]-1, snIndex[0]-s0Index-1));
            }
            spIndex = -1, snIndex[0] = -1, snIndex[1] = -1, s0Index=i, cur=1;
        }
        else { // 不为0
            if(nums[i]>0 && spIndex==-1)
                spIndex=i;
            else if(nums[i]<0) {
                if(snIndex[0]==-1)
                    snIndex[0]=i;
                else
                    snIndex[1]=i;
                cur=-cur;
            }
        }
    }
    int n=nums.size();
    if(cur>0) // 当前结果为正值
        ans=max(n-s0Index, ans);
    else { // 为负值
        if(snIndex[1]!=-1)
            ans=max(ans, max(n-snIndex[1]-1, snIndex[1]-s0Index-1));
        if(snIndex[0]!=-1)
            ans=max(ans, max(n-snIndex[0]-1, snIndex[0]-s0Index-1));
    }
    return ans;
}