#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <stack>
#include <unordered_set>
#include <set>
using namespace std;

vector<int> findDisappearedNumbers(vector<int>& nums) {
    set<int> exist(nums.begin(), nums.end());
    vector<int> result;
    for(int i=1;i<=nums.size();i++) {
        if(exist.count(i)==0) result.push_back(i);
    }
    return result;
}

// 鸽笼原理
// 如果为负则代表出现过
// 大神的解法
vector<int> findDisappearedNumbers(vector<int>& nums) {
    for(auto &n : nums)
        nums[abs(n)-1]=-abs(nums[abs(n)-1]);
    vector<int> result;
    for(int i=0;i<nums.size();++i)
        if(nums[i]>0) result.push_back(i+1);
    return result;
}