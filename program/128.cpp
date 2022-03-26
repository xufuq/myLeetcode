#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <unordered_set>
using namespace std;

// 不能排序，否则时间复杂度超出要求
// 时间复杂度超了
int longestConsecutive(vector<int>& nums) {
    map<int, vector<int>> nMap;
    for(auto n : nums) {
        auto it = nMap.begin();
        for(;it!=nMap.end();it++) {
            if(it->second[0]-1==n){
                it->second[0]--;
                break;
            }                
            else if(it->second[1]+1==n){
                it->second[1]++;
                break;
            }                
            else if(n<=it->second[1] && n>=it->second[0]){
                break;
            }
        }
        if(it==nMap.end()) 
            nMap[n]=vector<int>(2,n);
    }
    int start=INT32_MIN, end=INT32_MIN, maxLen=0;
    for(auto n : nMap) {
        if(end<n.second[0]-1){
            start=n.second[0];
            end=n.second[1];
        }
        else { // 连在一起了
            start=min(start, n.second[0]);
            end=max(end, n.second[1]);
        }
        maxLen=max(maxLen, end-start+1);
    }
    return maxLen;
}


// 标准答案用哈希表记录，然后逐个元素寻找
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> nset;
    for(auto n : nums)
        nset.insert(n);
    
    int maxLen=1, curNum=1;
    for(auto n : nset){
        if(!nset.count(n-1)){
            curNum=n;
            while(nset.count(curNum+1))
                ++curNum;
            maxLen=max(maxLen,curNum-n+1);
        }
    }
    return maxLen;
}