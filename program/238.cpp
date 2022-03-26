#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;


// O(n)时间复杂度，进阶要求是常数空间复杂度
vector<int> productExceptSelf(vector<int>& nums) {
    vector<int> result(nums.size(), 1);
    for(int i=0;i<nums.size();++i){
        for(int j=0;j<i;++j){
            result[j]*=nums[i];
        }
        for(int j=i+1;j<nums.size();++j){
            result[j]*=nums[i];
        }
    }
    return result;
}

// 官方n空间复杂度
vector<int> productExceptSelf(vector<int>& nums) {
    int n=nums.size();
    vector<int> L(n, 1), R(n, 1), result(n); // 包含区间是左闭右开
    for(int i=1;i<n;++i) 
        L[i]=L[i-1]*nums[i-1];
    for(int i=n-2;i>=0;--i)
        R[i]=nums[i+1]*R[i+1];
    for(int i=1;i<n-2;++i)
        result[i]=L[i-1]*R[i+1];
    result[0]=R[1];
    result[n-1]=L[n-2];
    return result;
}