#include <vector>
#include <iostream>
#include <map>
#include <algorithm>
#include <math.h>
#include <numeric>

using namespace std;
// 这里竟然可以对A排序
// 看题目好像不可以啊
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        multimap<int, int> minus;
        int absMin = INT32_MAX, minIndex = 0;
        for(int i = 0; i < nums.size();++i) {
            if(absMin > abs(nums[i])) {
                absMin = abs(nums[i]);
                minIndex = i;
            }
            if(nums[i]<0)
                minus.insert(pair<int, int>(nums[i], i));
        }

        for(auto m : minus) {
            if(k--)
                nums[m.second] *= -1;
            else
                break;
        }
        
        if(k>0 && k%2)
            nums[minIndex] = -nums[minIndex];
        return accumulate(nums.begin(), nums.end(), 0);
    }