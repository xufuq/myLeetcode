#include <vector>
#include <deque>

using namespace std;

// 时间复杂度过大
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int maxIndex = -1;
    vector<int> result;
    for(int i=0; i<nums.size()-k+1; ++i) {
        if(maxIndex<i) { // 
            maxIndex = i;
            for(int j=i;j<i+k;++j){
                if(nums[j]>nums[maxIndex])
                    maxIndex =j;
            }
        }
        else if(nums[i+k-1]>=nums[maxIndex])
            maxIndex =i+k-1;
        result.push_back(nums[maxIndex]);
    }
    return result;
}

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<pair<int,int>> InOrder;  // first值，second是index
    vector<int> result;
    // 先对双端队列初始化
    for(int i=0;i<k;++i){
        if(InOrder.empty())
            InOrder.push_back(pair<int,int>(nums[i],i));
        else if(InOrder.front().first > nums[i]){
            while(InOrder.back().first<=nums[i])
                InOrder.pop_back();
            InOrder.push_back(pair<int,int>(nums[i],i));
        }
        else{
            InOrder.clear();
            InOrder.push_back(pair<int,int>(nums[i],i));
        }
    }
    result.push_back(InOrder.front().first);
    // 利用双端队列求最大值
    for(int i=1;i<=nums.size()-k;++i){
        if(InOrder.front().second==i-1)
            InOrder.pop_front();
        if(InOrder.front().first>nums[i+k-1]){
            while(InOrder.back().first<=nums[i+k-1])
                InOrder.pop_back();
            InOrder.push_back(pair<int,int>(nums[i+k-1],i+k-1));
        }
        else{
            InOrder.clear();
            InOrder.push_back(pair<int,int>(nums[i+k-1],i+k-1));
        }
        result.push_back(InOrder.front().first);
    }
    return result;
}

// 优化，只保存坐标，不保存具体值
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> InOrder;  // first值，second是index
    vector<int> result;
    // 先对双端队列初始化
    for(int i=0;i<k;++i){
        if(InOrder.empty())
            InOrder.push_back(i);
        else if(nums[InOrder.front()] > nums[i]){
            while(nums[InOrder.back()]<=nums[i])
                InOrder.pop_back();
            InOrder.push_back(i);
        }
        else{
            InOrder.clear();
            InOrder.push_back(i);
        }
    }
    result.push_back(nums[InOrder.front()]);
    // 利用双端队列求最大值
    for(int i=1;i<=nums.size()-k;++i){
        if(InOrder.front()==i-1)
            InOrder.pop_front();
        if(nums[InOrder.front()]>nums[i+k-1]){
            while(nums[InOrder.back()]<=nums[i+k-1])
                InOrder.pop_back();
            InOrder.push_back(i+k-1);
        }
        else{
            InOrder.clear();
            InOrder.push_back(i+k-1);
        }
        result.push_back(nums[InOrder.front()]);
    }
    return result;
}
