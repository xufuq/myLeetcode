#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <iostream>
using namespace std;

// 这道题是希望能够手动实现小根堆，然后尽量少使用额外空间
int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() - k];
}

// int findKthLargest(vector<int>& nums, int k) {
//     priority_queue<int> myQue;
//     multiset<int> iset;
//     for(auto n : nums) {
//         if(iset.size()<k)
//             iset.insert(n);
//         else {
//             if(n > *iset.begin()){
//                 iset.erase(iset.begin());
//                 iset.insert(n);
//             }
//         }
//         cout << "size of " << iset.size() << " n: " << n << endl;
//     }
//     cout << "size of " << iset.size() << endl;
//     return *iset.begin();
// }

int main() {
    vector<int> nums={3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6};
    cout << findKthLargest(nums, 20) << endl;
    sort(nums.begin(), nums.end());
    for(auto n : nums) {
        cout << n << " ";
    }

}